#ifndef __PAINT_EGINE_HPP__TUGUI
#define __PAINT_EGINE_HPP__TUGUI

<<<<<<< HEAD
#include <platform/BaseInterface.hpp>
#include <core/painter/impl/colors/color.hpp>
#include <core/painter/PaintInterface.hpp>
=======
#include <core/painter/impl/PaintBase.hpp>
#include <core/painter/impl/colors/color.hpp>
#include <core/painter/PaintInterface.hpp>
#include <core/painter/impl/rasterizer/Rasterizer.hpp>
>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79

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

<<<<<<< HEAD
private:
    Color __mColor;
=======
    void rasterizer(const PaintInterface * const pInterface) {
        __mRasterizer(*pInterface, __mColor);
    }

private:
    Color __mColor;
    Rasterizer __mRasterizer;
>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79
}; // PaintEngine

}; // TUGUI


#endif // __PAINT_EGINE_HPP__TUGUI