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
        __mAffineTransform(hc);
    }

    void setTransformer(TRANSFORM::AffineTransform<2 + 1> at) {
        __mAffineTransform = at;
    }

    void setScale(uint32_t scale) {
        __mAffineTransform.add(TRANSFORM::Scale<2 + 1>(scale));
    }

private:
    TRANSFORM::AffineTransform<2 + 1> __mAffineTransform;

}; // TransformEngine

}; // TUGUI


#endif // __TRANSFORM_ENGINE_HPP__