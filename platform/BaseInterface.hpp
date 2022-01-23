/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-16 23:55:54 
 * @Last Modified by: tiansongyu
 * @Last Modified time: 2021-11-29 00:12:48
 */

#ifndef __BASE_INTERFACE_HPP__
#define __BASE_INTERFACE_HPP__

#include <libs/MUTILS/mutils.hpp>

namespace TUGUI {

namespace INTERFACE {

class BaseInterface {

public:
    struct RGB {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t s;
    } __attribute__((__packed__));;

public:
    virtual void init(void *) = 0;

    virtual void drawPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t reserved) = 0;

    virtual void * getFrameBufferBase() const = 0;

    virtual uint32_t getVerticalResolution() const = 0;

    virtual uint32_t getHorizontalResolution() const = 0;

    virtual RGB getPixel(uint32_t, uint32_t) { return RGB {  }; }

    virtual int clearScrean() { return 1; }

    static BaseInterface * & getInstancePtr() {
        static BaseInterface *bInterface = nullptr;
        return bInterface;
    }

};

}; // INTERFACE

}; // TUGUI

#endif // __BASE_INTERFACE_HPP__