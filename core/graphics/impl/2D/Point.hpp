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

    Point(const TMATH::Vector<double, 2 + 1> &hc) {
        // TODO: *this = hc is Error ?
        // becase of HomoCoordinates haven't assignment operator
        for (uint32_t i = 0; i < 3; i++) {
            (*this)[i] = hc[i];
        }
    }

    void paint(PaintEngine &pe) const {
        pe.drawPixel((*this)[0], (*this)[1]);
    }
}; // Point
}; // TUGUI

#endif //__POINT__HPP__TUGUI