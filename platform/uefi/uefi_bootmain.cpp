#include "uefi_base_interface_impl.hpp"

using UEFIWrapper::SystemTable;

TUGUI::BaseInterface *TUGUI::gBaseInterfacePtr = nullptr;
UEFIWrapper::GOP BaseInterfaceImpl::__mGOP;

extern "C" void
tugui_bootmain(void *ImageHandle __attribute__ ((unused)), SystemTable::ESystemTable *systemTable) {
    BaseInterfaceImpl base;
    base.init(systemTable);
    TUGUI::gBaseInterfacePtr = &base;
    tuguiMain();
}