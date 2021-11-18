/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-16 23:55:54 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-19 03:15:56
 */

#ifndef __BASE_INTERFACE_HPP__
#define __BASE_INTERFACE_HPP__

#include <defs.h>
#include <tdebug.hpp>
#include <color.hpp>

namespace TUGUI {

using TDEBUG::RT;

class BaseInterface {
public:
    virtual void drawPixel(unsigned int x, unsigned int y, RGB rgb) = 0;

    virtual MUTILS::uint32_t getFrameBufferBase() const = 0;

    virtual MUTILS::uint32_t getVerticalResolution() const = 0;

    virtual MUTILS::uint32_t getHorizontalResolution() const = 0;

    virtual RT clearScrean() {
        return RT::ERROR;
    }
};

static BaseInterface *gBaseInterface = nullptr;

inline static
void initInterface(BaseInterface *bi) {
    gBaseInterface = bi;
}

}; // TUGUI

int tugui_main();

#endif // __INTERFACE_HPP__