#ifndef __LINE__HPP__TUGUI
#define __LINE__HPP__TUGUI


#include <utils.hpp>
#include <formula.hpp>

#include <core/graphics/impl/2D/Point.hpp>
#include <core/painter/impl/PaintBase.hpp>

namespace TUGUI {

class Line : public PaintInterface {
public:

    Line(const Point &begin, const Point &end) : __mBegin { begin }, __mEnd { end }  {
       
    }

    void paint(Color &color) const {
        if (__mBegin[0] == __mEnd[0]) drawYLine(__mBegin[0], __mBegin[1], __mEnd[1], color);
        if (__mBegin[1] == __mEnd[1]) drawXLine(__mBegin[1], __mBegin[0], __mEnd[0], color);

        __mLinearEquation.set(__mBegin[0], __mBegin[1], __mEnd[0], __mEnd[1]);

        double sX { __mBegin[0] * 1. }, dX { __mEnd[0] * 1. };
        double deltaX { 1 };

        if (sX > dX) MUTILS::swap(sX, dX);

        auto buffSize = MUTILS::max(dX - sX, MUTILS::abs(__mBegin[1] - __mEnd[1]));

        auto buff = color.getGradientRgbBuff(buffSize);

        if (__mLinearEquation.getSlope() > 1 || __mLinearEquation.getSlope() < -1) // deltaY = 1 or -1
            deltaX = 1. / MUTILS::abs(__mLinearEquation.getSlope());

        int i = 0;
        while (sX < dX && i < buffSize) {
            PaintBase::drawPixel(sX, __mLinearEquation.getY(sX), buff[i++]);
            sX += deltaX;
        }
    }

private:
    Point __mBegin, __mEnd;
    static TMATH::FORMULA::LinearEquation __mLinearEquation;

    void drawXLine(unsigned int y, unsigned int x1, unsigned int x2, Color &color) const {
        if (x1 > x2) MUTILS::swap(x1, x2);
        unsigned int end = MUTILS::min(x2, PaintBase::getHorizontalResolution());
        auto buff = color.getGradientRgbBuff(end - x1);
        for (unsigned int i = 0; i < end - x1; i++) {
            PaintBase::drawPixel(x1 + i, y, buff[i]);
        }
    }

    void drawYLine(const unsigned int x, unsigned int y1, unsigned int y2, Color &color) const {
        if (y1 > y2) MUTILS::swap(y1, y2);
        unsigned int end = MUTILS::min(y2, PaintBase::getVerticalResolution());
        auto buff = color.getGradientRgbBuff(end - y1);
        for (unsigned int i = 0; i < end - y1; i++) {
            PaintBase::drawPixel(x, y1 + i, buff[i]);
        }
    }

}; // Point


}; // TUGUI

TMATH::FORMULA::LinearEquation TUGUI::Line::__mLinearEquation;

#endif //__POINT__HPP__TUGUI