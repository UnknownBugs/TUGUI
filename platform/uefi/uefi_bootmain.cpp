#include "uefi_base_interface_impl.hpp"
using UEFIWrapper::SystemTable;

TUGUI::INTERFACE::BaseInterface *TUGUI::INTERFACE::gBaseInterfacePtr = nullptr;
UEFIWrapper::GOP BaseInterfaceImpl::__mGOP;

extern "C" void
tugui_bootmain(void *ImageHandle __attribute__ ((unused)), SystemTable::ESystemTable *systemTable) {
    BaseInterfaceImpl base;
    base.init(systemTable);
    TUGUI::INTERFACE::gBaseInterfacePtr = &base;
    tuguiMain();
}