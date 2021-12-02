#ifndef __TRANSFORMATION_HPP__
#define __TRANSFORMATION_HPP__

#include <initializer_list.hpp>

#include <assert.hpp>

#include <homocoordinates.hpp>
#include <matrix.hpp>

namespace TUGUI {

namespace TRANSFORM {

template <unsigned int R>
class AffineTransform {

public:
    virtual TMATH::HomoCoordinates<R>
    operator()(const TMATH::HomoCoordinates<R> &hc) const {
        auto ans = _mTransformMatrix * hc;
        return ans;
    }

    virtual void
    operator()(TMATH::HomoCoordinates<R> &hc) {
        hc = _mTransformMatrix * hc;
    }

public:

    AffineTransform() {
        for (unsigned int i = 0; i < R; i++) {
            _mTransformMatrix[i][i] = 1; // init E
        }
    }


    virtual void add(const AffineTransform &atM) {
        _mTransformMatrix = _mTransformMatrix * atM._mTransformMatrix;
    }

protected:
    TMATH::Matrix<double, R, R> _mTransformMatrix;

}; // AffineTransform

template <unsigned int R>
class Scale : public AffineTransform<R> {

public:

    Scale() = default;

    Scale(const TMATH::Matrix<double, R, R> &m) {
         for (unsigned int i = 0; i < R - 1; i++) {
            this->_mTransformMatrix[i][i] = m[i][i];
        }
    }

    explicit Scale(const std::initializer_list<TMATH::Vector<double, R>> &vecList) 
        : Scale { TMATH::Matrix<double, R, R>(vecList) } {
        ASSERT(vecList.size() == R);
    }

    void add(const Scale &s) {
        this->_mTransformMatrix = s._mTransformMatrix * this->_mTransformMatrix;
    }

}; // Scale

}; // TRANSFORM

}; // TUGUI

#endif // __TRANSFORMATION_HPP__