/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-13 23:12:38 
 * @Last Modified by:   SPeak Shen 
 * @Last Modified time: 2021-11-13 23:12:38 
 */

#ifndef __TDEBUG_HPP__
#define __TDEBUG_HPP__

namespace TDEBUG {

inline static void
crash() {
    *((char *)0) = 'E';
}

}; /* TDEBUG end */

#endif