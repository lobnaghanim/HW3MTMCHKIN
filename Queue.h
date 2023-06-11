#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

// swap utility function
template <typename T>
void swapPtr(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> class Queue {

private:
    class Node;

    Node* m_head;
    Node* m_tail;
    int n_currSize;

public:
    Queue(): m_head(nullptr), m_tail(nullptr) , n_currSize(0){}
    ~Queue() {
        Node* t_ptr = m_head;
        while(t_ptr != nullptr){
            Node* t_ptr2 = t_ptr->m_next;
            delete t_ptr;
            t_ptr = t_ptr2;
        }
        m_head = nullptr;
        m_tail = nullptr;
    }

    // copy constructor
    Queue(Queue const &queue): m_head(nullptr), m_tail(nullptr), n_currSize(0){
        Node* t_ptr = queue.m_head;
        while(t_ptr != nullptr){
            try {
                pushBack(t_ptr->m_data);
                t_ptr = t_ptr->m_next;
            }catch (std::bad_alloc& e){
                // rethrow error
                throw e;
            }

        }
    }
    // assignment operator deep copy
//    Queue& operator=(Queue const &queue){
//        if (this != &queue){
//            Node* t_ptr = queue.head;
//            while(t_ptr != nullptr){
//                try {
//                    pushBack(t_ptr->data);
//                    t_ptr = t_ptr->next;
//                }catch (std::bad_alloc& e){
//                    // rethrow error
//                    throw e;
//                }
//            }
//        }
//        return *this;
//    }

// assignment operator deep copy and swap (passes all tests but with a memory leak)
    Queue& operator=(Queue const& queue) {
        if (this != &queue) {
            // Create a temporary Queue for the deep copy
            Queue tempQueue;
            // Perform the deep copy into the temporary Queue
            Node* t_ptr = queue.m_head;
            while (t_ptr != nullptr) {
                try {
                    tempQueue.pushBack(t_ptr->m_data);
                    t_ptr = t_ptr->m_next;
                } catch (std::bad_alloc& e) {
                    // Rethrow error or handle as needed
                    throw e;
                }
            }
            // Deep copy succeeded, update the current object
            // by swapping its contents with the temporary Queue
            swapPtr(m_head, tempQueue.m_head);
            swapPtr(m_tail, tempQueue.m_tail);
            swapPtr(n_currSize, tempQueue.n_currSize);

        }
        return *this;
}



    class EmptyQueue : public std::exception {};

    void pushBack(T element);

    // was T& front() const{}
    T& front(){
        if (m_head == nullptr){
            throw EmptyQueue();
        }
        return m_head->m_data;
    }

    // new implementation
    const T& front() const{
        if (m_head == nullptr){
            throw EmptyQueue();
        }
        return m_head->m_data;
    }

    void popFront(){
        // handle exception
        if(m_head == nullptr){
            throw EmptyQueue(); // nullptr dereference
        }
        Node* t_ptr = m_head->m_next; // (*head).next
        delete m_head;
        m_head = t_ptr;
        n_currSize--;
    }

    Node* getHead() const{
        return m_head;
    }
//    Node* getTail() const{
//        return tail;
//    }
    int size() const{
        return n_currSize;
    }

    // does not create a deep copy
    template <class Condition>
    friend Queue<T> filter(const Queue& queue, Condition condition){
        Queue<T> newQueue;
        Node* temp = queue.getHead();
        while(temp != nullptr){
            if (condition(temp->m_data)){
                try {
                    newQueue.pushBack(temp->m_data);
                }catch (std::bad_alloc& e){
                    // rethrow error
                    throw e;
                }
            }
            temp = temp->m_next;
        }
        return newQueue;
    }

    template <class Operator>
    friend void transform(Queue& queue, Operator op) {
        Node* temp = queue.getHead();
        while (temp != nullptr) {
            op(temp->m_data);
            temp = temp->m_next;
        }
    }

    class Iterator;
    class ConstIterator;

    Iterator begin(){
        return Iterator(m_head, 0);
    }

    Iterator end(){
        return Iterator(nullptr, n_currSize);
    }

    ConstIterator begin() const{
        return ConstIterator(m_head, 0);
    }

    ConstIterator end() const{
        return ConstIterator(nullptr, n_currSize);
    }


};

// Implementation of pushBack deep copy
template<typename T>
void Queue<T>::pushBack(T element) {
    try {
        Node *newNode = new Node(element);
        if (m_head == nullptr) {
            m_head = newNode;
            m_tail = newNode;
        } else {
            m_tail->m_next = newNode;
            m_tail = newNode;
            m_tail->m_next = nullptr;
        }
        n_currSize++;
    }catch (std::bad_alloc& e){
        // free memory
        while(m_head != nullptr){
            popFront();
        }

        // rethrow error
        throw e;
    }

}

// Implementation of Node
template <typename T>
class Queue<T>::Node{
public:
    T m_data;
    Node* m_next;
    explicit Node(T element): m_data(element), m_next(nullptr) {}
    bool operator==(const Node& other){ // might contain error.
        return (m_data == other.m_data && m_next == other.m_next);
    }
};



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
        node = node->m_next;
        index++;
        return *this;
    }

    Iterator& operator++(int){
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
        return node->m_data;
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
        node = node->m_next;
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
        return node->m_data;
    }
};

#endif