#include <iostream>


using namespace std;
#include "HealthPoints.h"

int main(){
    HealthPoints h1;
    h1.HP = 70;
    printf("h1: %d\n", h1.HP);

    h1+= 10;
    printf("h1: %d\n", h1.HP);

    printf("h1 + 10: %d\n", (h1 + 10).HP); // 90

    printf("10 + h1: %d\n", (10 + h1).HP); // 90


    printf("h1 - 10: %d\n", (h1 - 10).HP); // 70
//    printf("10 - h1: %d\n", (10 - h1).HP); // 0

    printf("h1: %d\n", h1.HP); // 80
}