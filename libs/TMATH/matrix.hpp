/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-29 09:44:36 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-12-02 01:05:16
 */

#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

// TDEBUG
#include <tdebug.hpp>
// std
#include <initializer_list.hpp>
// TMATH
#include <vector.hpp>
#include <homocoordinates.hpp>

namespace TMATH {
    template<typename, unsigned int, unsigned int> class Matrix;

    template<typename T, unsigned int N, unsigned int M>
    Matrix<T, N, M> operator+(const Matrix<T, N, M> &m1, const Matrix<T, N, M> &m2) {
        Matrix<T, N, M> temp;
        for (int i = 0; i < N; i++) {
            temp[i] = m1[i] + m2[i];
        }
        return temp;
    }

    template<typename T, unsigned int N, unsigned int M>
    Matrix<T, N, M> operator-(const Matrix<T, N, M> &m1, const Matrix<T, N, M> &m2) {
        Matrix<T, N, M> temp;
        for (int i = 0; i < N; i++) {
            temp[i] = m1[i] - m2[i];
        }
        return temp;
    }

    template<typename T, unsigned int N, unsigned int M>
    HomoCoordinates<N> operator*(const Matrix<T, N, M> &m, const HomoCoordinates<M> &hc) {
        HomoCoordinates<N> temp;
        for (unsigned int i = 0; i < N; i++) {
            temp[i] = m[i] * hc;
        }
        return temp;
    }

    template<typename T, unsigned int N, unsigned int M>
    Vector<T, N> operator*(const Matrix<T, N, M> &m, const Vector<T, M> &v) {
        Vector<T, N> temp;
        for (int i = 0; i < N; i++) {
            temp[i] = m[i] * v;
        }
        return temp;
    }

    template<typename T, unsigned int N, unsigned int M, unsigned int X>
    Matrix<T, N, X> operator*(const Matrix<T, N, M> &m1, const Matrix<T, M, X> &m2) {
        Matrix<T, N, X> temp;
        auto m2T = m2.transpose();

        for (unsigned int i = 0; i < N; i++) {
            for (unsigned int j = 0; j < X; j++) {
                temp[i][j] = m1[i] * m2T[j];
            }
        }
        return temp;
    }

template<typename T, unsigned int N = 1, unsigned int M = 1>
class Matrix {
private:
/*
    friend Vector<T, N> operator+<T, N, M>(const Matrix &, const Matrix &);
    friend Vector<T, N> operator-<T, N, M>(const Matrix &, const Matrix &);
    friend Vector<T, N> operator*<T, N, M>(const Matrix &, const Vector<T, M> &);
*/
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
        for (unsigned int i = 0; i < N; i++) {
            for (unsigned int j = 0; j < M; j++) {
                __mVector[i][j] = 0; // todo: temp design
            }
        }
    }    

    Matrix(const std::initializer_list<Vector<T, M> > &vecList) {
        if (vecList.size() > N) TDEBUG::crash();

        for (unsigned int i = 0; i < vecList.size() && vecList.begin() + i != vecList.end(); i++) {
            __mVector[i] = *(vecList.begin() + i);
        }

    }

    unsigned int getRow() const {
        return N;
    }

    unsigned int getCol() const {
        return M;
    }

    Matrix<T, M, N> transpose() const {
        Matrix<T, M, N> temp;

        for (unsigned int i = 0; i < M; i++) {
            for (unsigned int j = 0; j < N; j++) {
                temp[i][j] = __mVector[j][i];
            }
        }
        return temp;
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