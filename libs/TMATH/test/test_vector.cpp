#include <iostream>
#include <vector.hpp>

int main() {
    TMATH::Vector<int, 3> a(1), b {2, 2, 2};
    for (int i = 0; i < a.size(); i++) {
        std::cout << "a = " << a[i] << ", b = " << b[i] << std::endl;
    }
    auto c = a + b;
    c[1] = 4;
    auto d = TMATH::cross(a, c);
    std::cout << "\nc = a + b : d = a x c\n" << std::endl;
    for (int i = 0; i < a.size(); i++) {
        std::cout << "c = " << c[i] << ", d = " << d[i] << std::endl;
    }
    return 0;
}