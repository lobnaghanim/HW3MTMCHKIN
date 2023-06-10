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

    bool comparisonResult;
    HealthPoints healthPoints1(100);
    HealthPoints healthPoints2 = 100; /* 100 points out of 100 */
    cout << healthPoints1 << endl;
    comparisonResult = (healthPoints1 == healthPoints2); /* returns true */
    cout << comparisonResult << endl;
    healthPoints2 = HealthPoints(150); /* has 150 points out of 150 */
    cout << healthPoints2 << endl;
    comparisonResult = (healthPoints1 == healthPoints2); /* returns false */
    cout << comparisonResult << endl;
    healthPoints2 -= 50; /* now has 100 points out of 150 */
    cout << healthPoints2 << endl;
    comparisonResult = (100 == healthPoints2); /* returns true */
    cout << comparisonResult << endl;
    comparisonResult = (healthPoints1 < healthPoints2); /* returns false */
    cout << comparisonResult << endl;
    healthPoints1 -= 50; /* now has 50 points out of 100 */
    cout << healthPoints1 << endl;
    comparisonResult = (healthPoints1 < healthPoints2); /* returns true */
    cout << comparisonResult << endl;

    return 0;
}

