#ifndef __PAINT_ENGINE_INTERFACE_HPP__
#define __PAINT_ENGINE_INTERFACE_HPP__

#include <core/painter/impl/rasterizer/AABB.hpp>

namespace TUGUI {

class PaintEngine;

class PaintInterface {

public:
    virtual ~PaintInterface() { }

public:
    virtual void paint(PaintEngine &) const = 0;

    virtual bool inside(double, double) const {
        return false;
    }

    virtual AABB getAABB() const {
        AABB aabb;
        return aabb;
    }
};

}; // TUGUI

#endif // __PAINT_ENGINE_INTERFACE_HPP__
