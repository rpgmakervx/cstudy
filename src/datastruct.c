//
// Created by code4j on 2022-05-16.
//
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>

int main() {
    int array[] = {9, 3, 8, 1, 0, 7};
//    printf("%s\n", strerror(11));
    printf("sizeof(Node *):%ld, sizeof(Node):%ld\n", sizeof(Node *), sizeof(Node));
    Node *list = create_linked_list(array, sizeof(array) / sizeof(int));
    l_print(list);
    l_add(list, 10);
    l_print(list);
    l_set(list, 5, 3);
    l_print(list);
    l_delete(list, 1);
    l_print(list);
    l_remove(list, 1);
    l_print(list);
    l_add(list, 6);
    l_print(list);
    Node *node = l_get(list, 5);
    printf("node[%d]:%d\n", 5, node == NULL ? -1 : node->value);
    int location = sizeof(array) / sizeof(int);
    node = l_get(list, location);
    printf("node[%d]:%d\n", location, node == NULL ? -1 : node->value);
    node = l_get(list, 13);
    printf("node[%d]:%d\n", 13, node == NULL ? -1 : node->value);
    node = l_find(list, 9);
    printf("%d:%d\n", 9, node == NULL ? -1 : node->value);
    node = l_find(list, 12);
    printf("%d:%d\n", 12, node == NULL ? -1 : node->value);
    l_print(list);
    l_reverse(list);
    l_print(list);
    l_reverse(list);
    l_print(list);

    return 0;
}