#ifndef __HOMOCOORDINATES_HPP__
#define __HOMOCOORDINATES_HPP__

#include <vector.hpp>

namespace TMATH {

template <typename T, unsigned int N = 3>
class HomoCoordinates : public Vector<T, N> {
public:
    HomoCoordinates() {

    }

    template <typename... Targs>
    HomoCoordinates(const T n, const Targs... ns) : Vector<T, N>(0) {
        int pos = 0;
        init(pos, n, ns...);
    }

private:

    template <typename... Targs>
    void init(unsigned int pos, const T n, const Targs... ns) {
        (*this)[pos] = n;
        init(pos + 1, ns...);
    }

    void init(unsigned int pos, const T n) {
        (*this)[pos] = n;
        if (n != 0) {
            for (int i = 0; i < N; i++) {
                (*this)[i] = (*this)[i] / n;
            }
        }
    }

};  // HomoCoordiantes

};  // TMATH

#endif // __HOMOCOORDINATES_HPP__