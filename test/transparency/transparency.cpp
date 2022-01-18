#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;
    //PE config
    pe.setTransparency(0.5);

    Rectangle rect1(100, 100, 250, 250, true), rect2(200, 200, 250, 250, true), rect3(300, 300, 250, 250, true);

    pe.setColor(BLUE);
    pe(rect1);

    pe.setColor(RED);
    pe(rect2);

    pe.setColor(CYAN);
    pe(rect3);

    while(1);
    
    return 0;
}