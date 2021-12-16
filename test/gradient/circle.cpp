#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;


    Circle c(500, 500, 200, true);

    pe.setColor(Color(BLACK, RED));

    pe.setColorGradient(3.15 * 200 * 200);

    pe(c);

    while(1);
    
    return 0;
}