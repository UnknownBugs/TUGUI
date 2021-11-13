#include <tugui.hpp>

using TUGUI::UEFIWrapper::SystemTable;
using TUGUI::GOP;

extern "C" void
tugui_main(void *ImageHandle __attribute__ ((unused)), SystemTable::ESystemTable *systemTable) {
    SystemTable::init(systemTable);
    SystemTable::setWatchdogTimer(0, 0, 0, nullptr);

    SystemTable::clearScreen();

    TUGUI::Graphics g;
    
    // test circle
    g.drawCircle(500, 500, 100, {0xFF, 0, 0xFF, 0});
    g.drawCircle(240, 500, 100, {0xFF, 0, 0, 0});
    g.drawCircle(760, 500, 100, {0, 0xFF, 0, 0});
    g.drawCircle(370, 390, 100, {0xFF, 0xFF, 0, 0});
    g.drawCircle(630, 390, 100, {0xFF, 0xFF, 0xFF, 0});

    while (1);
}