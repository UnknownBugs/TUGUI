/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-16 23:55:54 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-21 00:12:48
 */

#ifndef __BASE_INTERFACE_HPP__
#define __BASE_INTERFACE_HPP__

#include <defs.hpp>
#include <tdebug.hpp>

#include "core/colors/color.hpp"

namespace TUGUI {

using TDEBUG::RT;

class BaseInterface {
public:
    virtual void drawPixel(unsigned int x, unsigned int y, RGB rgb) = 0;

    virtual uint32_t getFrameBufferBase() const = 0;

    virtual uint32_t getVerticalResolution() const = 0;

    virtual uint32_t getHorizontalResolution() const = 0;

    virtual RT clearScrean() {
        return RT::ERROR;
    }

    virtual void * malloc(uint64_t size);
};

extern BaseInterface *gBaseInterfacePtr;

}; // TUGUI

int tugui_main();

// Memory Alloc
void * operator new(uint64_t size);
void * operator new[](uint64_t size);

// placement new
void * operator new(uint64_t size, void *ptr);
void * operator new[](uint64_t size, void *ptr);

void operator delete(void *ptr);
void operator delete[](void *ptr);

#endif // __BASE_INTERFACE_HPP__