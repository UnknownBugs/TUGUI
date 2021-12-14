#include <new_tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    Rectangle rect1(500, 500, 200, 200, true), rect2(50, 50, 400, 300, true);

    pe.setColor(Color(RED, BLUE));
    pe.setColorGradient(40000);

    pe(rect1);
    pe(rect2);

    while(1);
    
    return 0;
}