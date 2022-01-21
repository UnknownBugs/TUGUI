/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:15:18 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-17 01:05:46
 * 
 * utility tools
 * 
 */

#ifndef __UTILS__HPP__
#define __UTILS__HPP__

namespace MUTILS {

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

template<typename T>
T abs(const T &num) {
    return num > 0 ? num : -num;
}

}; /* TUGUI end */

#endif