#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    // alloc memory
    Graphics *g = new Graphics();
    // test
    g->drawRectangle(100, 100, 300, 300, PIXEL_RED);
    // free memory
    delete g;

    while(1);
    
    return 0;

}