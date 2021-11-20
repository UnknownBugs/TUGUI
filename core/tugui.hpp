/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:13:11 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-20 23:43:45
 * 
 * Tiny UEFI Graphical User Interface
 * 
 */

#ifndef __TUGUI_HPP__
#define __TUGUI_HPP__

#include <formula.hpp>
#include <vector.hpp>
#include <utils.hpp>

#include "platform/base_interface.hpp"
#include "core/colors/color.hpp"

namespace TUGUI {

using Math::Formula::LinearEquation;
using MUTILS::max;
using MUTILS::min;
using MUTILS::swap;

class Base {
public:

    Base() = default;

    void drawPixel(unsigned int x, unsigned int y, RGB rgb) {
        gBaseInterfacePtr->drawPixel(x, y, rgb);
    }

    void drawXLine(unsigned int y, unsigned int x1, unsigned int x2, RGB rgb = PIXEL_WHITE) {
        if (x1 > x2) swap(x1, x2);
        unsigned int end = min(x2, gBaseInterfacePtr->getHorizontalResolution());
        while (x1 <= end) {
            drawPixel(x1, y, rgb);
            x1++;
        }
    }

    void drawYLine(const unsigned int &x, unsigned int y1, unsigned int y2, RGB rgb = PIXEL_WHITE) {
        if (y1 > y2) swap(y1, y2);
        unsigned int end = min(y2, gBaseInterfacePtr->getVerticalResolution());
        while (y1 <= end) {
            drawPixel(x, y1, rgb);
            y1++;
        }
    }

    void drawLine(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, RGB rgb = PIXEL_WHITE) {
        if (x1 == x2) drawYLine(x1, y1, y2, rgb);
        if (y1 == y2) drawXLine(y1, x1, x2, rgb);
        __mLinearEquation.set(x1, y1, x2, y2);
        double x = x1;
        double deltaX { 1 };
        if (__mLinearEquation.getSlope() > 1) // deltaY = 1
            deltaX = 1. / __mLinearEquation.getSlope();
        while (x < x2) {
            drawPixel(x, __mLinearEquation.getY(x), rgb);
            x += deltaX;
        }
    }

private:
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

    void drawRectangle(unsigned int x, unsigned int y, unsigned int w, unsigned int h, RGB rgb = PIXEL_WHITE);

    void drawRectangle(Rectangle rect, RGB rgb = PIXEL_WHITE);

    /**
     *  F(x, y) = x^2 + y^2 -R^2 
     *  1/8 circle of first quadrant(above)
     *  deltaX = 1;
     *  deltaY = 0.5;
     *  compare F(x + deltaX, y - deltaY) with 0 to choice (x + 1, y) and (x, y - 1)
     *  F(x + 1, y - 0.5) = x^2 + 2x + 1 + y2 - y + 0.25 - R^2
     *  Example:
     *      when initial point is (0, R),
     *      F(x + 1, y - 0.5) = 1.25 - R
     *      if (1.25 - R <= 0) choice (x + 1, y)
     *      else choice (x, y - 1)
     *          *---->(x + 1, y)
     *          |
     *          V
     *      (x, y - 1)
    */
    void drawCircle(unsigned int x0, unsigned int y0, unsigned int r, RGB rgb = PIXEL_WHITE);

private:
    /**
     *  1.x
     *  2.y 
     *  3.(0, 0)
     *  4.y = x
     *  5.y = -x
     * 
    */
    void drawCirclePoint(unsigned int x0, unsigned int y0, unsigned int x, unsigned int y, RGB rgb = PIXEL_WHITE) {
        drawPixel(x0 + x, y0 + y, rgb);   // (x, y)
        
        // base (x, y)
        drawPixel(x0 + x, y0 - y, rgb);   // 1.(x, -y)
        drawPixel(x0 - x, y0 + y, rgb);   // 2.(-x, y)
        drawPixel(x0 - x, y0 - y, rgb);   // 3.(-x, -y)
        drawPixel(x0 + y, y0 + x, rgb);   // 4.(y, x)
        drawPixel(x0 - y, y0 + x, rgb);   // 5.(-y, x)
        
        // base (y, x)
        drawPixel(x0 + y, y0 - x, rgb);   // 1.(y, -x)

        // base (-y, x)
        drawPixel(x0 - y, y0 - x, rgb);   // 1.(-y, -x)
    }

};

void Graphics::drawRectangle(unsigned int x, unsigned int y, unsigned int w, unsigned int h, RGB rgb) {
    drawXLine(y, x, x + w, rgb);
    drawYLine(x + w, y, y + h, rgb);
    drawXLine(y + h, x + w, x, rgb);
    drawYLine(x, y + h, y, rgb);
}

void Graphics::drawRectangle(Rectangle rect, RGB rgb) {
    drawRectangle(rect.x, rect.y, rect.w, rect.h, rgb);
}

void Graphics::drawCircle(unsigned int x0, unsigned int y0, unsigned int r, RGB rgb) {
    unsigned int x = 0, y = r;  // init point
    while (x <= y) {
        drawCirclePoint(x0, y0, x, y, rgb);
        // F(x + 1, y - 0.5)
        double F = x * x + 2 * x + 1 + y * y - y + 0.25 - r * r;
        if (F <= 0) {
            x++;    // (x + 1, y)
        } else {
            y--;    // (x, y -1)
        }
    }
}

/**
 * 
 * init global(static) var
 * 
*/
LinearEquation Base::__mLinearEquation;

};  /* TU end */



#endif

