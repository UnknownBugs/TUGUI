<<<<<<< HEAD
#include <new_tugui.hpp>
=======
#include <tugui.hpp>
>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79

using namespace TUGUI;

int tuguiMain() {

    PaintEngine pe;

    Point p1(50, 50), p2(300, 200), p3(0XFF + 0XFF, 0XFF + 0XFF);
    Line l1(p1, p2), l2(p2, p3);

<<<<<<< HEAD
    Color c(RED, GREEN);

    pe(l1);

    pe.setColor(c);

    pe(l2);

    int i = 0;
    while (i < 500) {
        PaintEngine::PaintBase::drawPixel(50, 50 + i, c.getGradientRgb(i, 500));
        pe.drawPixel(50 + 2, 51 + i);
        i++;
    }

    while(1);
    
    return 0;

=======
    pe(l1);
    pe(l2);

    while(1);
    
    return 0;
>>>>>>> 7fb5bf50fe8ae2a4b6c8a9129e08439410689b79
}