#ifndef __TRANSFORMATION_HPP__
#define __TRANSFORMATION_HPP__

#include <homocoordinates.hpp>

namespace TUGUI {

namespace Transform {

class AffineTransform {
public:
    virtual void operate()() {

    }

    virtual void add(const AffineTransform &at) {

    }
}; // AffineTransform

class Scale : public AffineTransform {
public:
    void operate()() {

    }

    void add(const Scale &s) {
    
    }

}; // Scale

}; // Transform

}; // TUGUI

#endif // __TRANSFORMATION_HPP__