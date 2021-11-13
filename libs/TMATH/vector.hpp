/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:11:28 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-13 23:39:36
 */

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <../TDEBUG/tdebug.hpp>

namespace TMATH {

template<typename T, unsigned int N = 2>
class Vector {
public:
    
    unsigned int getDimension() const {
        return N;
    }

    T & operator[](unsigned int i) {
        if (i >= N) TDEBUG::crash();
        return vec[N];
    }

private:
    T vec[N == 0 ? 1 : N];
};

} // namespace TMAT 

#endif // __VECTOR_HPP__ end