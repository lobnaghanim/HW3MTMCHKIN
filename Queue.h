#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template <typename T> class Queue {
private:
    class Node {
    public:
        T data;
        Node* next;
        explicit Node(const T& element): data(element), next(nullptr) {}
        ~Node() { printf("Node destructor\n");}
    };

public:
    Queue(): head(nullptr), tail(nullptr) {}

    void pushBack(const T& element) {
        Node * newNode = new Node(element);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* head;
    Node* tail;
};

#endif