#include <iostream>
using namespace std;
#include "HealthPoints.h"
#include "Queue.h"

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
int main(){
    Queue<int> queue1;
    queue1.pushBack(1);
    queue1.pushBack(2);
    queue1.pushBack(3);
    queue1.pushBack(4);

    //Queue<int> queue2 = filter(queue1, isEven);
    Queue<int> queue2=queue1;

    printf("------------------\n");
    for(Queue<int>::Iterator it = queue2.begin(); it != queue2.end(); ++it){
        printf("it: %d\n", *it);
    }

    printf("------------------\n");

    Queue<int> queue6;
    queue6.pushBack(1);

    try {
        queue6.popFront();
    }
    catch (Queue<int>::EmptyQueue e) {
        ::printf("Empty Queue!\n");
    }

    Queue<int>::Iterator endIterator = queue6.end();
    try {
        endIterator++;
    }
    catch (Queue<int>::Iterator::InvalidOperation& e) {
        printf("Invalid Operation!\n");
    }


    return 0;
}