/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:12:19 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-21 00:51:26
 */

#ifndef __FUNCTION_HPP__TMATH
#define __FUNCTION_HPP__TMATH

#define PI 3.14159265359
/**
 * taylor:
 *  x - x^3 / 3! + x^5 / 5! - x^7 / 7! + x^9 / 9! + ...
 * 
*/
#define TAYLOR_SIN(X) \
x - \
x / 3 * x / 2 * x + \
x / 5 * x / 4 * x / 3 * x / 2 * x - \
x / 7 * x / 6 * x / 5 * x / 4 * x / 3 * x / 2 * x + \
x / 9 * x / 8 * x / 7 * x / 6 * x / 5 * x / 4 * x / 3 * x / 2 * x
//....................................................................

double __sinTable[360 + 1] = { 0 };


namespace TMATH {

namespace FUNCTION {
    static double sinDegree(int degree) {
        double sign = 1;
        if (degree < 0) {
            sign = -1;
            degree = -degree;
        }

        degree = degree <= 360 ? degree : degree % 360;
        double x = degree * PI / 180;
        
        if ( __sinTable[degree] == 0) {
            __sinTable[degree] = TAYLOR_SIN(x);
            //std::cout << "[TMATH]: sin_degree: debug" << std::endl;
        }
        
        return __sinTable[degree] * sign;
    }

    static double cosDegree(int degree) {
        return sinDegree(90 - degree);
    }
}; // namespace FUNCTION

};  // namespace TMATH

#endif  /* __FUNCTION_HPP__TMATH */