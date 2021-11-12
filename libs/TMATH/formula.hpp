#ifndef __FORMULA_HPP__
#define __FORMULA_HPP__

#include "../TDEBUG/tdebug.hpp"

namespace Math {
namespace Formula {

class LinearEquation {

public:

    LinearEquation() = default;

    LinearEquation(double x1, double y1, double x2, double y2) {
        computer(x1, y1, x2, y2);
    }

    void set(double x1, double y1, double x2, double y2) {
        computer(x1, y1, x2, y2);
    }

    double getY(double x) const {
        if (-0.01 == __mK) TDEBUG::crash();
        return __mK * x + __mB;
    }

    double getX(double y) const {
        if (0 == __mK) TDEBUG::crash();
        return (y - __mB) / __mK;
    }

private:
    double __mK;
    double __mB;
    double __mXY;
    /**
     * 
     * computer value of __mK and b
     * 
    */
    void computer(double x1, double y1, double x2, double y2) {
        if (x1 == x2) {
            __mK = -0.01;
            __mB = x1;
            __mXY = x1;
        } else {
            __mK = (y1 - y2) / (x1 - x2);
            __mB = y1 - __mK * x1;
            if (__mK == 0) __mXY = y1;
        }
    }
};

}
};  /* Math end */

#endif  /* __FORMULA_HPP__ end */