//
// Created by code4j on 2022-06-04.
//
#include <stdio.h>
#include <stdlib.h>
#include "mybinarytree.h"

//根据数组创建二叉树
B_TREE init_tree(int len, int tree_array[]) {
    //进门判空
    if (len == 0) {
        return NULL;
    }
    B_TREE root = (B_TREE) malloc(sizeof(B_TREE_NODE));
    //维持一个队列，目的是为了给二叉树各个节点的父子关系做衔接的
    //如果没有这个队列，在遍历tree_array过程中会不知道
    B_TREE queue[len];
    root->data = tree_array[0];
    //一个节点就别继续了，到此结束
    if (len == 1) {
        return root;
    }
    queue[0] = root;
    //遍历顺序结构的二叉树值。
    //性质:索引为p的节点其left_node顺序为2p+1，right_node为2p+2
    //反过来，已知某个节点索引n，那么父节点为 (n-1)/2,可以套一个case自测下
    printf("begin init tree with array\n");
    for (int index = 1; index < len; ++index) {
        if (tree_array[index] == -1) {
            //如果是空节点就跳过它
            continue;
        }
        B_TREE new_node = (B_TREE) malloc(sizeof(B_TREE_NODE));
        queue[index] = new_node;
        new_node->data = tree_array[index];
        int parent_index = (index - 1) / 2;
        if (parent_index * 2 + 1 == index) {
            //new_node是左孩子的情况
            queue[parent_index]->left_node = new_node;
        } else if (parent_index * 2 + 2 == index) {
            queue[parent_index]->right_node = new_node;
        } else {
            //按理说if和else if会走一个,如果没有就打个日志
            printf("index error,parent_index:%d, index:%d", parent_index, index);
        }
    }
    return root;
}

/**
 * 返回前序遍历队列(非递归版本)
 * 思路：
 * 1. 使用栈模拟的递归函数在访问当前节点时前面的节点路径
 * 2. 当一路左孩子访问完毕后，转身右孩子迭代，迭代思路和左孩子一样
 */
void preorder_visit_queue(B_TREE tree, int len, B_TREE queue) {
    if (tree == NULL) {
        return;
    }
    //访问队列指针
    int index = 0;
    B_TREE stack[len];
    int top = -1;
    B_TREE temp = tree;
    while (top != -1 || temp != NULL) {
        while (temp != NULL) {
            stack[++top] = temp;
            queue[index++] = *temp;
            temp = temp->left_node;
        }
        temp = stack[top--]->right_node;
    }
}

//返回中序遍历队列(非递归版本)
void inorder_visit_queue(B_TREE tree, int len, B_TREE queue) {
    if (tree == NULL) {
        return;
    }
    //访问队列指针
    int index = 0;
    B_TREE stack[len];
    int top = -1;
    B_TREE temp = tree;
    while (top != -1 || temp != NULL) {
        while (temp != NULL) {
            stack[++top] = temp;
            temp = temp->left_node;
        }
        temp = stack[top--];
        queue[index++] = *temp;
        temp = temp->right_node;
    }
}

//返回后序遍历队列(非递归版本)
void postorder_visit_queue(B_TREE tree, int len, B_TREE queue) {

}

//先序遍历思路：
//先将节点记录下来，再进行左右递归。记录节点模拟访问操作，记录后再去外部打印访问
int recursion_preorder_visit_queue0(B_TREE tree, B_TREE queue, int count) {
    if (tree == NULL) {
        return count;
    }
    queue[count++] = *tree;
    printf("visit count:%d, data:%d\n", count, tree->data);
    count = recursion_preorder_visit_queue0(tree->left_node, queue, count);
    return recursion_preorder_visit_queue0(tree->right_node, queue, count);
}

//返回前序遍历队列(递归版本)
int recursion_preorder_visit_queue(B_TREE tree, B_TREE queue) {
    return recursion_preorder_visit_queue0(tree, queue, 0);
}

int recursion_inorder_visit_queue0(B_TREE tree, B_TREE queue, int count) {
    if (tree == NULL) {
        return count;
    }
    count = recursion_inorder_visit_queue0(tree->left_node, queue, count);
    queue[count++] = *tree;
    printf("visit count:%d, data:%d\n", count, tree->data);
    return recursion_inorder_visit_queue0(tree->right_node, queue, count);
}

//返回中序遍历队列(递归版本)
int recursion_inorder_visit_queue(B_TREE tree, B_TREE queue) {
    return recursion_inorder_visit_queue0(tree, queue, 0);
}

int recursion_postorder_visit_queue0(B_TREE tree, B_TREE queue, int count) {
    if (tree == NULL) {
        return count;
    }
    count = recursion_postorder_visit_queue0(tree->left_node, queue, count);
    count = recursion_postorder_visit_queue0(tree->right_node, queue, count);
    printf("visit count:%d, data:%d\n", count, tree->data);
    queue[count++] = *tree;
    return count;
}

//返回后序遍历队列(递归版本)
int recursion_postorder_visit_queue(B_TREE tree, B_TREE queue) {
    return recursion_postorder_visit_queue0(tree, queue, 0);
}

//打印二叉树访问的返回结果，入参实际上是一个数组，不过用指针接一下
void print_tree(int len, B_TREE queue) {
    for (int index = 0; index < len; ++index) {
        printf("%d ", queue[index].data);
    }
    printf("\n");
}