//
// Created by code4j on 2022-06-04.
//

#ifndef POINTERTEST_MYBINARYTREE_H
#define POINTERTEST_MYBINARYTREE_H
//定义一个二叉树节点
typedef struct _B_TREE_NODE{
    int data;   //存储元素
    struct _B_TREE_NODE *left_node; //左孩子
    struct _B_TREE_NODE *right_node;//右孩子
}B_TREE_NODE, *B_TREE;  //B_TREE_NODE这个别名可能在求长度的时候有用
//根据数组创建二叉树
//数组格式为二叉树层次遍历，直到最后一个节点；节点为空的内容为-1
B_TREE init_tree(int len, int tree_array[]);
//返回前序遍历队列(非递归版本)
void preorder_visit_queue(B_TREE tree, int len, B_TREE_NODE queue[]);
//返回中序遍历队列(非递归版本)
void inorder_visit_queue(B_TREE tree, int len, B_TREE_NODE queue[]);
//返回后序遍历队列(非递归版本)
void postorder_visit_queue(B_TREE tree, int len, B_TREE_NODE queue[]);

//返回前序遍历队列(递归版本)
int recursion_preorder_visit_queue(B_TREE tree, B_TREE_NODE queue[]);
//返回中序遍历队列(递归版本)
int recursion_inorder_visit_queue(B_TREE tree, B_TREE_NODE queue[]);
//返回后序遍历队列(递归版本)
int recursion_postorder_visit_queue(B_TREE tree, B_TREE_NODE queue[]);

//返回后序遍历队列
int post_order_visit_queue(B_TREE tree, B_TREE_NODE queue[]);

//打印二叉树访问的返回结果，入参实际上是一个数组，不过用指针接一下
void print_tree(int len, B_TREE_NODE queue[]);
#endif //POINTERTEST_MYBINARYTREE_H
