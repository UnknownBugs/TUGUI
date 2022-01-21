#ifndef __PAINT_EGINE_HPP__TUGUI
#define __PAINT_EGINE_HPP__TUGUI

#include <core/painter/impl/PaintBase.hpp>
#include <core/painter/impl/colors/color.hpp>
#include <core/painter/PaintInterface.hpp>

namespace TUGUI {

class Transparency;

class PaintEngine {

public:
    struct PaintBase {
        static void clearScreen() {
            INTERFACE::BaseInterface::getInstancePtr()->clearScrean();
        }

        static void drawPixel(uint32_t x, uint32_t y, Color::RGB rgb = WHITE) {
            INTERFACE::BaseInterface::getInstancePtr()->drawPixel(x, y, rgb.R, rgb.G, rgb.B, 0);
        }

        static uint32_t getHorizontalResolution() {
            return INTERFACE::BaseInterface::getInstancePtr()->getHorizontalResolution();
        }

        static uint32_t getVerticalResolution() {
            return INTERFACE::BaseInterface::getInstancePtr()->getVerticalResolution();
        }

        static Color::RGB getPixel(uint32_t x, uint32_t y) {
            Color::RGB *VM = (Color::RGB *)(INTERFACE::BaseInterface::getInstancePtr()->getFrameBufferBase());
            uint32_t hr = getHorizontalResolution();
            if (x >= getHorizontalResolution() || y >= getVerticalResolution()) {
                // todo
            }
            return VM[(hr * y) + x];
        }
    }; // PaintBase

    class Transparency {
    public:
        Color::RGB operator()(const Color::RGB &preRgb, const Color::RGB &bgRgb) const {
            Color::RGB rgb {0, 0, 0, 0};
            if (0 != __mTrans) {
                rgb.R = preRgb.R * (1 - __mTrans) + bgRgb.R * __mTrans;
                rgb.G = preRgb.G * (1 - __mTrans) + bgRgb.G * __mTrans;
                rgb.B = preRgb.B * (1 - __mTrans) + bgRgb.B * __mTrans;
            }
            return rgb;
        }

        operator bool () const {
            return __mTrans != 0;
        }

    public:
        Transparency(double trans) : __mTrans { trans } { }

        void set(double trans) {
            __mTrans = MUTILS::abs(trans);
            if (__mTrans > 1)
                __mTrans = (static_cast<int>(__mTrans)  % 100 * 1.) / 100;
        }

    private:
        double __mTrans;
    }; // Transparency

    class Rasterizer {
    public:
        void operator()(const PaintInterface &pInterface, Color &c, const Transparency &trans) {
            auto aabbPtr = pInterface.getAABB();
            auto min = aabbPtr.getMin();
            auto max = aabbPtr.getMax();
            for (unsigned int x = min[0]; x < max[0]; x++) {
                for (unsigned int y = min[1]; y < max[1]; y++) {
                    if (pInterface.inside(x, y)) {
                        auto rgb = c.getGradientRgb();
                        if (trans) {
                            rgb = trans(rgb, PaintBase::getPixel(x, y));
                        }
                        PaintBase::drawPixel(x, y, rgb);
                    }
                }
            }
        }
    };

public: // OP

    void operator()(PaintInterface * const pInterface) {
        pInterface->paint(*this);
    }

    void operator()(const PaintInterface &pInterface) {
        pInterface.paint(*this);
    }

public:

    PaintEngine() : __mTransparency { 0 } {
        __mColor = Color(WHITE, BLACK);
    }

    void setColor(const Color &color) {
        __mColor = color;
    }

    void setColorGradient(uint32_t gradient) {
        __mColor.setGradient(gradient);
    }

    void setTransparency(double trans) {
        __mTransparency.set(trans);
    }

    void drawPixel(uint32_t x, uint32_t y) {
        auto rgb = __mColor.getGradientRgb();
        if (__mTransparency) {
            rgb = __mTransparency(rgb, PaintBase::getPixel(x, y));
        }
        PaintBase::drawPixel(x, y, rgb);
    }

    void rasterizer(const PaintInterface * const pInterface) {
        __mRasterizer(*pInterface, __mColor, __mTransparency);
    }

private:
    Color __mColor;
    Rasterizer __mRasterizer;
    Transparency __mTransparency;

}; // PaintEngine

}; // TUGUI


#endif // __PAINT_EGINE_HPP__TUGUI