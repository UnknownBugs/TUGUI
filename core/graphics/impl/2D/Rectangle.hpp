#ifndef __RECTANGLE__HPP__TUGUI
#define __RECTANGLE__HPP__TUGUI

#include <defs.hpp>

#include <core/painter/PaintInterface.hpp>

#include <core/graphics/impl/2D/Line.hpp>

/***
 *  (x, y)
 *     +------------+
 *     |            |  h
 *     |            |
 *     +------------+
 *            w
 **/


namespace TUGUI {

class Rectangle : public PaintInterface {
public:
    Rectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h) :
        __mX { x }, __mY { y }, __mW { w }, __mH { h } { }

    void paint(PaintEngine &pe) const {
        Line(__mX, __mY, __mX + __mW, __mY).paint(pe);
        Line(__mX + __mW, __mY, __mX + __mW, __mY + __mH).paint(pe);
        Line(__mX + __mW, __mY + __mH, __mX, __mY + __mH).paint(pe);
        Line( __mX, __mY + __mH, __mX, __mY).paint(pe);
    }

private:
    uint32_t __mX, __mY;
    uint32_t __mW, __mH;
    
}; // Rectangle
}; // TUGUI

#endif //__RECTANGLE__HPP__TUGUI