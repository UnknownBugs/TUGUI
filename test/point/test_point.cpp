#include <new_tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    Point p1(50, 50), p2(300, 200), p3(0XFF + 0XFF, 0XFF + 0XFF);
    Line l1(p1, p2), l2(p2, p3);

    Color c(RED, GREEN);

    pe(l1);

    pe.setColor(c);

    pe(l2);

    int i = 0;
    while (i < 500) {
        PaintBase::drawPixel(50, 50 + i, c.getGradientRgb(i, 500));
        i++;
    }

    while(1);
    
    return 0;

}