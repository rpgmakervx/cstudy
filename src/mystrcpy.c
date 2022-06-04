//
// Created by code4j on 2022-05-12.
//
#include <stdio.h>
#include "mystrcpy.h"

void my_str_cpy( char const* src, char* dest) {
    while ((*dest++ = *src++) != '\0') {
        printf("char:%c", *src);
    }
}