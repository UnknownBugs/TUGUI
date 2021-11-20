#ifndef __UEFI_BASE_INTERFACE_HPP__
#define __UEFI_BASE_INTERFACE_HPP__

#include <base_interface.hpp>

#include <uefi/wrapper/gop_wrapper.hpp>
#include <uefi/wrapper/systemtable_wrapper.hpp>

class BaseInterfaceImpl : public TUGUI::BaseInterface {

    using ST  = UEFIWrapper::SystemTable;
    using EST = UEFIWrapper::SystemTable::ESystemTable;

public:

    void init(EST *est);

    uint32_t getFrameBufferBase() const override;

    uint32_t getHorizontalResolution() const override;

    uint32_t getVerticalResolution() const override;

    void drawPixel(uint32_t x, uint32_t y, TUGUI::RGB rgb) override;

private:
    static UEFIWrapper::GOP __mGOP;
}; // BaseInterfaceImpl

void BaseInterfaceImpl::init(EST *est) {
    ST::init(est);
    ST::setWatchdogTimer(0, 0, 0, nullptr);
    ST::clearScreen();
    __mGOP = UEFIWrapper::GOP(); // init gop ptr
}

uint32_t BaseInterfaceImpl::getFrameBufferBase() const {
    return __mGOP.getFrameBufferBase();
}

uint32_t BaseInterfaceImpl::getHorizontalResolution() const {
    return __mGOP.getHorizontalResolution();
}

uint32_t BaseInterfaceImpl::getVerticalResolution() const {
    return __mGOP.getVerticalResolution();
}

void BaseInterfaceImpl::drawPixel(uint32_t x, uint32_t y, TUGUI::RGB rgb) {
    uint32_t hr = getHorizontalResolution();
    UEFIWrapper::GOP::Pixel *base = (UEFIWrapper::GOP::Pixel *)(__mGOP.getFrameBufferBase());
    UEFIWrapper::GOP::Pixel *pixel = base + (hr * y) + x;

    pixel->red = rgb.R;
    pixel->green = rgb.G;
    pixel->blue = rgb.B;
    pixel->reserved = rgb.S;
}

void * operator new(uint64_t size) {

}

#endif // __UEFI_BASE_INTERFACE_HPP__