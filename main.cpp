#include <iostream>
using namespace std;
#include "HealthPoints.h"
#include "Queue.h"
int main(){
    Queue<int> queue1;
    queue1.pushBack(67);
    queue1.pushBack(2);
    queue1.pushBack(3);

    int front1 = queue1.front(); /* front1 equals 1 as it's the first value */
    printf("front1 = %d\n", front1);
    queue1.front() = 1; /* queue1 content is: 3, 2 (left to right) */
    front1 = queue1.front(); /* front1 now equals 3 */
    printf("front1 = %d\n", front1);


    printf("q1 first element: %d\n", queue1.front());
    printf("q1 second element: %d\n", queue1.head->next->data);
    printf("q1 third: %d\n", queue1.tail->data);

    printf("-------popped front-------\n");
    queue1.popFront(); /* queue1 content is: 2 */

    printf("q1 first element: %d\n", queue1.front());
    return 0;
}