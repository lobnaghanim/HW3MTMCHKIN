#include <iostream>
using namespace std;


#include "Queue.h"
#include <vector>
// include REQUIRE
#define REQUIRE(condition) \
    if (!(condition)) { \
        std::cout << "Line " << __LINE__ << ": requirement failed: " << #condition << std::endl; \
    }

bool isEven(int n){
    return !(n % 2);
}
static void setFourtyTwo(int& n)
{
    n = 69;
}
static void addOne(int& n)
{
    n += 1;
}

//print a queue
template <typename T>
void printQueue(Queue<T> queue){
    // iterator
    for (auto it = queue.begin(); it != queue.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){


    // check if pushBack creates a deep copy
    Queue<int> queue1;
    queue1.pushBack(1);
    queue1.pushBack(2);
    queue1.pushBack(3);
    queue1.pushBack(4);

    cout << "queue1: ";
    printQueue(queue1);

    Queue<int> queue2;
    queue2.pushBack(42);
    queue2.pushBack(33);

    cout << "queue2: ";
    printQueue(queue2);

    queue2 = queue1;
    cout << "queue2: ";
    printQueue(queue2);

    cout << "*********queue2: ";
    printQueue(queue2);


    Queue<int> queue3(queue1);
    cout << "queue3: ";
    queue3.pushBack(33333);
    printQueue(queue3);


    Queue<int> queue4 = queue1;
    cout << "queue4: ";
    queue4.pushBack(44444);
    printQueue(queue4);

    cout << "-------------------" << endl;
    // print q1
    cout << "queue1: ";
    printQueue(queue1);
    // print q2
    cout << "queue2: ";
    printQueue(queue2);
    // print q3
    cout << "queue3: ";
    printQueue(queue3);
    // print q4
    cout << "queue4: ";
    printQueue(queue4);

    Queue<int> queue5;
    queue5.pushBack(1);

    queue5 = queue1;
    cout << "queue5: ";
    printQueue(queue5);

    Queue<int> temp;

    temp = filter(queue1, isEven);
    temp = filter(queue2, isEven);
    temp = filter(queue3, isEven);
    temp = filter(queue4, isEven);
    temp = filter(queue5, isEven);
    temp.pushBack(1);

    transform(queue1, setFourtyTwo);

    // print q1
    cout << "queue1: ";
    printQueue(queue1);

    Queue<int> qErr;
    qErr.pushBack(1);
    qErr.pushBack(2);
    try{
        queue2 = queue1;
    }catch (std::bad_alloc& e){
        cout << "bad_alloc caught: " << e.what() << endl;
    }

    return 0;
}

