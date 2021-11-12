#ifndef __TDEBUG_HPP__
#define __TDEBUG_HPP__

namespace TDEBUG {

inline static void
crash() {
    *((char *)0) = 'E';
}

}; /* TDEBUG end */

#endif