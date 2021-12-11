#include <tugui.hpp>

int tuguiMain() {

    TUGUI::Graphics g;

    // coordinate
    g.drawXLine(50, 50, 700);
    g.drawYLine(50, 50, 700);

    // 1.test line slope >= 0
    g.drawLine(50, 50, 700, 50, {0xFF, 0, 0, 0});
    g.drawLine(50, 50, 500, 100, {0, 0xFF, 0, 0});
    g.drawLine(50, 50, 400, 200, {0, 0, 0xFF, 0});

    g.drawLine(300, 300, 50, 50, {0xFF, 0xFF, 0, 0}); // 2.test direction
    
    g.drawLine(50, 50, 200, 400, {0xFF, 0, 0xFF, 0});
    g.drawLine(50, 50, 100, 500, {0, 0xFF, 0xFF, 0});
    g.drawLine(50, 50, 50, 700, {0x66, 0x66, 0x66, 0});


    // 1.test line slope <= 0
    g.drawLine(50, 700, 700, 50, {0xFF, 0, 0, 0});
    g.drawLine(50, 700, 500, 100, {0, 0xFF, 0, 0});
    g.drawLine(50, 700, 400, 200, {0, 0, 0xFF, 0});

    g.drawLine(300, 300, 50, 700, {0xFF, 0xFF, 0, 0}); // 2.test direction
    
    g.drawLine(50, 700, 200, 400, {0xFF, 0, 0xFF, 0});
    g.drawLine(50, 700, 100, 500, {0, 0xFF, 0xFF, 0});
    g.drawLine(50, 700, 50, 700, {0x66, 0x66, 0x66, 0});

    while (1);
}