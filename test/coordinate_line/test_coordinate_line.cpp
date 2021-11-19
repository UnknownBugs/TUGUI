#include <tugui.hpp>

int tugui_main() {
    TUGUI::Base base;
    base.drawXLine(100, 100, 260, {0, 0, 0xFF, 0});
    base.drawXLine(102, 150, 360, {0xFF, 0xFF, 0xFF, 0});
    base.drawYLine(104, 200, 460, {0, 0xFF, 0xFF, 0});
    base.drawYLine(106, 250, 560, {0xFF, 0, 0xFF, 0});

    TUGUI::Graphics g;
    // coordinate
    g.drawXLine(500, 300, 700, {0, 0, 0xFF, 0});
    g.drawYLine(500, 300, 700, {0, 0xFF, 0, 0});
    while (1);
    return 0;
}