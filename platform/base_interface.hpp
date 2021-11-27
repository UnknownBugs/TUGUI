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

namespace INTERFACE {

class BaseInterface {
public:
    virtual void drawPixel(uint32_t x, uint32_t y, RGB rgb) = 0;

    virtual uint32_t getFrameBufferBase() const = 0;

    virtual uint32_t getVerticalResolution() const = 0;

    virtual uint32_t getHorizontalResolution() const = 0;

    virtual RT clearScrean() {
        return RT::ERROR;
    }

    virtual void * tuguiMalloc(uint64_t size) = 0;

    // TODO: START
    virtual void tuguiReadKeyStroke() = 0;

    virtual void tuguiOutputString() = 0;
    // TODO: END
};

class EventInterface {

    using voidFunc = void (*) ();

public:

    virtual void waitEvent() {

    }

    virtual void timerEvent(voidFunc vfunc, uint32_t ns) {
        
    }

    virtual void keyboardEvent() {

    }

};

extern EventInterface *gEventInterfacePtr;

extern BaseInterface *gBaseInterfacePtr;


}; // INTERFACE


}; // TUGUI

int tuguiMain();

// Memory Alloc
void * operator new(uint64_t size);
void * operator new[](uint64_t size);

// placement new
void * operator new(uint64_t size, void *ptr);
void * operator new[](uint64_t size, void *ptr);

void operator delete(void *ptr);
void operator delete[](void *ptr);

void operator delete(void* ptr, uint64_t size);
void operator delete[](void* ptr, uint64_t size);

#endif // __BASE_INTERFACE_HPP__