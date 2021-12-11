#include <tugui.hpp>

int tuguiMain()
{

    TUGUI::Graphics g;

    g.fillTriangle(200, 500, 100, 30, 500, 400, {0xFF, 0, 0, 0});
    g.drawTriangle(500, 200, 703, 400, 300, 100, {0xFF, 0, 0, 0});

    while (1)
        ;
    // test Rect

    return 0;
}
