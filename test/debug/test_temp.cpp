#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    TransformEngine te;

    te.setScale(2);

    Line l1(50, 50, 100, 100), l2(100, 50, 150, 100), l3(400, 401, 501, 501);

    pe.setColor(Color(BLUE, GREEN));
    pe.setColorGradient(50);

    pe(l1);

    te.setPoint(100, 50);
    te(l2);

    pe(l2);

    te.setPoint(400, 401);
    te.setRotation(35);
    pe.setColor(Color(RED, VIOLET));
    pe.setColorGradient(50);

    uint8_t rTimes = 50;

    for (uint8_t i = 0; i < rTimes; i++) {
        pe(l3);
        te(l3);
    }

    while(true) {
        
    };
    
    return 0;
}