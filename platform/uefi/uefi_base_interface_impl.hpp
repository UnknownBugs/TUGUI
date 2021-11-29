#ifndef __UEFI_BASE_INTERFACE_HPP__
#define __UEFI_BASE_INTERFACE_HPP__

#include <base_interface.hpp>
#include <tdebug.hpp>
#include <uefi/wrapper/gop_wrapper.hpp>
#include <uefi/wrapper/systemtable_wrapper.hpp>

class BaseInterfaceImpl : public TUGUI::INTERFACE::BaseInterface {
    using ST = UEFIWrapper::SystemTable;
    using EST = UEFIWrapper::SystemTable::ESystemTable;

   public:
    void init(EST *est) {
        ST::init(est);
        ST::setWatchdogTimer(0, 0, 0, nullptr);
        ST::clearScreen();
        __mGOP = UEFIWrapper::GOP();  // init gop ptr
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

    void drawPixel(uint32_t x, uint32_t y, TUGUI::RGB rgb) override {
        uint32_t hr = getHorizontalResolution();
        UEFIWrapper::GOP::Pixel *base =
            (UEFIWrapper::GOP::Pixel *)(__mGOP.getFrameBufferBase());
        UEFIWrapper::GOP::Pixel *pixel = base + (hr * y) + x;

        pixel->red = rgb.R;
        pixel->green = rgb.G;
        pixel->blue = rgb.B;
        pixel->reserved = rgb.S;
    }

    TDEBUG::RT clearScrean() override {
        UEFIWrapper::SystemTable::clearScreen();
        return TDEBUG::RT::SUCCESS;
    }

    void *tuguiMalloc(uint64_t size) override {
        return UEFIWrapper::SystemTable::allocatePool(EfiConventionalMemory,
                                                      size);
    }

    void tuguiOutputString(uint16_t *s) override {
        UEFIWrapper::SystemTable::OutputString(s);
    }

   private:
    static UEFIWrapper::GOP __mGOP;
};  // BaseInterfaceImpl

void *operator new(uint64_t size) {
    return UEFIWrapper::SystemTable::allocatePool(EfiConventionalMemory, size);
}

void *operator new[](uint64_t size) {
    return UEFIWrapper::SystemTable::allocatePool(EfiConventionalMemory, size);
}

void operator delete(void *ptr) { UEFIWrapper::SystemTable::freePool(ptr); }

void operator delete[](void *ptr) { UEFIWrapper::SystemTable::freePool(ptr); }

void operator delete(void *ptr, uint64_t size) {
    size -= size;  // remove warning: unused parameter
    UEFIWrapper::SystemTable::freePool(ptr);
}

void operator delete[](void *ptr, uint64_t size) {
    size -= size;  // remove warning: unused parameter
    UEFIWrapper::SystemTable::freePool(ptr);
}

#endif  // __UEFI_BASE_INTERFACE_HPP__
