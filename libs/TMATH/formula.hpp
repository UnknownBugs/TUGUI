/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:12:19 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-21 00:51:26
 */

#ifndef __FORMULA_HPP__
#define __FORMULA_HPP__

#include <tdebug.hpp>

#define DOUBLE_MAX (1.79769e+308)

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
        if (DOUBLE_MAX == __mK) TDEBUG::crash();
        return __mK * x + __mB;
    }

    double getX(double y) const {
        if (0 == __mK) TDEBUG::crash();
        return (y - __mB) / __mK;
    }

    double getSlope() const {
        return __mK;
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
            __mK = DOUBLE_MAX; // temp method to expression inf
            __mB = x1;
            __mXY = x1;
        } else {
            __mK = (y1 - y2) / (x1 - x2);
            __mB = y1 - __mK * x1;
            if (__mK == 0) __mXY = y1;
        }
    }
};

class MonadicEquation {
private:
        
};


} // Formula
};  /* Math end */

#endif  /* __FORMULA_HPP__ end */