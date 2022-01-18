#include <tugui.hpp>

using namespace TUGUI;

int tuguiMain() {

    // alloc memory
    PaintEngine *pe = new PaintEngine();
    // test
    for (int i = 0; i < 100; i++) {
        pe->drawPixel(100, 100);
    }
    // free memory
    delete pe;

    while(1);
    
    return 0;

}