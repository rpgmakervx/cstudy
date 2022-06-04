//
// Created by code4j on 2022-05-12.
//

#include "mystrlen.h"
//字符串求长度
int my_str_len(char *string) {
    int count = 0;
    while (*string++ != '\0') {
        count++;
    }
    return count;
}