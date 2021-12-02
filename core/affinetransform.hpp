#ifndef __TRANSFORMATION_HPP__
#define __TRANSFORMATION_HPP__

#include <initializer_list.hpp>

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
        for (int i = 0; i < R; i++) {
            _mTransformMatrix[i][i] = 1; // init E
        }
    }


    virtual void add(const AffineTransform &atM) {
        _mTransformMatrix = atM * _mTransformMatrix;
    }

protected:
    TMATH::Matrix<double, R, R> _mTransformMatrix;

}; // AffineTransform

template <unsigned int R>
class Scale : public AffineTransform<R> {

public:

    Scale() = default;

    Scale(const Matrix<double, R, R> &m) {
        init(m);
    }

    Scale(const Matrix<double, R - 1, R - 1> &m) {
        init(m);
    }

    void add(const Scale &s) {
        _mTransformMatrix = s._mTransformMatrix * _mTransformMatrix;
    }

private:

    template<typename _M>
    void init(const _M & m) {
        for (int i = 0; i < R - 1; i++) {
            _mTransformMatrix[i][i] = m[i][i];
        }
    }

}; // Scale

}; // TRANSFORM

}; // TUGUI

#endif // __TRANSFORMATION_HPP__