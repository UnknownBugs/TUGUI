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
    /*
    virtual TMATH::HomoCoordinates<R>
    operator()(const TMATH::HomoCoordinates<R> &hc) const {
        auto ans = _mTransformMatrix * hc;
        return ans;
    }
    */

    virtual void
    operator()(TMATH::HomoCoordinates<R> &hc) const {
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

    Scale(uint32_t scale = 1) {
        for (unsigned int i = 0; i < R - 1; i++) {
            this->_mTransformMatrix[i][i] = scale;
        }
    };

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



template <unsigned int R>
class Translation : public AffineTransform<R> {

public:

    Translation() = default;

    Translation(const TMATH::Matrix<double, R, R> &m) {
        for (unsigned int i = 0; i < R - 1; i++) {
            this->_mTransformMatrix[i][R - 1] = m[i][R - 1];
        }
    }

    Translation(const std::initializer_list<int> &mList) {
        init(mList);
    }

    Translation(const TMATH::Vector<int, R - 1> &mVec) {
        init(mVec);
    }

    explicit Translation(const std::initializer_list<TMATH::Vector<double, R>> &vecList) 
        : Translation { TMATH::Matrix<double, R, R>(vecList) } {
        ASSERT(vecList.size() == R);
    }

    void add(const Translation &s) {
        this->_mTransformMatrix = s._mTransformMatrix * this->_mTransformMatrix;
    }

    void set(const std::initializer_list<int> &mList) {
        init(mList);
    }

    void set(const TMATH::Vector<int, R - 1> &mVec) {
        init(mVec);
    }

private:
    
    void init(const std::initializer_list<int> &mList) {
        ASSERT(mList.size() == R - 1);
        for (unsigned int i = 0; i < R - 1; i++) {
            this->_mTransformMatrix[i][R - 1] = *(mList.begin() + i);
        }
    }

    void init(const TMATH::Vector<int, R - 1> &mVec) {
        for (unsigned int i = 0; i < R - 1; i++) {
            this->_mTransformMatrix[i][R - 1] = mVec[i];
        }
    }

}; // Translation



template <unsigned int R>
class Rotation : public AffineTransform<R> {
public:
    TMATH::HomoCoordinates<R>
    operator()(const TMATH::HomoCoordinates<R> &hc) const override {
        __mTransOrigin(hc);
        auto ans = this->_mTransformMatrix * hc;
        __mTransBack(ans);
        return ans;
    }

    void operator()(TMATH::HomoCoordinates<R> &hc) override {
        __mTransOrigin(hc);
        hc = this->_mTransformMatrix * hc;
        __mTransBack(hc);
    }

public:

    Rotation() = default;

    Rotation(const TMATH::Matrix<double, R, R> &m) {
        for (unsigned int i = 0; i < R - 1; i++) {
            for (unsigned int j = 0; j < R - 1; j++) {
                ASSERT(MUTILS::abs(m[i][j]) <= 1);
                this->_mTransformMatrix[i][j] = m[i][j];
            }
        }
    }

    explicit Rotation(const std::initializer_list<TMATH::Vector<double, R>> &vecList) 
        : Rotation { TMATH::Matrix<double, R, R>(vecList) } {
        ASSERT(vecList.size() == R);
    }

    void add(const Rotation &s) {
        this->_mTransformMatrix = s._mTransformMatrix * this->_mTransformMatrix;
    }

    void setPoint(const TMATH::HomoCoordinates<R> &point) {
        // todo: wait optimize
        __mTransBack.set({ (int)point[0], (int)point[1] });
        __mTransOrigin.set({ -(int)point[0], -(int)point[1] });
    }

private:

    Translation<R> __mTransOrigin, __mTransBack;

}; // Rotation

}; // TRANSFORM

}; // TUGUI

#endif // __TRANSFORMATION_HPP__