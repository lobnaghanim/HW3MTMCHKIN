#include <iostream>
using namespace std;
#include "HealthPoints.h"
#include "Queue.h"

bool isEven(int n){
    return !(n % 2);
}

int main(){
    Queue<int> queue1;
    queue1.pushBack(1);
    queue1.pushBack(2);
    queue1.pushBack(3);
    queue1.pushBack(4);
    queue1.pushBack(5);
    queue1.pushBack(6);

   Queue<int> queue2 = filter(queue1, isEven);

    printf("queue 2 first element: %d\n", queue2.front());
    printf("queue 2 second element: %d\n", queue2.getHead()->next->data);
    printf("queue 2 third element: %d\n", queue2.getHead()->next->next->data);

    return 0;
}