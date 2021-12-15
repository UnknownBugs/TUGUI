#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    Circle c1(150, 150, 100), c2(500, 500, 200, true);

    pe.setColor(Color(RED, BLUE));
    pe.setColorGradient(200 * 200 * 3.2);

    pe(c1);
    pe(c2);

    while(1);
    
    return 0;
}