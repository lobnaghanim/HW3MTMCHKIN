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
    queue2.popFront();
    printf("queue 2 first element: %d\n", queue2.front());
    printf("queue 2 second element: %d\n", queue2.getHead()->next->data);
    printf("queue 2 third element: %d\n", queue2.getHead()->next->next->data);

    Queue<int>::Iterator it = queue2.end();
    printf("the iterator's size is: %d\n", it.index);

    Queue<int>::Iterator it2 = queue2.begin();
    printf("it != it2: %d\n", it != it2); // 1
    printf("it != it: %d\n", it != it); // 0

    printf("------------------\n");
    printf("it2 index is: %d\n", it2.index); // 0
    printf("the data of it2.node is: %d\n", *it2); // 2
    ++it2;
    printf("it2 index is: %d\n", it2.index); // 1
    printf("the data of it2.node is: %d\n", *it2); // 3

    return 0;
}