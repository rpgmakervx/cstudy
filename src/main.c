#include <stdio.h>
#include "mystrlen.h"
#include "mystrcpy.h"

#define ABC(x) x*x;

void test() {
    printf("Hello, World!\n");
    int size = 10;
    int *p_size = &size;
    int **loc_p_size = &p_size;
    printf("pointer size:%p, p_size:%p, loc_p_size:%p\n", &size, p_size, loc_p_size);
    printf("size size:%d, p_size size:%d", sizeof(size), sizeof(p_size));
    return;
}

int my_str_len(char *string);

int main() {
    char *name = "code4j";
    char cp_name[my_str_len(name)];
    printf("string:%s, size:%d\n", name, my_str_len(name));
    printf("string:%s\n", name);
    my_str_cpy(name, cp_name);
    printf("string copy, src:%s, dest:%s\n", name, cp_name);
    int x = 3;
    int a = ++ABC(x+1);
    printf("x:%d", a);
    return 0;
}