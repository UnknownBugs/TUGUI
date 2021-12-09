#ifndef __PAINT_ENGINE_INTERFACE_HPP__
#define __PAINT_ENGINE_INTERFACE_HPP__

#include <core/painter/impl/PaintBase.hpp>
#include <core/painter/impl/colors/color.hpp>

namespace TUGUI {

class PaintInterface {
public:
    virtual void paint(Color &) const = 0;
};

}; // TUGUI

#endif // __PAINT_ENGINE_INTERFACE_HPP__