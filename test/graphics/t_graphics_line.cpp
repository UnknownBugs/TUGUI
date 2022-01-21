#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    {
        Point p1(50, 50), p2(50, 700), p3(700, 50);
        Line l1(p1, p2), l2(p1, p3);
        pe(l1); pe(l2);
    }
    
    {
        // 1.test line slope >= 0
        Line l1(50, 50, 700, 50), l2(50, 50, 500, 100), l3(50, 50, 400, 200), l4(300, 300, 50, 50);
        Line l5(50, 50, 200, 400), l6(50, 50, 100, 500), l7(50, 50, 50, 700);

        pe.setColor(RED); pe(l1);
        pe.setColor(ORANGE); pe(l2);
        pe.setColor(YELLOW); pe(l3);
        pe.setColor(GREEN); pe(l4);
        pe.setColor(CYAN); pe(l5);
        pe.setColor(BLUE); pe(l6);
        pe.setColor(VIOLET); pe(l7);
    }
    
    // test line slope <= 0
    Line l1(50, 700, 700, 50), l2(50, 700, 500, 100), l3(50, 700, 400, 200), l4(300, 300, 50, 700);
    Line l5(50, 700, 200, 400), l6(50, 700, 100, 500), l7(50, 700, 50, 700);

    pe.setColor(RED); pe(l1);
    pe.setColor(ORANGE); pe(l2);
    pe.setColor(YELLOW); pe(l3);
    pe.setColor(GREEN); pe(l4);
    pe.setColor(CYAN); pe(l5);
    pe.setColor(BLUE); pe(l6);
    pe.setColor(VIOLET); pe(l7);

    while(1);
    
    return 0;
}