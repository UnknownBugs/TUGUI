#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    Triangle t(80, 120, 200, 150, 400, 500, true);

    pe.setColor({GREEN, BLUE});
    pe.setColorGradient(100);

    pe(t);

    while(true);
    
    return 0;
}