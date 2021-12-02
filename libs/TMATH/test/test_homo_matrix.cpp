#include <iostream>

#define __INITIALIZER_LIST_HPP__

#include <matrix.hpp>
#include <homocoordinates.hpp>
#include <initializer_list>



template<typename T>
void printV(const T &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << "\t";
    }
    std::cout << std::endl;
}

template<typename T>
void printM(const T &m) {
    for (int i = 0; i < m.getRow(); i++) {
        for (int j = 0; j < m.getCol(); j++) {
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {

    TMATH::HomoCoordinates<3> rectPointer { 100, 100, 1};
    
    TMATH::Matrix<double, 3, 3> scale {
        {2, 0, 0},
        {0, 3, 0},
        {0, 0, 1}
    };

    auto ans = scale * rectPointer;

    printV(ans);

    return 0;
}