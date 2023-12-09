/*
 * platform_Types.h
 *
 *  Created on: Nov 20, 2023
 *      Author: engma
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include <stdbool.h>
#include <stdint.h>


#ifndef _Bool
#define _Bool unsigned char
#endif

#define CPU_TYPE          CPU_TYPE_32
#define CPU_BIT_ORDER     MSB_FIRST
#define CPU_BYTE_ORDER    HIGH_BYTE_FIRST

#ifndef False
#define False  (boolean)false
#endif

#ifndef True
#define True (boolean)true
#endif

typedef _Bool             boolean;
typedef int8_t            sint8;
typedef uint8_t           uint8;
typedef int16_t           sint16;
typedef uint16_t          uint16;
typedef int32_t           sint32;
typedef uint32_t          uint32;
typedef int64_t           sint64;
typedef uint64_t          uint64;

typedef uint_least8_t     uint8_least;
typedef uint_least16_t    uint16_least;
typedef uint_least32_t    uint32_least;
typedef int_least8_t      sint8_least;
typedef int_least16_t     sint16_least;
typedef int_least32_t     sint32_least;


typedef float             float32;
typedef double            float64;

typedef volatile int8_t     vint8;
typedef volatile uint8_t    vuint8;
typedef volatile int16_t    vint16;
typedef volatile uint16_t   vuint16;
typedef volatile int32_t    vint32;
typedef volatile uint32_t   vuint32;
typedef volatile int64_t    vint64;
typedef volatile uint64_t   vuint64;


#endif /* PLATFORM_TYPES_H_ */
