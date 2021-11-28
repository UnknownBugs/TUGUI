#include "uefi_base_interface_impl.hpp"
#include "uefi_event_interface_impl.hpp"

using UEFIWrapper::SystemTable;

TUGUI::INTERFACE::BaseInterface *TUGUI::INTERFACE::gBaseInterfacePtr = nullptr;
TUGUI::INTERFACE::EventInterface *TUGUI::INTERFACE::gEventInterfacePtr = nullptr;

UEFIWrapper::GOP BaseInterfaceImpl::__mGOP;
UEFIWrapper::STIEP EventInterfaceImpl::__mSTIEP;

extern "C" void
tugui_bootmain(void *ImageHandle __attribute__((unused)), SystemTable::ESystemTable *systemTable)
{
    BaseInterfaceImpl base;
    base.init(systemTable);
    TUGUI::INTERFACE::gBaseInterfacePtr = &base;

    EventInterfaceImpl event;
    event.init(systemTable);
    TUGUI::INTERFACE::gEventInterfacePtr = &event;
    
    tuguiMain();
}