#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "BinaryTree.h"

struct ListNode {
    BinaryTree *tree;
    ListNode *next;
    ListNode(BinaryTree *t) : tree(t), next(nullptr) {}
};

class LinkedList {
private:
    ListNode *head, *current;
public:
    LinkedList() : head(nullptr), current(nullptr) {}
    void append(BinaryTree *tree);
    void moveNext();
    void movePrev();
    void deleteCurrent();
    void mirrorCurrentTree();
    void display() const;
    ~LinkedList();
};

#endif
