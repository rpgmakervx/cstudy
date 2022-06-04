//
// Created by code4j on 2022-05-16.
//

#ifndef POINTERTEST_LINKEDLIST_H
#define POINTERTEST_LINKEDLIST_H
typedef struct NODE {
    int value;
    struct NODE *next;
    struct NODE *prev;
} Node;

//用数组初始化一个连表
Node *create_linked_list(int array[], int len);

void l_add(Node *node, int value);

int l_set(Node *node, int value, int index);

void l_delete(Node *head, int value);

int l_remove(Node *node, int index);

Node *l_find(Node *node, int value);

Node *l_get(Node *node, int index);

void l_print(const Node const *node);

Node *l_reverse(Node *node);

#endif //POINTERTEST_LINKEDLIST_H
