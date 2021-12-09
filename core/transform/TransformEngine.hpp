#ifndef __TRANSFORM_ENGINE_HPP__
#define __TRANSFORM_ENGINE_HPP__

#include <core/transform/TransformInterface.hpp>

namespace TUGUI {

class TransformEngine {
public:
    void operator()(const TransformInterface & trans) {
        trans.transform();
    }
}; // TransformEngine

}; // TUGUI


#endif // __TRANSFORM_ENGINE_HPP__