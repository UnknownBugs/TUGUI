/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-17 01:12:54 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-21 00:27:54
 */

#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <defs.hpp>

#define PIXEL_WHITE {0xFF, 0xFF, 0xFF, 0}
#define PIXEL_RED   {0xFF, 0, 0, 0}

namespace TUGUI {

struct RGB {
    uint8_t R;
    uint8_t G;
    uint8_t B;
    uint8_t S;    // reserved
};

};

#endif