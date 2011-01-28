/*

    pHash, the open source perceptual hash library
    Copyright (C) 2008-2009 Aetilius, Inc.
    All rights reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Evan Klinger - eklinger@phash.org
    D Grant Starkweather - dstarkweather@phash.org

*/

#ifndef _PHASH_H
#define _PHASH_H

#include "pHash-config.h"
#include <limits.h>
#include <math.h>
//#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>
#include <malloc.h>

#define __STDC_CONSTANT_MACROS

//#include <stdint.h>
//#include "CImg.h"

#ifdef HAVE_PTHREAD
#include <pthread.h>
#endif

#ifndef __GLIBC__
#include <sys/param.h>
//#include <sys/sysctl.h>
#endif

using namespace std;

#define SQRT_TWO 1.4142135623730950488016887242097

#ifndef ULLONG_MAX
#define ULLONG_MAX 18446744073709551615ULL
#endif

#define ROUNDING_FACTOR(x) (((x) >= 0) ? 0.5 : -0.5)

#if defined( _MSC_VER) || defined(_BORLANDC_)
typedef unsigned __int64 ulong64;
typedef signed __int64 long64;
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed int int16_t;
typedef unsigned int uint16_t;
typedef signed long int int32_t;
typedef unsigned long int uint32_t;
typedef signed long long int int64_t;
typedef unsigned long long int uint64_t;
#else
typedef unsigned long long ulong64;
typedef signed long long long64;
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ph_hashtype {
    BYTEARRAY   = 1,          /* refers to bitwidth of the hash value */
    UINT16ARRAY = 2,
    UINT32ARRAY = 4,
    UINT64ARRAY = 8,
}HashType;

/* structure for a single hash */
typedef struct ph_datapoint {
    char *id;
    void *hash;
    float *path;
    uint32_t hash_length;
    uint8_t hash_type;
}DP;

#define ROTATELEFT(x, bits)  (((x)<<(bits)) | ((x)>>(64-bits)))

#ifdef HAVE_PTHREAD
int ph_num_threads();
#endif

/*! /brief copyright information
 */
//const char* ph_about();

#ifdef __cplusplus
}
#endif

#endif
