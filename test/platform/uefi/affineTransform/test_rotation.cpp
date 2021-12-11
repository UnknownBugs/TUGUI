#include <tugui.hpp>

using namespace TUGUI;



int tuguiMain() {

    TMATH::HomoCoordinates<3> a { 400, 400, 1 }, b { 450, 550, 1}, c { 350, 450, 1};
    
    TRANSFORM::Rotation<3> rotation {
        {0.965925, -0.258819,0},   //     。
        {0.258819, 0.965925, 0},   // ～15
        {0,     0,     1}
    };

    rotation.setPoint({400, 400, 1});

    uint8_t R { 20 }, G { 30 }, B { 40 };

    Graphics g;
    
    void *tevent;
    void *wait_list[1];
    unsigned long long idx;

    TUGUI::INTERFACE::gEventInterfacePtr->createEvent(EVT_TIMER , 0, (void (*)(void *, void *))NULL, NULL, &tevent);

    wait_list[0] = tevent;


    while (true) {

        TUGUI::INTERFACE::gEventInterfacePtr->setTimer(tevent, TimerRelative, 1000000);
        TUGUI::INTERFACE::gEventInterfacePtr->waitForEvent(1, wait_list, &idx);

        g.clearScreen();
        g.drawTriangle(a, b, c, {R, G, B, 0});
        rotation(a); rotation(b); rotation(c);
        R += 5; G += 66; B += 15;
    }

    return 0;

}