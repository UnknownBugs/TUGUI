#ifndef __LINE__HPP__TUGUI
#define __LINE__HPP__TUGUI


#include <utils.hpp>
#include <formula.hpp>

#include <core/graphics/impl/2D/Point.hpp>

namespace TUGUI {

class Line : public PaintInterface {
public:

    Line(const Point &begin, const Point &end) : __mBegin { begin }, __mEnd { end }  {
       
    }

    void paint(PaintEngine &pe) const {
        if (__mBegin[0] == __mEnd[0]) drawYLine(__mBegin[0], __mBegin[1], __mEnd[1], pe);
        if (__mBegin[1] == __mEnd[1]) drawXLine(__mBegin[1], __mBegin[0], __mEnd[0], pe);

        __mLinearEquation.set(__mBegin[0], __mBegin[1], __mEnd[0], __mEnd[1]);

        double sX { __mBegin[0] * 1. }, dX { __mEnd[0] * 1. };
        double deltaX { 1 };

        if (sX > dX) MUTILS::swap(sX, dX);

        auto cGrad = MUTILS::max(dX - sX, MUTILS::abs(__mBegin[1] - __mEnd[1]));

        pe.setColorGradient(cGrad);

        if (__mLinearEquation.getSlope() > 1 || __mLinearEquation.getSlope() < -1) // deltaY = 1 or -1
            deltaX = 1. / MUTILS::abs(__mLinearEquation.getSlope());

        while (sX < dX) {
            pe.drawPixel(sX, __mLinearEquation.getY(sX));
            sX += deltaX;
        }
    }

private:
    Point __mBegin, __mEnd;
    static TMATH::FORMULA::LinearEquation __mLinearEquation;

    void drawXLine(unsigned int y, unsigned int x1, unsigned int x2, PaintEngine &pe) const {
        if (x1 > x2) MUTILS::swap(x1, x2);
        unsigned int end = MUTILS::min(x2, PaintEngine::PaintBase::getHorizontalResolution());
        pe.setColorGradient(end - x1);
        for (unsigned int i = 0; i < end - x1; i++) {
            pe.drawPixel(x1 + i, y);
        }
    }

    void drawYLine(const unsigned int x, unsigned int y1, unsigned int y2, PaintEngine &pe) const {
        if (y1 > y2) MUTILS::swap(y1, y2);
        unsigned int end = MUTILS::min(y2, PaintEngine::PaintBase::getVerticalResolution());
        pe.setColorGradient(end - y1);
        for (unsigned int i = 0; i < end - y1; i++) {
            pe.drawPixel(x, y1 + i);
        }
    }

}; // Line


}; // TUGUI

TMATH::FORMULA::LinearEquation TUGUI::Line::__mLinearEquation;

#endif //__POINT__HPP__TUGUI