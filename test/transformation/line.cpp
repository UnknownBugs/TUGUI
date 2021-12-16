#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    TransformEngine te;

    te.setScale(2);

    Line line(50, 50, 200, 300);

    pe.setColor(Color(BLUE, GREEN));

    pe.setColorGradient(100);

    pe(line);

    //te(line);

    //pe(line);

    while(1);
    
    return 0;
}