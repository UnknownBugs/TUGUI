#ifndef __UEFI_BASE_INTERFACE_HPP__
#define __UEFI_BASE_INTERFACE_HPP__

#include <BaseInterface.hpp>
#include <tdebug.hpp>
#include <icxxabi.hpp>

#include <UEFIWrapper.hpp>

class BaseInterfaceImpl : public TUGUI::INTERFACE::BaseInterface {

    using ST  = UEFIWrapper::SystemTable;
    using EST = UEFIWrapper::SystemTable::ESystemTable;

public:

    void init(EST *est) {
        ST::init(est);
        ST::setWatchdogTimer(0, 0, 0, nullptr);
        ST::clearScreen();
        __mGOP = UEFIWrapper::GOP(); // init gop ptr
    }

    uint32_t getFrameBufferBase() const override {
        return __mGOP.getFrameBufferBase();
        
    }

    uint32_t getHorizontalResolution() const override {
        return __mGOP.getHorizontalResolution();
    }

    uint32_t getVerticalResolution() const override {
        return __mGOP.getVerticalResolution();
    }
    void tuguiblt(unsigned char img[], unsigned int img_width,
                  unsigned int img_height,unsigned int posX,unsigned int posY) override {
        unsigned char *fb;
        unsigned int i, j, k, vr, hr, ofs = 0;
        fb = (unsigned char *)__mGOP.getFrameBufferBase();
        vr = __mGOP.getVerticalResolution();
        hr = __mGOP.getHorizontalResolution();
        fb += hr * posY * 4 + posX * 4;
        for (i = 0; i < vr; i++) {
            if (i >= img_height) break;
            for (j = 0; j < hr; j++) {
                if (j >= img_width) {
                    fb += (hr - img_width) * 4;
                    break;
                }
                for (k = 0; k < 4; k++) *fb++ = img[ofs++];
            }
        }
    }

    void drawPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t reserved) override {
        uint32_t hr = getHorizontalResolution();
        UEFIWrapper::GOP::Pixel *base = (UEFIWrapper::GOP::Pixel *)(__mGOP.getFrameBufferBase());
        UEFIWrapper::GOP::Pixel *pixel = base + (hr * y) + x;

        pixel->red = r;
        pixel->green = g;
        pixel->blue = b;
        pixel->reserved = reserved;
    }

    TDEBUG::RT clearScrean() override {
        UEFIWrapper::SystemTable::clearScreen();
        return TDEBUG::RT::SUCCESS;
    }

    void * tuguiMalloc(uint64_t size) override {
        return UEFIWrapper::SystemTable::allocatePool(EfiConventionalMemory, size);
    }

   private:
    static UEFIWrapper::GOP __mGOP;
};  // BaseInterfaceImpl

void * operator new(uint64_t size) {
    return UEFIWrapper::SystemTable::allocatePool(EfiConventionalMemory, size);
}

void * operator new[](uint64_t size) {
    return UEFIWrapper::SystemTable::allocatePool(EfiConventionalMemory, size);
}

void operator delete(void *ptr) {
    UEFIWrapper::SystemTable::freePool(ptr);
}

void operator delete[](void *ptr) {
    UEFIWrapper::SystemTable::freePool(ptr);
}

void operator delete(void* ptr, uint64_t size) {
     size -= size;  // remove warning: unused parameter
    UEFIWrapper::SystemTable::freePool(ptr);
}

void operator delete[](void* ptr, uint64_t size) {
    size -= size;   // remove warning: unused parameter
    UEFIWrapper::SystemTable::freePool(ptr);
}

#endif // __UEFI_BASE_INTERFACE_HPP__