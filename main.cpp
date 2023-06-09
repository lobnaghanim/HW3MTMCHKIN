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

    // modify queue1
    Queue<int> queue2 = queue1;

    try {
        queue2 = queue1;
        queue1.pushBack(6);
        queue1.pushBack(7);
        queue1.pushBack(8);

        //print queue1
        cout << "queue1: ";
        it = queue1.begin();
        while(it != queue1.end()){
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        // print queue2
        cout << "queue2: ";
        it = queue2.begin();
        while(it != queue2.end()){
            cout << *it << " ";
            ++it;
        }
        cout << endl;

    }catch (Queue<int>::Iterator::InvalidOperation& e){
        // rethrow error
        ::printf("\nOperation not allowed\n");
    }



    return 0;
}