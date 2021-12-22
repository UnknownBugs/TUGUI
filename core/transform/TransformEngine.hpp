#ifndef __TRANSFORM_ENGINE_HPP__
#define __TRANSFORM_ENGINE_HPP__

#include <homocoordinates.hpp>

#include <core/transform/TransformInterface.hpp>
#include <core/transform/impl/AffineTransform.hpp>

namespace TUGUI {

class TransformEngine {
public:

    void operator()(TransformInterface &trans) {
        trans.transform(*this);
    }

public:

    TransformEngine() = default;

    void affineTransform(TMATH::HomoCoordinates<2 + 1> &hc) const {
        __mTransOrigin(hc);
        __mAffineTransform(hc);
        __mTransBack(hc);
    }

    /**
     * default:
     *      (0, 0)
     *        +--------------> x
     *        |
     *        |    Screen
     *        |
     *        v
     *        y
    */

    void initRefSystem(int x, int y) {
        // todo: wait optimize
        __mTransBack.set({ x, y });
        __mTransOrigin.set({ -x, -y });
    }

    void visibleRefSystem() {
        
    }

public: // setter and adder

    void setTransformer(TRANSFORM::AffineTransform<2 + 1> at) {
        __mAffineTransform = at;
    }

    void setAffineTransformer(TRANSFORM::AffineTransform<2 + 1> at) {
        __mAffineTransform = at;
    }

    void setScale(const double &scale) {
        __mAffineTransform = TRANSFORM::Scale<2 + 1>(scale);
    }

    void setTranslation(uint32_t translation) {
        __mAffineTransform = TRANSFORM::Translation<2 + 1>(translation);
    }

    void setRotation(uint32_t angle) {
        __mAffineTransform = TRANSFORM::Rotation<2 + 1>(angle);
    }

    void addTransformer(TRANSFORM::AffineTransform<2 + 1> at) {
        __mAffineTransform.add(at);
    }

    void addAffineTransformer(TRANSFORM::AffineTransform<2 + 1> at) {
        __mAffineTransform.add(at);
    }

    void addScale(const double &scale) {
        __mAffineTransform.add(TRANSFORM::Scale<2 + 1>(scale));
    }

    void addTranslation(uint32_t translation) {
        __mAffineTransform.add(TRANSFORM::Translation<2 + 1>(translation));
    }

    void addRotation(uint32_t angle) {
        __mAffineTransform.add(TRANSFORM::Rotation<2 + 1>(angle));
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