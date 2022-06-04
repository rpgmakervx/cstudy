//
// Created by code4j on 2022-05-14.
//
#include <stdio.h>
#include "strings.h"
#include "mystringcmp.h"

void error_msg() {
    printf("error4:%s\n", strerror(4));
    printf("error10:%s\n", strerror(10));
    printf("error1:%s\n", strerror(1));
}
void find_str() {
    char* name1 = "code4j, deter";
    printf("strstr:%s\n", strstr(name1, "det"));
    printf("strpbrk:%s\n", strpbrk(name1, "det"));
}
void find_ch() {
    char* name = "code4j";
    char* name1 = "code4j, deter";
    printf("d loc:%s\n", strchr(name, 'd'));
    printf("4 loc:%s\n", strchr(name, '4'));
    printf("p loc:%s\n", strchr(name, 'p'));
    printf("strrchr d loc:%s\n", strrchr(name1, 'd'));
}
void my_strcmp() {
    char* name1 = "code4j123";
    char* name2 = "code4j";
    char* name3 = "rpgmakervx";
    int a = *name1 - *name2;
    printf("begin\n");

    printf("my_str_cmp1:%d\n", my_str_cmp(name1, name1));
    printf("my_str_cmp2:%d\n", my_str_cmp(name1, name2));
    printf("my_str_cmp3:%d\n", my_str_cmp(name1, name3));
    printf("my_str_cmp4:%d\n", my_str_cmp("", name3));
    printf("my_str_cmp5:%d\n", my_str_cmp("\0", name3));
}
void mem_cover() {
    char message[] = "this is a message";
    char x[] = "hello";
    strcpy(message, "12345678901234567");
    printf("message:%s, x:%s\n", message, x);
}

int main() {
//    mem_cover();
//    my_strcmp();
//    find_ch();
//    find_str();
    error_msg();
    return 0;
}

