#ifndef __PLATFORM_HPP__TUGUI
#define __PLATFORM_HPP__TUGUI

#ifdef UEFIWrapper
#include <platform/uefi/uefi_base_interface_impl.hpp>
using BASE_INTERFACE_IMPL = BaseInterfaceImpl;
#define TUGUI_MAIN tugui_main
#elif defined(WIN)

#else
#include <platform/linux/LinuxBaseInterfaceImpl.hpp>
using BASE_INTERFACE_IMPL = LinuxBaseInterfaceImpl;
#define TUGUI_MAIN main
#endif

namespace TUGUI {

namespace PLATFORM {

static inline void init(void *sys) {
    static BASE_INTERFACE_IMPL base;
    base.init(sys);
}

}; // namespace PLATFORM

}; // namespace TUGUI

#endif // __PLATFORM_HPP__TUGUI