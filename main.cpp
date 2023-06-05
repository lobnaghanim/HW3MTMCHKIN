#include <iostream>
using namespace std;
#include "HealthPoints.h"
#include "Queue.h"
int main(){
    Queue<int> q1;
    q1.pushBack(67);
    q1.pushBack(68);

    printf("q1.head() = %d\n", q1.head->data);
    printf("q1.tail() = %d\n", q1.tail->data);

    return 0;
}