/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:12:38 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-17 00:25:41
 */

#ifndef __TDEBUG_HPP__
#define __TDEBUG_HPP__

namespace TDEBUG {

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