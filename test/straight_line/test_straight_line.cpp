#include <tugui.hpp>

using TUGUI::UEFIWrapper::SystemTable;
using TUGUI::GOP;

extern "C" void
tugui_main(void *ImageHandle __attribute__ ((unused)), SystemTable::ESystemTable *systemTable) {
    SystemTable::init(systemTable);
    SystemTable::setWatchdogTimer(0, 0, 0, nullptr);

    SystemTable::clearScreen();

    TUGUI::Graphics g;

    // coordinate
    g.drawXLine(50, 50, 800);
    g.drawYLine(50, 50, 800);

    // test line
    g.drawLine(50, 50, 600, 50, {0xFF, 0, 0, 0});
    g.drawLine(50, 50, 500, 100, {0, 0xFF, 0, 0});  // erro
    g.drawLine(50, 50, 400, 200, {0, 0, 0xFF, 0});
    g.drawLine(50, 50, 300, 300, {0xFF, 0xFF, 0, 0});
    g.drawLine(50, 50, 200, 400, {0xFF, 0, 0xFF, 0});
    g.drawLine(50, 50, 100, 500, {0, 0xFF, 0xFF, 0});
    g.drawLine(50, 50, 50, 600, {0x66, 0x66, 0x66, 0});

    while (1);
}