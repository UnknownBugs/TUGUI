/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:15:18 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-17 01:05:46
 * 
 * array
 * 
 */

#ifndef __ARRAY__HPP__
#define __ARRAY__HPP__

namespace MUTILS {

template <typename T, unsigned int N>
class Array {

public:

    T & operator[](const unsigned int i) {
        if (i >= N) while(1);
        return c[i];
    }

    T operator[](const unsigned int i) const {
        if (i >= N) while(1);
        return c[i];
    }

public:

    Array() = default;

    Array(const T &value) {
        for (unsigned int i = 0; i < N; i++) {
            c[i] = value;
        }
    }

    unsigned int size() const {
        return N;
    }

private:

    T c[N == 0 ? 1 : N];

}; // Array

}; /* MUTILS end */

#endif // __ARRAY__HPP__