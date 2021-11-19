/*
 * @Author: SPeak Shen 
 * @Date: 2020-03-19 21:19:26 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-17 01:06:30
 */

#ifndef __DEFS_H__
#define __DEFS_H__

namespace MUTILS {

#define nullptr 0

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

// address
typedef unsigned int uptr32_t;

// char
typedef unsigned char uchar8_t;

//cstring, ccstring     c style string
typedef char *cstring;
typedef const char *ccstring;

}; // MUITLS
#endif