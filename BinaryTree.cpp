#include "../include/BinaryTree.h"
#include <iostream>
using namespace std;

void BinaryTree::insert(Node *&node, char value) {
    if (!node) {
        node = new Node(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else {
        insert(node->right, value);
    }
}

void BinaryTree::insert(char value) {
    insert(root, value);
}

void BinaryTree::mirror(Node *&node) {
    if (node) {
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }
}

void BinaryTree::mirror() {
    mirror(root);
}

void BinaryTree::display(Node *node, int space) const {
    if (!node) return;
    space += 5;
    display(node->right, space);
    cout << endl;
    for (int i = 5; i < space; i++) cout << " ";
    cout << node->data << "\n";
    display(node->left, space);
}

void BinaryTree::display() const {
    display(root, 0);
}

BinaryTree::~BinaryTree() {
    // Belleği temizlemek için yıkıcı fonksiyon
}
