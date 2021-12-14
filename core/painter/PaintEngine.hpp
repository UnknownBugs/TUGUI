#ifndef __PAINT_EGINE_HPP__TUGUI
#define __PAINT_EGINE_HPP__TUGUI

#include <core/painter/impl/PaintBase.hpp>
#include <core/painter/impl/colors/color.hpp>
#include <core/painter/PaintInterface.hpp>
#include <core/painter/impl/rasterizer/Rasterizer.hpp>

namespace TUGUI {

class PaintEngine {

public:
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

public: // OP

    void operator()(PaintInterface * const pInterface) {
        pInterface->paint(*this);
    }

    void operator()(const PaintInterface &pInterface) {
        pInterface.paint(*this);
    }

public:

    PaintEngine() {
        __mColor = Color(WHITE, BLACK);
    }

    void setColor(const Color &color) {
        __mColor = color;
    }

    void setColorGradient(uint32_t gradient) {
        __mColor.setGradient(gradient);
    }

    void drawPixel(uint32_t x, uint32_t y) {
        PaintBase::drawPixel(x, y, __mColor.getGradientRgb());
    }

    void rasterizer(const PaintInterface * const pInterface) {
        __mRasterizer(*pInterface, __mColor);
    }

private:
    Color __mColor;
    Rasterizer __mRasterizer;
}; // PaintEngine

}; // TUGUI


#endif // __PAINT_EGINE_HPP__TUGUI