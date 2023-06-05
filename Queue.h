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
    ~Queue() {
        Node* t_ptr = head;
        while(t_ptr != nullptr){
            Node* t_ptr2 = t_ptr->next;
            delete t_ptr;
            t_ptr = t_ptr2;
        }
    }

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

    T& front() const{
        return head->data;
    }

    void popFront(){
        if(head == nullptr){ return;}

        Node* t_ptr = head->next;
        delete head;

        head = t_ptr;
    }

    Node* tail;
    Node* head;
};

#endif