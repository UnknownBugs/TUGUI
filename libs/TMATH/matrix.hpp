/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-29 09:44:36 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-30 12:24:31
 */

#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

// TDEBUG
#include <tdebug.hpp>
// std
#include <initializer_list.hpp>

#include <vector.hpp>

namespace TMATH {

template<typename T, unsigned int N = 1, unsigned int M = 1>
class Matrix {

public: // Type

    enum class RC {
        ROW = false,
        COL = true,
    };

public: // Operater
    Vector<T, M> & operator[](const unsigned int index) {
        if (index >= N) TDEBUG::crash();
        return __mVector[index];
    }

    Vector<T, M> operator[](const unsigned int index) const {
        if (index >= N) TDEBUG::crash();
        return __mVector[index];
    }

public:

    Matrix() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                __mVector[i][j] = 0; // todo: temp design
            }
        }
    }    

    Matrix(const std::initializer_list<Vector<T, M> > &vecList) {
        if (vecList.size() > N) TDEBUG::crash();

        for (int i = 0; i < vecList.size() && vecList.begin() + i != vecList.end(); i++) {
            __mVector[i] = *(vecList.begin() + i);
        }

    }

    unsigned int getRow() const {
        return N;
    }

    unsigned int getCol() const {
        return M;
    }

private:

    Vector<T, M> __mVector[N];

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