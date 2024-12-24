#ifndef BINARYTREE_H
#define BINARYTREE_H

struct Node {
    char data;
    Node *left, *right;
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node *root;
    void insert(Node *&node, char value);
    void mirror(Node *&node);
    void display(Node *node, int space) const;

public:
    BinaryTree() : root(nullptr) {}
    void insert(char value);
    void mirror();
    void display() const;
    ~BinaryTree();
};

#endif
