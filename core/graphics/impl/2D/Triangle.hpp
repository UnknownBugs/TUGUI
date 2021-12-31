#ifndef __TRIANGLE__HPP__TUGUI
#define __TRIANGLE__HPP__TUGUI

#include <defs.hpp>

#include <core/painter/PaintInterface.hpp>
#include <core/painter/impl/rasterizer/AABB.hpp>
#include <core/graphics/impl/2D/Point.hpp>
#include <core/graphics/impl/2D/Line.hpp>

namespace TUGUI {

class Triangle : public PaintInterface {
public:
    Triangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, bool filled = false)
        : __mP1(x1, y1), __mP2(x2, y2), __mP3(x3, y3), __mFilled { filled } {

        AABB aabb {
            {static_cast<double>(x1), y1},
            {static_cast<double>(x2), y2},
            {static_cast<double>(x3), y3}
        };

        __mAABB = aabb;

    }

    void paint(PaintEngine &pe) const {
        if (__mFilled) {
            pe.rasterizer(this);
        } else {
            Line(__mP1, __mP2).paint(pe);
            Line(__mP2, __mP3).paint(pe);
            Line(__mP3, __mP1).paint(pe);
        }
    }

    /**
     * 
     *   p1 ------- p3
     *     \        /
     *      \      /
     *       \    /
     *         p2
     * 
    */
    bool inside(double x, double y) const {

        Point P(x, y);

        auto p1p2 = __mP2 - __mP1;
        auto p1P = P - __mP1;

        auto p2p3 = __mP3 - __mP2;
        auto p2P = P - __mP2;

        auto p3p1 = __mP1 - __mP3;
        auto p3P = P - __mP3;

        auto z1 = TMATH::cross(p1p2, p1P)[2];
        auto z2 = TMATH::cross(p2p3, p2P)[2];
        auto z3 = TMATH::cross(p3p1, p3P)[2];

        return (z1 <= 0 && z2 <= 0 && z3 <= 0) ||
            (z1 >= 0 && z2 >= 0 && z3 >= 0);
    }

    AABB getAABB() const {
        return __mAABB;
    }

private:
    Point __mP1, __mP2, __mP3;
    bool __mFilled;
    AABB __mAABB;

}; // TRIANGLE
}; // TUGUI

#endif //__TRIANGLE__HPP__TUGUI