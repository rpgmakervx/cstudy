//
// Created by code4j on 2022-05-14.
//
#include <stdio.h>
#include "mystringcmp.h"
//字符串复制
int my_str_cmp(const char *str_left, const char *str_right) {
    int gap = 0;
    while ((gap = (*str_left++) - (*str_right++)) == 0) {
        if (*str_left == '0' || *str_right == '0') {
            return (*str_left) - (*str_right);
        }
    }
    return gap;

}