#include <iostream>
#include <ostream>

#include <homocoordinates.hpp>

template<unsigned int N>
std::ostream & operator<<(std::ostream &os, const TMATH::HomoCoordinates<N> &hc) {
    os << "(";
    for (int i = 0; i < hc.size() - 1; i++) {
        os << hc[i] << ", ";
    }
    return os << hc[hc.size() - 1] << ")" << std::endl;
}

int main() {
    {
        TMATH::HomoCoordinates<4> a(1, 2, 3, 1), b(1, 3, 0, 3);
        
        std::cout << a << b << std::endl;
    }
    
    TMATH::HomoCoordinates<5> a(1, 2, 3, 1, 4), b(1, 3, 0, 3, 0);

    std::cout << a << b << std::endl;

    return 0;
}