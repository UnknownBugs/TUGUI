#include <iostream>
#include <ostream>

#include <homocoordinates.hpp>

template<typename T, unsigned int N>
std::ostream & operator<<(std::ostream &os, const TMATH::HomoCoordinates<T, N> &hc) {
    os << "(";
    for (int i = 0; i < hc.size() - 1; i++) {
        os << hc[i] << ", ";
    }
    return os << hc[hc.size() - 1] << ")" << std::endl;
}

int main() {
    {
        TMATH::HomoCoordinates<int, 4> a(1, 2, 3, 1), b(1, 3, 0, 3);
        
        std::cout << a << b << std::endl;
    }
    
    TMATH::HomoCoordinates<double, 5> a(1, 2, 3, 1, 4), b(1, 3, 0, 3, 0);

    std::cout << a << b << std::endl;

    return 0;
}