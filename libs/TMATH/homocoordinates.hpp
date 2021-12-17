#ifndef __HOMOCOORDINATES_HPP__
#define __HOMOCOORDINATES_HPP__

#include <vector.hpp>

namespace TMATH {

template <unsigned int N = 3>
class HomoCoordinates : public Vector<double, N> {
public:

    HomoCoordinates() {

    }

    HomoCoordinates(const Vector<double, N> &v) {
        *this = v;
    }

    template <typename... Targs>
    HomoCoordinates(const double n, const Targs... ns) : Vector<double, N>(n, ns...) {
        if ((*this)[N -1] != 0) {
            for (unsigned int i = 0; i < N; i++) {
                (*this)[i] = (*this)[i] / (*this)[N -1];
            }
        }
    }

};  // HomoCoordiantes

};  // TMATH

#endif // __HOMOCOORDINATES_HPP__