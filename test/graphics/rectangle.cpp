#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    Rectangle rect(50, 50, 300, 400);

    pe(rect);

    while(1);
    
    return 0;

}