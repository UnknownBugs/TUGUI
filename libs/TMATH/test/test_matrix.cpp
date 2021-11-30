#include <iostream>

#include <vector.hpp>
#include <matrix.hpp>

#include <initializer_list.hpp>

template<typename T>
void printM(const T &m) {
    for (int i = 0; i < m.getRow(); i++) {
        for (int j = 0; j < m.getCol(); j++) {
            std::cout << (m[i][j]) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {

    {
        TMATH::Vector<double, 3> a(1), b {2, 2, 2};
        TMATH::Matrix<double, 3, 3> m {a, b, {9, 9, 6}};

        m[1][1] = 8;
        
        printM(m);
    }

    std::cout << "----------------" << std::endl;
    
    TMATH::Matrix<double, 4, 3> m {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {6, 6, 6}
    };

    m[1][1] = 0;

    printM(m);

    return 0;
}