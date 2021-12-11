#include <tugui.hpp>

int tuguiMain() {

    TUGUI::Graphics g;
    
    // test circle
    g.drawCircle(500, 500, 100, {0xFF, 0, 0xFF, 0});
    g.drawCircle(240, 500, 100, {0xFF, 0, 0, 0});
    g.drawCircle(760, 500, 100, {0, 0xFF, 0, 0});
    g.drawCircle(370, 390, 100, {0xFF, 0xFF, 0, 0});
    g.drawCircle(630, 390, 100, {0xFF, 0xFF, 0xFF, 0});

    g.drawCircle(500, 500, 400, {0x3F, 0x5F, 0x7F, 0});

    while (1);
    return 0;
}