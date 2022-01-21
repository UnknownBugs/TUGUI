#ifndef __AABB_HPP__TUGUI
#define __AABB_HPP__TUGUI

#include <libs/std/initializer_list.hpp>
#include <libs/MUTILS/mutils.hpp>
#include <libs/TMATH/tmath.hpp>

namespace TUGUI {


class AABB {
public:

    AABB() = default;

    AABB(std::initializer_list<TMATH::Vector<double, 2> > points) {
        __mMax = __mMin = *(points.begin());
        for (unsigned int i = 1; i < points.size(); i++) {
            auto point = *(points.begin() + i);
            computer(point);
        }
    }

    TMATH::Vector<double, 2> getMin() {
        return __mMin;
    }

    TMATH::Vector<double, 2> getMax() {
        return __mMax;
    }

private:
    TMATH::Vector<double, 2> __mMin, __mMax;

    void computer(const TMATH::Vector<double, 2> &a) {
        for (unsigned int i = 0; i < a.size(); i++) {
            __mMin[i] = MUTILS::min(__mMin[i], a[i]);
            __mMax[i] = MUTILS::max(__mMax[i], a[i]);
        }
    }
}; // AABB

}; // TUGUI

#endif // __AABB_HPP__TUGUI