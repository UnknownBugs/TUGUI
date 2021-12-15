#ifndef __PAINT_BASE_HPP__TUGUI
#define __PAINT_BASE_HPP__TUGUI

#include <platform/BaseInterface.hpp>
#include <core/painter/impl/colors/color.hpp>

namespace TUGUI {

struct PaintBase {
    static void clearScreen() {
        INTERFACE::gBaseInterfacePtr->clearScrean();
    }

    static void drawPixel(uint32_t x, uint32_t y, Color::RGB rgb = WHITE) {
        INTERFACE::gBaseInterfacePtr->drawPixel(x, y, rgb.R, rgb.G, rgb.B, 0);
    }

    static uint32_t getHorizontalResolution() {
        return INTERFACE::gBaseInterfacePtr->getHorizontalResolution();
    }

    static uint32_t getVerticalResolution() {
        return INTERFACE::gBaseInterfacePtr->getVerticalResolution();
    }
}; // PaintBase

} // TUGUI

#endif // __PAINT_BASE_HPP__TUGUI