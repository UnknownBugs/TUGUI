/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-17 01:12:54 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-21 00:27:54
 */

#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <defs.hpp>
#include <array.hpp>

#include <core/painter/impl/colors/colorTable.hpp>


namespace TUGUI {

class Color {

public:

    struct RGB {
        uint8_t R;
        uint8_t G;
        uint8_t B;
    };

public:

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t transp = 0) : 
        Color({r, g, b}, transp) { }

    Color(const RGB &rgb = WHITE, uint8_t transp = 0) : Color(rgb, rgb, transp) { }

    Color(const RGB &rgbBegin, const RGB &rgbEnd, uint8_t transp = 0) {
        __mRgbBegin = rgbBegin;
        __mRgbEnd = rgbEnd;
        __mTransparency = transp;
        __mRgbBuff = nullptr;
        __mBuffSize = 0;
    }

    ~Color() {
        if (nullptr != __mRgbBuff) {
            delete [] __mRgbBuff;
        }
    }

    
    const RGB * getGradientRgbBuff(uint32_t size = 1) {
        if (size > __mBuffSize) {
            resize(size);
        } else if (size <= __mBuffSize / 2) {
            resize(__mBuffSize / 2);
        }
        for (unsigned int i = 0; i < size; i++) {
            __mRgbBuff[i] = getGradientRgb(i, size);
        }
        return  __mRgbBuff;
    }

    // Gradient = A + (B-A) / Step * index
    RGB getGradientRgb(int32_t index, int32_t step) const {
        RGB ans;
        if (index > step) step = index;
        // use int32_t to avoid overflow
        int32_t beginR = __mRgbBegin.R, beginG = __mRgbBegin.G, beginB = __mRgbBegin.B;
        int32_t endR = __mRgbEnd.R, endG = __mRgbEnd.G, endB = __mRgbEnd.B;
        ans.R = beginR + (endR - beginR) * index * 1. / step;
        ans.G = beginG + (endG - beginG) * index * 1. / step;
        ans.B = beginB + (endB - beginB) * index * 1. / step;
        return ans;
    }

private:
    RGB __mRgbBegin, __mRgbEnd;
    RGB *__mRgbBuff;
    uint32_t __mBuffSize;
    uint8_t __mTransparency;

    void resize(uint32_t size) {
        delete [] __mRgbBuff;
        __mRgbBuff = new RGB[size];
        __mBuffSize = size;
    }
}; // Color

}; // TUGUI

#endif