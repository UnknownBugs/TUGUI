/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-29 09:44:36 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-29 10:19:22
 */
#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <tdebug.hpp>

#include <vector.hpp>

namespace TMATH {

template<typename T, unsigned int N = 1, unsigned int M = 1>
class Matrix {
public:

    enum class RC {
        ROW = false,
        COL = true,
    };

public:

    Matrix() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                __mVector[i][j] = 0; // todo: temp design
            }
        }
    }    

    template <typename... Targs>
    Matrix(const Vector<T, M> &v /*, const Targs... vs */) {
        int pos = 0;
        //init(pos, vs...);
    }

    auto & operator[](const unsigned int index) {
        if (index >= N) TDEBUG::crash();
        return __mVector[index];
    }

private:

    Vector<T, M> __mVector[N];

    template <typename... Targs>
    void init(unsigned int pos, const Vector<T, M> &v, const Targs & ...vs) {
        __mVector[pos] = v;
        init(pos + 1, vs...);
    }

    void init(unsigned int pos, const Vector<T, M> &v) {
        if (N - 1 != pos) TDEBUG::crash();
        __mVector[pos] = v;
    }

    Vector<T, M> & getRow(const unsigned int index) {
        if (index >= M) TDEBUG::crash();
            Vector<T, M> ans;
            for (int i = 0; i < ans.size(); i++) {
                ans[i] = __mVector[i][index];
            }
            return ans;
    }

}; // Matrix

}; // TMATH

#endif