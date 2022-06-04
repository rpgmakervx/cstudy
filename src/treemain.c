//
// Created by code4j on 2022-06-05.
//
#include <stdio.h>
#include <stdlib.h>
#include "mybinarytree.h"

int main() {
    int tree_array[] = {8, 5, 13, 2, 6, 10, 16, 1, 3, 7};
    int len = sizeof(tree_array) / sizeof(int);
    B_TREE root = init_tree(len, tree_array);
    B_TREE_NODE queue[len];
    printf("init over\n");
    recursion_preorder_visit_queue(root, queue);
    printf("recursion over\n");
    print_tree(len, queue);
    printf("print over\n");
    return 0;
}
