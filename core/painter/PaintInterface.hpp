#ifndef __PAINT_ENGINE_INTERFACE_HPP__
#define __PAINT_ENGINE_INTERFACE_HPP__

<<<<<<< HEAD
=======
#include <core/painter/impl/rasterizer/AABB.hpp>

>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79
namespace TUGUI {

class PaintEngine;

class PaintInterface {
public:
    virtual void paint(PaintEngine &) const = 0;
<<<<<<< HEAD
=======

    virtual bool inside(double, double) const {
        return false;
    }

    virtual AABB getAABB() const {
        AABB aabb;
        return aabb;
    }
>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79
};

}; // TUGUI

#endif // __PAINT_ENGINE_INTERFACE_HPP__