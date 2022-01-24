#include <iostream>

#include <tugui.hpp>
//#include <initializer_list>

using namespace TUGUI;

namespace GRAPHICS_TEST {

PaintEngine pe;


inline void line() {
    Line l1(5, 5, 5, 100), l2(5, 5, 100, 5);

    pe.setColor(VIOLET); pe(l1);
    pe.setColor(BLUE); pe(l2);

    pe.setColor(WHITE); pe(Line(5, 5, 100, 100));
    pe.setColor(GREEN); pe(Line(66, 88, 5, 5));
    pe.setColor(CYAN); pe(Line(88, 66, 5, 5));
}

inline void rectangle() {
    Rectangle rect1(100, 100, 50, 50), rect2(100, 100, 100, 70);
    pe.setColor(RED); pe(rect1);
    pe.setColor(GREEN); pe(rect2);
}

inline void circle() {

}

inline void triangle() {

}

};

int TUGUI_MAIN() {
    
    TUGUI::PLATFORM::init(nullptr);
    
    GRAPHICS_TEST::line();
    std::cin.get();
    
    GRAPHICS_TEST::rectangle();
    std::cin.get();
    
    //std::cout << "test over" << std::endl;
    
    return 0;
}