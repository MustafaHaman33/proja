#include "../include/LinkedList.h"
#include <iostream>
using namespace std;

void LinkedList::append(BinaryTree *tree) {
    ListNode *newNode = new ListNode(tree);
    if (!head) {
        head = current = newNode;
    } else {
        ListNode *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void LinkedList::moveNext() {
    if (current && current->next) {
        current = current->next;
    } else {
        cout << "Sonraki dugum yok.\n";
    }
}

void LinkedList::movePrev() {
    if (current && current != head) {
        ListNode *temp = head;
        while (temp->next != current) temp = temp->next;
        current = temp;
    } else {
        cout << "Onceki dugum yok.\n";
    }
}

void LinkedList::deleteCurrent() {
    if (!current) return;
    if (current == head) {
        head = head->next;
        delete current;
        current = head;
    } else {
        ListNode *temp = head;
        while (temp->next != current) temp = temp->next;
        temp->next = current->next;
        delete current;
        current = temp->next;
    }
}

void LinkedList::mirrorCurrentTree() {
    if (current) {
        current->tree->mirror();
    }
}

void LinkedList::display() const {
    ListNode *temp = head;
    int count = 0;
    while (temp && count < 10) {
        cout << "Dugum " << count + 1 << endl;
        temp->tree->display();
        temp = temp->next;
        count++;
    }
}

LinkedList::~LinkedList() {
    while (head) {
        ListNode *temp = head;
        head = head->next;
        delete temp->tree;
        delete temp;
    }
}
