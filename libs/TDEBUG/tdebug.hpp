/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:12:38 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-12-01 09:34:38
 */

#ifndef __TDEBUG_HPP__
#define __TDEBUG_HPP__

#include <assert.hpp>

namespace TDEBUG {

static inline
void setDPrint(void *func) {
    dprint = (DPrintType)func;
}

enum class RT {
    ERROR   = -1,
    SUCCESS = 0
};

inline static void
crash() {
    *((char *)0) = 'E';
}

}; /* TDEBUG end */

#endif