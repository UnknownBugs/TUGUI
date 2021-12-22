#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    TransformEngine te;

    te.setScale(2);

    Line l1(50, 50, 100, 100), l2(100, 50, 150, 100), l3(400, 401, 410, 411);

    pe.setColor(Color(BLUE, GREEN));
    pe.setColorGradient(50);

    pe(l1);

    te.initRefSystem(100, 50);
    te(l2);

    pe(l2);

    // config transformEngine
    te.initRefSystem(400, 401);
    te.setRotation(5);   // set rotation 35 degree
    te.addScale(1.05);   // add scale 1.1 base on rotation 35 degree

    uint8_t rTimes = 72;

    for (uint8_t i = 0; i < rTimes; i++) {
        pe(l3);
        te(l3);
    }

    while(true) {
        
    };
    
    return 0;
}