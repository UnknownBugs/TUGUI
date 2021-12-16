#ifndef __TRANSFORM_INTERFACE_HPP__TUGUI
#define __TRANSFORM_INTERFACE_HPP__TUGUI

namespace TUGUI {

class TransformEngine;

class TransformInterface {

public:
    virtual void transform(const TransformEngine &) = 0;

}; // TransformInterface

}; // TUGUI



#endif // __TRANSFORM_INTERFACE_HPP__TUGUI