//
// Created by code4j on 2022-05-10.
//
#include <stdio.h>
#include <string.h>


void pointer_visit() {
    int array[] = {0, 1, 2, 3, 4, 5};
    int *pointer = array;
    printf("pointer[1]:%d\n", pointer[-1]);
    printf("&array[0]:%p, &pointer[0]:%p\n", &array[0], &pointer[0]);
    printf("&array[1]:%p, &pointer[1]:%p\n", &array[1], &pointer[1]);
    // &array + 1 和 &array[1]不同，array数组名会被当成一个指针常量，指针常量+1表示增加一个
    // 指针长度单位的大小，所以前者的地址跨度是8(32位为4)，后者是取数组第2个元素地址，int是4字节所以地址跨度是4
    printf("&array:%p, &array + 1:%p\n", &array, &array + 1);
    printf("&pointer:%p, &pointer + 1:%p\n", &pointer, &pointer + 1);
}

int find_word(const char *src, char *array[], int size) {
    printf("array size:%d\n", size);
    for (int index = 0; index < size; ++index) {
        if (strcmp(array[index], src) == 0) {
            return index;
        }
    }
    return -1;
}

void pointer_array() {
    char *array[] = {"great", "name", "please", "finite", "generate"};
    int size = sizeof(array) / sizeof(char *);
//    printf("size:%d", );
    printf("find great:%d", find_word("please", array, size));
}

void double_array() {
    int array[][5] = {
            {1,  2,  3},
            {4,  5,  6},
            {7,  8,  9},
            {10, 11, 12, 13, 14}
    };
    printf("array size:%d\n", sizeof(array));
    printf("array1 size:%d, array2 size:%d\n", sizeof(array[0]), sizeof(array[3]));
}

void method(int *p) {
    printf("p:%p,", p);
    p = p + 1;
    printf("p+1:%p\n", p);
}

void param_deliver() {
    int num = 10;
    int *p = &num;
    printf("before call method p:%p\n", p);
    method(p);
    printf("after call method p:%p\n", p);
}

void test_array() {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ap = array + 2;
    printf("name as pointer:%p\n", array);
    printf("name as ap:%p\n", ap);
    printf("loc name:%p\n", &ap);
    printf("*ap:%d\n", *ap);
    printf("ap[0]:%d\n", ap[0]);
    printf("ap[2]:%d\n", ap[2]);
    printf("ap+6:%p, &array[8]:%p\n", ap + 6, &array[8]);
    printf("*(ap+6):%d\n", *(ap + 6));
    printf("ap[6]:%d\n", ap[6]);
    printf("ap[-1]:%d\n", ap[-1]);
    printf("ap[10]:%d\n", ap[7]);
}

int main() {
//    test_array();
//    param_deliver();
//    double_array();
//    pointer_array();
    pointer_visit();
    return 0;
}