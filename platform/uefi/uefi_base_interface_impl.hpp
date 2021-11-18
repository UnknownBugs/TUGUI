#ifndef __UEFI_BASE_INTERFACE_HPP__
#define __UEFI_BASE_INTERFACE_HPP__

#include <base_interface.h>
#include <gop_wrapper.hpp>

class BaseInterfaceImpl : public TUGUI::BaseInterface {

public:
    MUTILS::uint32_t getFrameBufferBase() const;

    MUTILS::uint32_t getHorizontalResolution() const;

    MUTILS::uint32_t getVerticalResolution() const;

    void drawPixel(MUTILS::uint32_t x, MUTILS::uint32_t y, TUGUI::RGB rgb);

private:
    static UEFIWrapper::GOP __mGOP;
}; // BaseInterfaceImpl

MUTILS::uint32_t BaseInterfaceImpl::getFrameBufferBase() const {
    return __mGOP.getFrameBufferBase();
}

MUTILS::uint32_t BaseInterfaceImpl::getHorizontalResolution() const {
    return __mGOP.getHorizontalResolution();
}

MUTILS::uint32_t BaseInterfaceImpl::getVerticalResolution() const {
    return __mGOP.getVerticalResolution();
}

void BaseInterfaceImpl::drawPixel(MUTILS::uint32_t x, MUTILS::uint32_t y, TUGUI::RGB rgb) {
    MUTILS::uint32_t hr = getHorizontalResolution();
    UEFIWrapper::GOP::Pixel *base = (UEFIWrapper::GOP::Pixel *)(__mGOP.getFrameBufferBase());
    UEFIWrapper::GOP::Pixel *pixel = base + (hr * y) + x;

    pixel->red = rgb.R;
    pixel->green = rgb.G;
    pixel->blue = rgb.B;
    pixel->reserved = rgb.S;
}

UEFIWrapper::GOP BaseInterfaceImpl::__mGOP;

#endif // __UEFI_BASE_INTERFACE_HPP__