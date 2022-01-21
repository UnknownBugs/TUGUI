/*
 * @Author: SPeak Shen 
 * @Date: 2020-03-19 21:19:26 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-30 10:34:37
 */

#ifndef __DEFS_HPP__
#define __DEFS_HPP__

using uint8_t  = unsigned char;
using uint16_t = unsigned short;
using uint32_t = unsigned int;
using uint64_t = unsigned long long;

using UINT8  = uint8_t;
using UINT16 = uint16_t;
using UINT32 = uint32_t;
using UINT64 = uint64_t;

using int8_t  = char;
using int16_t = short;
using int32_t = int;
using int64_t = long long;

using size_t = uint32_t;

// address
typedef unsigned int uptr32_t;

// char
using uchar8_t   = unsigned char;
using uwchar16_t = unsigned short;

using char8_t   = char;
using wchar16_t = short;

//cstring, ccstring     c style string
typedef char *cstring;
typedef const char *ccstring;


#ifndef __cplusplus

#define nullptr 0

enum {
    false 0,
    true 1,
} bool；

#endif // __cplusplus

#endif // __DEFS_HPP__