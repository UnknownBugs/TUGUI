#ifndef __RECTANGLE__HPP__TUGUI
#define __RECTANGLE__HPP__TUGUI

#include <defs.hpp>

#include <core/painter/PaintInterface.hpp>
#include <core/painter/impl/rasterizer/AABB.hpp>

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
    Rectangle(uint32_t x, uint32_t y, uint32_t w, uint32_t h, bool filled = false) :
        __mX { x }, __mY { y }, __mW { w }, __mH { h }, __mFilled(filled) {
        
        AABB aabb { 
            {x, y}, 
            {x + w, y + h}
        };
        
        __mAABB = aabb;
    }

    void paint(PaintEngine &pe) const {
        if (__mFilled) {
            pe.rasterizer(this);
        } else {
            Line(__mX, __mY, __mX + __mW, __mY).paint(pe);
            Line(__mX + __mW, __mY, __mX + __mW, __mY + __mH).paint(pe);
            Line(__mX + __mW, __mY + __mH, __mX, __mY + __mH).paint(pe);
            Line( __mX, __mY + __mH, __mX, __mY).paint(pe);
        }
    }

    bool inside(double x, double y) const {
        return x >= __mX && x <= __mX + __mW &&
            y >= __mY && y <= __mY + __mH;
    }

    AABB getAABB() const {
        return __mAABB;
    }

private:
    uint32_t __mX, __mY;
    uint32_t __mW, __mH;
    bool __mFilled;
    AABB __mAABB;
    
}; // Rectangle
}; // TUGUI

#endif //__RECTANGLE__HPP__TUGUI