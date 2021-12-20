#ifndef __TRANSFORM_ENGINE_HPP__
#define __TRANSFORM_ENGINE_HPP__

#include <homocoordinates.hpp>

#include <core/transform/TransformInterface.hpp>
#include <core/transform/impl/AffineTransform.hpp>

namespace TUGUI {

class TransformEngine {
public:
    TransformEngine() = default;

    void operator()(TransformInterface &trans) {
        trans.transform(*this);
    }

    void affineTransform(TMATH::HomoCoordinates<2 + 1> &hc) const {
        __mTransOrigin(hc);
        __mAffineTransform(hc);
        __mTransBack(hc);
    }

    void addTransformer(TRANSFORM::AffineTransform<2 + 1> at) {
        __mAffineTransform = at;
    }

    void setScale(uint32_t scale) {
        __mAffineTransform.add(TRANSFORM::Scale<2 + 1>(scale));
    }

    void setRotation(uint32_t angle) {
        __mAffineTransform.add(TRANSFORM::Rotation<2 + 1>(angle));
    }

    void setPoint(int x, int y) {
        // todo: wait optimize
        __mTransBack.set({ x, y });
        __mTransOrigin.set({ -x, -y });
    }


public: // static
    template <unsigned int _N = 1>
    static void scale(TMATH::HomoCoordinates<2 + 1> &hc) {
        typename TRANSFORM::Scale<2 + 1> s(_N);
        s(hc);
    }

    template <int _X = 0, int _Y = 0>
    static void translation(TMATH::HomoCoordinates<2 + 1> &hc) {
        typename TRANSFORM::Translation<2 + 1> t {_X, _Y};
        t(hc);
    }

    template <unsigned int _D = 1>
    static void rotation(TMATH::HomoCoordinates<2 + 1> &hc) {
        typename TRANSFORM::Rotation<2 + 1> r(_D);
        r(hc);
    }

private:
    TRANSFORM::Translation<2 + 1> __mTransOrigin, __mTransBack;
    TRANSFORM::AffineTransform<2 + 1> __mAffineTransform;

}; // TransformEngine

}; // TUGUI


#endif // __TRANSFORM_ENGINE_HPP__