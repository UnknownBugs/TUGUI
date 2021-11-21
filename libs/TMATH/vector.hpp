/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:11:28 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-21 17:08:04
 */

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

namespace TMATH {
    template<typename, unsigned int>
    class Vector;

    template<typename T, unsigned int N>
    Vector<T, N> operator+(const Vector<T, N> &v1, const Vector<T, N> &v2) {
        Vector<T, N> temp;
        for (int i = 0; i < N; i++) {
            temp[i] = v1.c[i] + v2.c[i];
        }
        return temp;
    }

    template<typename T, unsigned int N>
    Vector<T, N> operator-(const Vector<T, N> &v1, const Vector<T, N> &v2) {
        Vector<T, N> temp;
        for (int i = 0; i < N; i++) {
            temp[i] = v1.c[i] - v2.c[i];
        }
        return temp;
    }

    template<typename T, unsigned int N>
    T operator*(const Vector<T, N> &v1, const Vector<T, N> &v2) {
        T temp;
        for (int i = 0; i < N; i++) {
            temp += v1.c[i] * v2.c[i];
        }
        return temp;
    }

    template<typename T>
    Vector<T, 3> cross(const Vector<T, 3> &v1, const Vector<T, 3> &v2) {
        Vector<T, 3> temp;
        temp[0] = v1.c[1] * v2.c[2] - v1.c[2] * v2.c[1];      //  | i  j  k |
        temp[1] = v1.c[2] * v2.c[0] - v1.c[0] * v2.c[2];      //  | x  y  z | -> c
        temp[2] = v1.c[0] * v2.c[1] - v1.c[1] * v2.c[0];      //  | a  b  c | -> obj.c
        return temp;
    }

template<typename T, unsigned int N>
class Vector {
private:
    friend Vector operator+<T, N>(const Vector &v1, const Vector &v2);

    friend Vector operator-<T, N>(const Vector &v1, const Vector &v2);

    friend T operator*<T, N>(const Vector &v1, const Vector &v2);
    
    friend Vector<T, 3> cross<T>(const Vector<T, 3> &v1, const Vector<T, 3> &v2);

public:

    Vector(unsigned int val = 0) {
        for (int i = 0; i < N; i++) {
            c[i] = val;
        }
    }
    
    unsigned int getDimension() const {
        return N;
    }

    unsigned int size() const {
        return N;
    }

    T & operator[](const unsigned int i) {
        if (i >= N) while(1);
        return c[i];
    }

private:
    T c[N == 0 ? 1 : N];
};  // Vector

}   // TMATH 

#endif // __VECTOR_HPP__ end