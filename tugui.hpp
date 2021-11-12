/**
 * Tiny UEFI Graphical User Interface
 * 
 * 
*/

#ifndef __TUGUI_HPP__
#define __TUGUI_HPP__

#include <src/wrapper/systemtable_wrapper.hpp>
#include <src/wrapper/gop_wrapper.hpp>
#include <src/utils/utils.hpp>

#include "libs/TMATH/formula.hpp"

#define PIXEL_WHITE {0xFF, 0xFF, 0xFF, 0}

namespace TUGUI {

using UEFIWrapper::GOP;
using Math::Formula::LinearEquation;

class Base {
private:
    using EGOP  = GOP::EGOP;

public:
    using Pixel = GOP::Pixel;
    
public:

    Base() = default;

    void drawPixel(unsigned int x, unsigned int y, Pixel p) {
        unsigned int hr = __mGOP.getHorizontalResolution();
        Pixel *base = (Pixel *)__mGOP.getFrameBufferBase();
        Pixel *pixel = base + (hr * y) + x;

        *pixel = p;
    }

    void drawXLine(unsigned int y, unsigned int x1, unsigned int x2, Pixel p = PIXEL_WHITE) {
        if (x1 > x2) swap(x1, x2);
        unsigned int end = min(x2, __mGOP.getHorizontalResolution());
        while (x1 <= end) {
            drawPixel(x1, y, p);
            x1++;
        }
    }

    void drawYLine(const unsigned int &x, unsigned int y1, unsigned int y2, Pixel p = PIXEL_WHITE) {
        if (y1 > y2) swap(y1, y2);
        unsigned int end = min(y2, __mGOP.getVerticalResolution());
        while (y1 <= end) {
            drawPixel(x, y1, p);
            y1++;
        }
    }

    void drawLine(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, Pixel p = PIXEL_WHITE) {
        if (x1 == x2) drawYLine(x1, y1, y2, p);
        if (y1 == y2) drawXLine(y1, x1, x2, p);
        __mLinearEquation.set(x1, y1, x2, y2);
        double x = x1;
        double deltaX { 1 };
        if (__mLinearEquation.getSlope() > 1) // deltaY = 1
            deltaX = 1. / __mLinearEquation.getSlope();
        while (x < x2) {
            drawPixel(x, __mLinearEquation.getY(x), p);
            x += deltaX;
        }
    }

private:
    GOP __mGOP;
    static LinearEquation __mLinearEquation;

};  /* GUI end */


class Graphics : public Base{
public:
    struct Rectangle {
        unsigned int x;
        unsigned int y;
        unsigned int w;
        unsigned int h;
    };

public:

    void drawRectangle(unsigned int x, unsigned int y, unsigned int w, unsigned int h, Pixel p = PIXEL_WHITE);

    void drawRectangle(Rectangle rect, Pixel p = PIXEL_WHITE);

};

void Graphics::drawRectangle(unsigned int x, unsigned int y, unsigned int w, unsigned int h, Pixel p) {
    drawXLine(y, x, x + w, p);
    drawYLine(x + w, y, y + h, p);
    drawXLine(y + h, x + w, x, p);
    drawYLine(x, y + h, y, p);
}

void Graphics::drawRectangle(Rectangle rect, Pixel p) {
    drawRectangle(rect.x, rect.y, rect.w, rect.h, p);
}



/**
 * 
 * init global(static) var
 * 
*/
LinearEquation Base::__mLinearEquation;

};  /* TU end */



#endif

