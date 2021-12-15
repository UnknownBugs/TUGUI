#ifndef __RASTERIZER_HPP__TUGUI
#define __RASTERIZER_HPP__TUGUI

#include <core/painter/impl/PaintBase.hpp>
#include <core/painter/impl/rasterizer/AABB.hpp>

namespace TUGUI {

class Rasterizer {
public:
    void operator()(const PaintInterface &pInterface, Color &c) {
        auto aabbPtr = pInterface.getAABB();
        auto min = aabbPtr.getMin();
        auto max = aabbPtr.getMax();
        for (unsigned int i = min[0]; i < max[0]; i++) {
            for (unsigned int j = min[1]; j < max[1]; j++) {
                if (pInterface.inside(i, j)) {
                    PaintBase::drawPixel(i, j, c.getGradientRgb());
                }
            }
        }
    }
};

};

#endif // __RASTERIZER_HPP__TUGUI