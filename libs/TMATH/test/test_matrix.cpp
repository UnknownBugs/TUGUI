#include <iostream>

#define __INITIALIZER_LIST_HPP__

#include <vector.hpp>
#include <matrix.hpp>

#include <initializer_list>

template<typename T>
void printV(const T &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << "\t";
    }
    std::cout << std::endl;
}

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

    //{
        TMATH::Vector<double, 3> a(1), b {2, 2, 2};
        TMATH::Matrix<double, 4, 3> m1 {a, b, {9, 9, 6}, 0};

        m1[1][1] = 8;
        std::cout << "\n-------m1---------" << std::endl << std::endl;
        printM(m1);
    //}

    std::cout << "\n-------m2---------" << std::endl << std::endl;
    
    TMATH::Matrix<double, 4, 3> m2 {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {6, 6, 6}
    };

    printM(m2);

    std::cout << "\n--------m2T--------" << std::endl << std::endl;
    // add
    printM(m2.transpose());

    std::cout << "\n--------m1 + m2--------" << std::endl << std::endl;
    // add
    printM(m1 + m2);

    std::cout << "\n--------m1 - m2--------" << std::endl << std::endl;
    // mius
    printM(m1 - m2);

    std::cout << "\n--------m2 * b--------" << std::endl << std::endl;
    // matix * vector
    printV(m2 * b);

    std::cout << "\n--------m2 * m2T--------" << std::endl << std::endl;
    // matix * vector
    printM(m2 * m2.transpose());

    return 0;
}