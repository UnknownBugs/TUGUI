#ifndef __PAINT_ENGINE_INTERFACE_HPP__
#define __PAINT_ENGINE_INTERFACE_HPP__

namespace TUGUI {

class PaintEngine;

class PaintInterface {
public:
    virtual void paint(PaintEngine &) const = 0;
};

}; // TUGUI

#endif // __PAINT_ENGINE_INTERFACE_HPP__