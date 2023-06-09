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
int main(){
    Queue<int> queue1;
    queue1.pushBack(1);
    queue1.pushBack(2);
    queue1.pushBack(3);
    queue1.pushBack(4);
    queue1.pushBack(5);

    //print queue1
    cout << "queue1: ";
    Queue<int>::Iterator it = queue1.begin();
    while(it != queue1.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    Queue<int> queue2 = queue1;

    queue1.popFront();
    queue1.pushBack(6);

    // print queue2
    cout << "queue2: ";
    Queue<int>::Iterator it2 = queue2.begin();
    while(it2 != queue2.end()){
        cout << *it2 << " ";
        ++it2;
    }

    Queue<int> queue3;
    queue3 = queue2;
    queue2.popFront();
    cout << endl;
    cout << "queue3: ";
    Queue<int>::Iterator it3 = queue3.begin();
    while(it3 != queue3.end()){
        cout << *it3 << " ";
        ++it3;
    }
    cout << endl;



    return 0;
}