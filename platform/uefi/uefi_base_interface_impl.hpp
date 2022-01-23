#ifndef __UEFI_BASE_INTERFACE_HPP__
#define __UEFI_BASE_INTERFACE_HPP__

#include <platform/BaseInterface.hpp>
#include <libs/MUTILS/icxxabi.hpp>

#include <UEFIWrapper.hpp>

class BaseInterfaceImpl : public TUGUI::INTERFACE::BaseInterface {

    using ST  = UEFIWrapper::SystemTable;
    using EST = UEFIWrapper::SystemTable::ESystemTable;

public:

    void init(void *est) override {
        ST::init(static_cast<EST *>(est));
        ST::setWatchdogTimer(0, 0, 0, nullptr);
        ST::clearScreen();
        __mGOP = UEFIWrapper::GOP(); // init gop ptr
        getInstancePtr() = this;
    }

    void * getFrameBufferBase() const override {
        return (void *)(__mGOP.getFrameBufferBase());
        
    }

    uint32_t getHorizontalResolution() const override {
        return __mGOP.getHorizontalResolution();
    }

    uint32_t getVerticalResolution() const override {
        return __mGOP.getVerticalResolution();
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

    int clearScrean() override {
        UEFIWrapper::SystemTable::clearScreen();
        return 0;
    }

private:
    static UEFIWrapper::GOP __mGOP;
};  // BaseInterfaceImpl

UEFIWrapper::GOP BaseInterfaceImpl::__mGOP;

#endif // __UEFI_BASE_INTERFACE_HPP__