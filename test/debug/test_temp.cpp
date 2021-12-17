#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    TransformEngine te;

    te.setScale(2);

    Line l1(50, 50, 300, 300), l2(100, 50, 350, 300);

    pe.setColor(Color(BLUE, GREEN));

    pe.setColorGradient(250);

    pe(l1);

    te(l2);

    pe(l2);

    while(1);
    
    return 0;
}