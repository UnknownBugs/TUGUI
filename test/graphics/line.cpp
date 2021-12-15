#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    Point p1(50, 50), p2(300, 200), p3(0XFF + 0XFF, 0XFF + 0XFF);
    Line l1(p1, p2), l2(p2, p3);

    pe(l1);
    pe(l2);

    while(1);
    
    return 0;
}