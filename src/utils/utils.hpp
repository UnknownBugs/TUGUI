/**
 * 
 *  utility tools
 * 
 * 
*/

#ifndef __UTILS__HPP__
#define __UTILS__HPP__

namespace TUGUI {

template<typename T>
T max(const T &a, const T &b) {
    return a < b ? b : a;
}

template<typename T>
T min(const T &a, const T &b) {
    return a < b ? a : b;
}

template<typename T>
void swap(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}

}; /* TUGUI end */

#endif