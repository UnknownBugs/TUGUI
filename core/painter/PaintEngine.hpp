#ifndef __PAINT_EGINE_HPP__
#define __PAINT_EGINE_HPP__

#include <core/painter/impl/colors/color.hpp>
#include <core/painter/impl/PaintBase.hpp>
#include <core/painter/PaintInterface.hpp>

namespace TUGUI {

class PaintEngine {

public:

    PaintEngine() {
        __mColor = Color(WHITE, BLACK);
    }

    void operator()(PaintInterface * const pInterface) {
        pInterface->paint(__mColor);
    }

    void operator()(const PaintInterface &pInterface) {
        pInterface.paint(__mColor);
    }

    void setColor(const Color &color) {
        __mColor = color;
    }

private:
    Color __mColor;
}; // PaintEngine

}; // TUGUI


#endif // __PAINT_EGINE_HPP__