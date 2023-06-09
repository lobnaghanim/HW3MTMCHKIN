#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>


template <typename T> class Queue {

private:
    class Node;

    Node* head;
    Node* tail;
    int currSize;

public:
    Queue(): head(nullptr), tail(nullptr) , currSize(0){}
    ~Queue() {
        Node* t_ptr = head;
        while(t_ptr != nullptr){
            Node* t_ptr2 = t_ptr->next;
            delete t_ptr;
            t_ptr = t_ptr2;
        }
    }
    // copy constructor
    Queue(Queue const &queue): head(nullptr), tail(nullptr), currSize(0){
        Node* t_ptr = queue.getHead();
        while(t_ptr != nullptr){
            pushBack(t_ptr->data);
            t_ptr = t_ptr->next;
        }
    }

    class EmptyQueue : public std::exception {};

    void pushBack(const T& element);


    T& front() const{
        if (head == nullptr){
            throw EmptyQueue();
        }
        return head->data;
    }

    void popFront(){
        // handle exception
        if(head == nullptr){
            throw EmptyQueue(); // nullptr dereference
        }
        Node* t_ptr = head->next; // (*head).next
        delete head;
        head = t_ptr;
        currSize--;
    }

    Node* getHead() const{
        return head;
    }
//    Node* getTail() const{
//        return tail;
//    }
    int size() const{
        return currSize;
    }


    template <class Condition>
    friend Queue<T> filter(const Queue& queue, Condition condition){
        Queue<T> newQueue;
        Node* temp = queue.getHead();
        while(temp != nullptr){
            if (condition(temp->data)){
                newQueue.pushBack(temp->data);
            }
            temp = temp->next;
        }
        return newQueue;
    }

    template <class Operator>
    friend void transform(Queue& queue, Operator op) {
        Node* temp = queue.getHead();
        while (temp != nullptr) {
            op(temp->data);
            temp = temp->next;
        }
    }

    class Iterator;
    class ConstIterator;

    Iterator begin(){
        return Iterator(head, 0);
    }

    Iterator end(){
        return Iterator(nullptr, currSize);
    }

    ConstIterator begin() const{
        return ConstIterator(head, 0);
    }

    ConstIterator end() const{
        return ConstIterator(nullptr, currSize);
    }


};

// Implementation of Node
template <typename T>
class Queue<T>::Node{
    public:
    T data;
    Node* next;
    explicit Node(const T& element): data(element), next(nullptr) {}
    bool operator==(const Node& other){ // might contain error.
        return (data == other.data && next == other.next);
    }
};

// Implementation of Queue's methods

// pushBack
template <typename T>
void  Queue<T>::pushBack(const T &element) {
    try {
        Node *newNode = new Node(element);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        currSize++;
    }catch (std::bad_alloc& e){
        // rethrow error
        throw e;
    }
}


// Implementation of Iterator
template <typename T>
class Queue<T>::Iterator{

private:
    Iterator(Node* node, int index): node(node), index(index){}
    friend class Queue;
public:
    Node* node;
    int index;

    class InvalidOperation : public std::exception {};
    Iterator(const Iterator&) = default;

    Iterator& operator++(){
        // handle exception
        if(node == nullptr){
            throw InvalidOperation(); // nullptr dereference
        }
        node = node->next;
        index++;
        return *this;
    }

    Iterator operator++(int){
        // handle exception
        if(node == nullptr){
            throw InvalidOperation(); // nullptr dereference
        }
        Iterator result = *this;

        try {
            // try the implementation of operator++()
            operator++(); // might be an error
        } catch (InvalidOperation& e) {
            throw e;
        }

        return result;
    }

    bool operator!=(const Iterator& it2){ // might contain error.
        return !(node == it2.node && index == it2.index);
    }

    T& operator*(){
        // handle exception
        if(node == nullptr){
            throw InvalidOperation(); // nullptr dereference
        }
        return node->data;
    }
};


// Implementation of ConstIterator
template <typename T>
class Queue<T>::ConstIterator{
private:
    ConstIterator(const Node* node, int index): node(node), index(index){}
    friend class Queue;
public:
    const Node* node;
    int index;

    class InvalidOperation : public std::exception {};
    ConstIterator(const ConstIterator&) = default;

    ConstIterator& operator++(){
        // handle exception
        if(node == nullptr){
            throw InvalidOperation(); // nullptr dereference
        }
        node = node->next;
        index++;
        return *this;
    }

    ConstIterator operator++(int) {
        // handle exception
        if(node == nullptr){
            throw InvalidOperation(); // nullptr dereference
        }
        ConstIterator result = *this;

        try {
            // try the implementation of operator++()
            operator++(); // might be an error
        } catch (InvalidOperation& e) {
            throw e;
        }

        return result;
    }

    bool operator!=(const ConstIterator& it2) const{ // might contain error.
        return !(node == it2.node && index == it2.index);
    }

    const T& operator*() const{
        // handle exception
        if(node == nullptr){
            throw InvalidOperation(); // nullptr dereference
        }
        return node->data;
    }
};

#endif