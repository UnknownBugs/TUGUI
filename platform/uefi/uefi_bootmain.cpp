#include "uefi_base_interface_impl.hpp"

using namespace TUGUI;
using UEFIWrapper::SystemTable;

static BaseInterfaceImpl uefi; 

extern "C" void
tugui_bootmain(void *ImageHandle __attribute__ ((unused)), SystemTable::ESystemTable *systemTable) {
    
    SystemTable::init(systemTable);
    SystemTable::setWatchdogTimer(0, 0, 0, nullptr);
    SystemTable::clearScreen();

    initInterface(&uefi);

    tugui_main();
}