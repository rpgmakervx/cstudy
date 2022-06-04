//
// Created by code4j on 2022-05-16.
//
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/**
 *
 */
Node *create_linked_list(int array[], int len) {
    Node *head = malloc(sizeof(Node));
    head->prev = NULL;
    head->next = NULL;
    head->value = -1;
    Node *temp = head;
    for (int index = 0; index < len; ++index) {
        Node *next = malloc(sizeof(Node));
        next->prev = temp;
        next->next = NULL;
        next->value = array[index];
        temp->next = next;
        temp = temp->next;
    }
    return head;
}

void l_print(const Node const *head) {
    if (head == NULL) {
        printf("[]\n");
        return;
    }
    Node *temp = head->next;
    while (temp != NULL) {
        printf("%d", temp->value);
        if (temp->next != NULL) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
}

void l_add(Node *head, int value) {
    Node *next = malloc(sizeof(Node));
    Node *temp = head->next;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    next->prev = temp;
    next->next = NULL;
    next->value = value;
    temp->next = next;
}

int l_set(Node *head, int value, int location) {
    if (head == NULL) {
        return -1;
    }
    Node *temp = head->next;
    int index = 0;
    while (temp->next != NULL && index++ < location) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        return -1;
    }
    temp->value = value;
}

void l_delete(Node *head, int value) {
    if (head == NULL) {
        return;
    }
    Node *temp = head->next;
    while (temp != NULL && temp->value != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        // not found
        return;
    }
    //最后一个元素
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    free(temp);
}

int l_remove(Node *head, int location) {
    if (head == NULL) {
        return -1;
    }
    Node *temp = head->next;
    int index = 0;
    while (temp != NULL && index++ < location) {
        temp = temp->next;
    }
    if (temp == NULL) {
        // not found
        return -1;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
}

Node *l_find(Node *head, int value) {
    if (head == NULL) {
        return NULL;
    }
    Node *temp = head->next;
    while (temp != NULL && temp->value != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return NULL;
    }
    return temp;
}

Node *l_get(Node *head, int location) {
    if (head == NULL) {
        return NULL;
    }
    Node *temp = head->next;
    int index = 0;
    while (temp != NULL && index++ < location) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return NULL;
    }
    return temp;
}

/**
 * 三指针
 * 思路：
 * @param head
 * @return
 */
Node *l_reverse(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    Node *current = head->next;
    Node *prev = head;
    Node *next = current->next;
    while (current != NULL) {
        current->prev = next;
        current->next = prev->prev == NULL ? NULL : prev;
        prev = current;
        current = next;
        next = next == NULL ? NULL : next->next;
    }
    prev->prev = head;
    head->next = prev;
    return head;
}