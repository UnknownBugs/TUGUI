#include <tugui.hpp>

using namespace TUGUI;


int tuguiMain() {

    TMATH::HomoCoordinates<3> a { 300, 300, 1 }, b { 350, 450, 1}, c { 450, 250, 1};

    Graphics g;

    g.drawTriangle(a, b, c, {0xFF, 0, 0, 0});

    TRANSFORM::Translation<3> trans { 50, 100 };

    trans(a); trans(b); trans(c);

    g.drawTriangle(a, b, c, {0, 0xFF, 0, 0});

    while (1)
        ;

    return 0;

}