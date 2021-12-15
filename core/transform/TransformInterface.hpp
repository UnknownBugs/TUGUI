#ifndef __TRANSFORM_INTERFACE_HPP__
#define __TRANSFORM_INTERFACE_HPP__

class TransformInterface {

public:
    virtual void transform(const TransformInterface &) = 0;

}; // TransformInterface

#endif // __TRANSFORM_INTERFACE_HPP__