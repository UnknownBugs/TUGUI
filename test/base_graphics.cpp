#include <iostream>

#include <tugui.hpp>
//#include <initializer_list>

using namespace TUGUI;

namespace GRAPHICS_TEST {

PaintEngine pe;


inline void line() {
    Line l1(5, 5, 5, 200), l2(5, 5, 200, 5);

    pe.setColor(VIOLET); pe(l1);
    pe.setColor(BLUE); pe(l2);

    pe.setColor(WHITE); pe(Line(5, 5, 200, 200));
    pe.setColor(GREEN); pe(Line(166, 188, 5, 5));
    pe.setColor(CYAN); pe(Line(188, 166, 5, 5));
}

inline void rectangle() {
    Rectangle rect1(200, 200, 150, 150), rect2(200, 200, 200, 170);
    pe.setColor(RED); pe(rect1);
    pe.setColor(GREEN); pe(rect2);
}

inline void circle() {
    Circle c(650, 370, 250);
    pe.setColor(VIOLET); pe(c);
}

inline void triangle() {
    Triangle t(650, 370, 1400, 700, 800, 900);
    pe.setColor(ORANGE); pe(t);
}

};

int TUGUI_MAIN() {
    
    TUGUI::PLATFORM::init(nullptr);
    
    GRAPHICS_TEST::line();
    std::cin.get();
    
    GRAPHICS_TEST::rectangle();
    std::cin.get();
    
    GRAPHICS_TEST::circle();
    std::cin.get();

    GRAPHICS_TEST::triangle();
    std::cin.get();
    
    //std::cout << "test over" << std::endl;
    
    return 0;
}
