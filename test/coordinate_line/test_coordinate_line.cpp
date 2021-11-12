#include <tugui.hpp>

using TUGUI::UEFIWrapper::SystemTable;
using TUGUI::GOP;

extern "C" void
tugui_main(void *ImageHandle __attribute__ ((unused)), SystemTable::ESystemTable *systemTable) {
    SystemTable::init(systemTable);
    SystemTable::setWatchdogTimer(0, 0, 0, nullptr);

    SystemTable::clearScreen();

    TUGUI::Base base;
    base.drawXLine(100, 100, 260, {0, 0, 0xFF, 0});
    base.drawXLine(102, 150, 360, {0xFF, 0xFF, 0xFF, 0});

    TUGUI::Graphics g;
    base.drawYLine(104, 200, 460, {0, 0xFF, 0xFF, 0});
    base.drawYLine(106, 250, 560, {0xFF, 0, 0xFF, 0});

    // / coordinate
    g.drawXLine(500, 300, 700, {0, 0, 0xFF, 0});
    g.drawYLine(500, 300, 700, {0, 0xFF, 0, 0});
    while (1);
}