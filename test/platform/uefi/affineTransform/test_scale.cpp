#include <tugui.hpp>

using namespace TUGUI;


int tuguiMain() {

    TMATH::HomoCoordinates<3> rectWH { 100, 100, 1 };
    // alloc memory
    Graphics *g = new Graphics();
    // test
    g->drawRectangle(100, 100, rectWH[0], rectWH[1], PIXEL_RED); // 1

    TMATH::Matrix<double, 3, 3> m {
        {1.5, 0, 0},
        {0, 2, 0},
        {0, 0, 1}
    };

    rectWH = m * rectWH;

    g->drawRectangle(100, 100, rectWH[0], rectWH[1], {0x33, 0x44, 0x55, 0}); // 2

    TRANSFORM::Scale<3> scale { m };
    
    scale(rectWH);

    g->drawRectangle(100, 100, rectWH[0], rectWH[1], {0x66, 077, 0x88, 0}); // 3

    // free memory
    delete g;

    while (1)
        ;

    return 0;

}