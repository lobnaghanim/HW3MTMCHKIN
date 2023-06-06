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
    n+=1;
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

    transform(queue1, setFourtyTwo);
    transform(queue2, addOne);

    printf("queue 1 first element: %d\n", queue1.front());
    printf("queue 1 second element: %d\n", queue1.getHead()->next->data);
    printf("queue 1 third element: %d\n", queue1.getHead()->next->next->data);
    printf("queue 1 third element: %d\n", queue1.getHead()->next->next->next->data);

    printf("queue 2 first element: %d\n", queue2.front());
    printf("queue 2 second element: %d\n", queue2.getHead()->next->data);
    printf("queue 2 third element: %d\n", queue2.getHead()->next->next->data);

    return 0;
}