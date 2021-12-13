#include <new_tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    Rectangle rect1(50, 50, 300, 400), rect2(50, 50, 400, 300);

    pe(rect1);

    pe.setColor(Color(RED, GREEN));

    pe.setColorGradient(40);

    pe(rect2);

    while(1);
    
    return 0;

}