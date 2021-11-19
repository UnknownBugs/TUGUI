#include <tugui.hpp>

int tugui_main() {
    
    TUGUI::Graphics g;
    
    // test Rect
    g.drawRectangle(500, 500, 100, 30, {0xFF, 0, 0xFF, 0});
    g.drawRectangle(240, 500, 100, 80, {0xFF, 0, 0, 0});
    g.drawRectangle(760, 500, 100, 100, {0, 0xFF, 0, 0});
    g.drawRectangle(370, 390, 100, 300, {0xFF, 0xFF, 0, 0});
    g.drawRectangle(630, 390, 100, 150, {0xFF, 0xFF, 0xFF, 0});

    while (1);
    return 0;
}