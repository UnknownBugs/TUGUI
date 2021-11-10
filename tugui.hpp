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

#define PIXEL_WHITE {0xFF, 0xFF, 0xFF, 0}

namespace TUGUI {

using UEFIWrapper::GOP;

class Base {
private:
    using EGOP  = GOP::EGOP;

public:
    using Pixel = GOP::Pixel;
    
public:

    Base() = default;

    void drawPixel(unsigned int x, unsigned int y, Pixel p) {
        unsigned int hr = _mGOP.getHorizontalResolution();
        Pixel *base = (Pixel *)_mGOP.getFrameBufferBase();
        Pixel *pixel = base + (hr * y) + x;

        *pixel = p;
    }

    void drawXLine(const unsigned int &y, unsigned int x1, unsigned int x2, Pixel p = PIXEL_WHITE) {
        if (x1 > x2) swap(x1, x2);
        unsigned int end = min(x2, _mGOP.getHorizontalResolution());
        while (x1 <= end) {
            drawPixel(x1, y, p);
            x1++;
        }
    }

    void drawYLine(const unsigned int &x, unsigned int y1, unsigned int y2, Pixel p = PIXEL_WHITE) {
        if (y1 > y2) swap(y1, y2);
        unsigned int end = min(y2, _mGOP.getHorizontalResolution());
        while (y1 <= end) {
            drawPixel(x, y1, p);
            y1++;
        }
    }

private:
    GOP _mGOP;

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


};  /* TU end */



#endif

