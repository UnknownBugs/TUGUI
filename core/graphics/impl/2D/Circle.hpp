#ifndef __CIRCLE__HPP__TUGUI
#define __CIRCLE__HPP__TUGUI

#include <libs/MUTILS/mutils.hpp>

#include <core/painter/PaintInterface.hpp>
#include <core/painter/impl/rasterizer/AABB.hpp>


namespace TUGUI {

class Circle : public PaintInterface {
public:
    Circle(uint32_t x, uint32_t y, uint32_t r, bool filled = false) :
        __mX { x }, __mY { y }, __mR { r }, __mFilled { filled } {
            AABB aabb {
                {static_cast<double>(x - r), y - r},
                {static_cast<double>(x + r), y + r}
            };
            __mAABB = aabb;
    }

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
    void paint(PaintEngine &pe) const {
        if (__mFilled) {
            pe.rasterizer(this);
        } else {
            unsigned int x = 0, y = __mR;  // init point
            while (x <= y) {
                drawCirclePoint(__mX, __mY, x, y, pe);
                // F(x + 1, y - 0.5)
                double F = x * x + 2 * x + 1 + y * y - y + 0.25 - __mR * __mR;
                if (F <= 0) {
                    x++;    // (x + 1, y)
                } else {
                    y--;    // (x, y -1)
                }
            }
        }
    }

    bool inside(double x, double y) const {
        return ( (x - __mX) * (x - __mX) + (y - __mY) * (y - __mY) ) <= __mR * __mR;
    }

    AABB getAABB() const {
        return __mAABB;
    }

private:

    uint32_t __mX, __mY, __mR;    // center
    bool __mFilled;
    AABB __mAABB;

    /**
     *  1.x
     *  2.y 
     *  3.(0, 0)
     *  4.y = x
     *  5.y = -x
     * 
    */
    void drawCirclePoint(unsigned int x0, unsigned int y0, unsigned int x, unsigned int y, PaintEngine &pe) const {
        pe.drawPixel(x0 + x, y0 + y);   // (x, y)
        
        // base (x, y)
        pe.drawPixel(x0 + x, y0 - y);   // 1.(x, -y)
        pe.drawPixel(x0 - x, y0 + y);   // 2.(-x, y)
        pe.drawPixel(x0 - x, y0 - y);   // 3.(-x, -y)
        pe.drawPixel(x0 + y, y0 + x);   // 4.(y, x)
        pe.drawPixel(x0 - y, y0 + x);   // 5.(-y, x)
        
        // base (y, x)
        pe.drawPixel(x0 + y, y0 - x);   // 1.(y, -x)

        // base (-y, x)
        pe.drawPixel(x0 - y, y0 - x);   // 1.(-y, -x)
    }


}; // CIRCLE

}; // TUGUI

#endif //__CIRCLE__HPP__TUGUI