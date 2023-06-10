#include <iostream>
using namespace std;
#include "HealthPoints.h"
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
    n = 42;
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


    Queue<int> queue2(queue1);

    queue1.pushBack(5);
    queue1.pushBack(6);
    queue1.pushBack(7);

    REQUIRE(queue1.front() == 1);
    // print front of queue1
    queue1.popFront();


    Queue<int> queue3 = filter(queue1, isEven);
    printQueue(queue1);
    queue1.front() = 42;
    cout << "queue 1 after pop" << endl;
    printQueue(queue1);
    printQueue(queue2);
    printQueue(queue3);

    return 0;
}

