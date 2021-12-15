/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-17 01:12:54 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-21 00:27:54
 */

<<<<<<< HEAD
#ifndef __COLOR_HPP__
#define __COLOR_HPP__
=======
#ifndef __COLOR_HPP__TUGUI
#define __COLOR_HPP__TUGUI
>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79

#include <defs.hpp>
#include <array.hpp>

#include <core/painter/impl/colors/colorTable.hpp>


namespace TUGUI {

class Color {

public: // Type

    struct RGB {
        uint8_t R;
        uint8_t G;
        uint8_t B;
    };

public: // cntor

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t transp = 0) : 
        Color({r, g, b}, transp) { }

    Color(const RGB &rgb = WHITE, uint8_t transp = 0) : Color(rgb, rgb, transp) { }

    Color(const RGB &rgbBegin, const RGB &rgbEnd, uint8_t transp = 0) {
        __mRgbBegin = rgbBegin;
        __mRgbEnd = rgbEnd;
        __mTransparency = transp;
<<<<<<< HEAD
        __mRgbBuff = nullptr;
        __mBuffSize = __mIndex = 0;
=======
        __mIndex = __mBuffSize =  0;
        __mRgbBuff = nullptr;

        setGradient(1);
>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79
    }

    ~Color() {
        if (nullptr != __mRgbBuff) {
            delete [] __mRgbBuff;
        }
    }

public: // setter/getter
    
    const RGB * getGradientRgbBuff() const {
        return  __mRgbBuff;
    }

    // Gradient = A + (B-A) / Step * index
    RGB getGradientRgb(int32_t index, int32_t step) const {
        RGB ans;
        if (index > step) step = index;
        // use int32_t to avoid overflow & signed integer and unsigned interger compute issue
        int32_t beginR = __mRgbBegin.R, beginG = __mRgbBegin.G, beginB = __mRgbBegin.B;
        int32_t endR = __mRgbEnd.R, endG = __mRgbEnd.G, endB = __mRgbEnd.B;
        ans.R = beginR + (endR - beginR) * index * 1. / step;
        ans.G = beginG + (endG - beginG) * index * 1. / step;
        ans.B = beginB + (endB - beginB) * index * 1. / step;
        return ans;
    }

    RGB getGradientRgb() {
        __mIndex = (__mIndex + 1) % __mBuffSize;
        return __mRgbBuff[__mIndex];
    }

    void setGradient(uint32_t gradient) {
        if (gradient > __mBuffSize) {
            resize(gradient);
        } else if (gradient <= __mBuffSize / 2) {
            resize(__mBuffSize / 2);
        }
<<<<<<< HEAD
        for (unsigned int i = 0; i < gradient; i++) {
=======
        for (unsigned int i = 0; i <= gradient; i++) {
>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79
            __mRgbBuff[i] = getGradientRgb(i, gradient);
        }

        __mBuffSize = gradient;
        __mIndex = __mBuffSize - 1;
    }

private:

    RGB __mRgbBegin, __mRgbEnd;
    RGB *__mRgbBuff;
    uint32_t __mIndex, __mBuffSize;
    uint8_t __mTransparency;

    void resize(uint32_t size) {
        delete [] __mRgbBuff;
        __mRgbBuff = new RGB[size];
        __mBuffSize = size;
    }
}; // Color

}; // TUGUI

<<<<<<< HEAD
#endif
=======
#endif // __COLOR_HPP__TUGUI
>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79
