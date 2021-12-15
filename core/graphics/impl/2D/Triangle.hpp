#ifndef __TRIANGLE__HPP__TUGUI
#define __TRIANGLE__HPP__TUGUI

#include <defs.hpp>

#include <core/painter/PaintInterface.hpp>
#include <core/painter/impl/rasterizer/AABB.hpp>

namespace TUGUI {

class Triangle : public PaintInterface {
public:
    Triangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, bool filled = false) {

    }

    void paint(PaintEngine &pe) const {
        
    }

    bool inside(double x, double y) const {
        
    }

    AABB getAABB() const {
        
    }

}; // TRIANGLE
}; // TUGUI

#endif //__TRIANGLE__HPP__TUGUI