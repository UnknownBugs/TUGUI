#ifndef __POINT__HPP__TUGUI
#define __POINT__HPP__TUGUI

#include <homocoordinates.hpp>
#include <initializer_list.hpp>

#include <core/painter/PaintInterface.hpp>
#include <core/painter/impl/colors/color.hpp>

namespace TUGUI {

class Point : public PaintInterface, public TMATH::HomoCoordinates<2 + 1> {
public:
    Point(uint32_t x, uint32_t y) : TMATH::HomoCoordinates<2 + 1>(x, y, 1) { }

    Point(const TMATH::HomoCoordinates<2 + 1> &hc) {
        *this = hc;
    }

    void paint(PaintEngine &pe) const {
        pe.setColorGradient(1);
        pe.drawPixel((*this)[0], (*this)[1]);
    }
}; // Point
}; // TUGUI

#endif //__POINT__HPP__TUGUI