//
// Created by mrn on 06.10.19.
//

#pragma once

#include <cstdint>

#define func auto
#define kB *1024

#ifdef DEBUG
    #define DBG_PRINT(X) printf(X)
#else
    #define DBG_PRINT(X)
#endif

typedef uint32_t u32;
typedef int32_t  i32;
typedef uint16_t u16;
typedef int16_t  i16;
typedef uint8_t  u8;
typedef int8_t   i8;

func readFile(const char* filename, const char* mode) -> void {

}