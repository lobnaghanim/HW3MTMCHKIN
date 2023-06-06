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
//        ~Node() { printf("Node destructor\n");}
    };
    Node* tail;
    Node* head;
    int currSize;

public:
    Queue(): head(nullptr), tail(nullptr) , currSize(0){}
    ~Queue() {
        Node* t_ptr = head;
        printf("Queue size is %d\n", currSize);
        while(t_ptr != nullptr){
            Node* t_ptr2 = t_ptr->next;
            delete t_ptr;
            t_ptr = t_ptr2;
        }
        printf("Queue destroyed\n\n");
    }
    // copy constructor
    Queue(Queue const &queue): head(nullptr), tail(nullptr), currSize(0){
        Node* t_ptr = queue.getHead();
        while(t_ptr != nullptr){
            pushBack(t_ptr->data);
            t_ptr = t_ptr->next;
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
        currSize++;
    }

    T& front() const{
        return head->data;
    }

    void popFront(){
        if(head == nullptr){ return;}

        Node* t_ptr = head->next;
        delete head;
        head = t_ptr;
        currSize--;
    }

    Node* getHead() const{
        return head;
    }
    Node* getTail() const{
        return tail;
    }

    int size() const{
        return currSize;
    }

    template <class Condition>
    friend Queue<T> filter(Queue queue, Condition condition){
        Queue<T> newQueue;
        Node* temp = queue.getHead();
        while(temp != nullptr){
            if (condition(temp->data)){
                newQueue.pushBack(temp->data);
            }
            temp = temp->next;
        }
//        printf("t_ptr's data is %d\n", temp->data);
//        printf("t_ptr's next is %d\n", temp->next->data);

        return newQueue;
    }
    template <class Condition>
    friend void transform(Queue& queue, Condition condition){
        Node* temp = queue.getHead();
        while(temp != nullptr){
            condition(temp->data);
            temp = temp->next;
        }
    }
};


#endif