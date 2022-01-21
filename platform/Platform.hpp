/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-16 23:55:54 
 * @Last Modified by: tiansongyu
 * @Last Modified time: 2021-11-29 00:12:48
 */

#ifndef __Platform_HPP__TUGUI
#define __Platform_HPP__TUGUI

#include <platform/BaseInterface.hpp>
#include <platform/uefi/uefi_base_interface_impl.hpp>

namespace TUGUI {

namespace PLATFORM {

static inline void init(void *sys) {
    static BaseInterfaceImpl base;
    base.init(sys);
}

}; // namespace PLATFORM

}; // TUGUI

#endif // __Platform_HPP__TUGUI