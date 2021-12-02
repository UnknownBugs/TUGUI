#include <tugui.hpp>
#include <affinetransform.hpp>

using namespace TUGUI;

int tuguiMain() {

    TMATH::HomoCoordinates<3> rectPointer { 300, 300, 1};
    // alloc memory
    Graphics *g = new Graphics();
    // test
    g->drawRectangle(100, 100, rectPointer[0], rectPointer[1], PIXEL_RED);

    
    
    TRANSFORM::Scale<3> scale {
        TMATH::Matrix<double, 2, 2> {
            {2, 0},
            {0, 3}
        }
    };

    scale(rectPointer);
    g->drawRectangle(100, 100, rectPointer[0], rectPointer[1], PIXEL_RED);

    // free memory
    delete g;

    while (1) {
        ;
    }

    return 0;

}