//
// Created by Ali Harbaji on 11/06/2023.
#include <new>

using namespace std;
#include "Queue.h"

//
class ControlledAllocer{
public:
    static int allowedAllocs;
    int someInteger;

    ControlledAllocer()
    {
        if (!allowedAllocs){
            throw std::bad_alloc();
        }
        --allowedAllocs;
    }

    ControlledAllocer(const ControlledAllocer &other)
    {
        if (!allowedAllocs){
            throw std::bad_alloc();
        }
        --allowedAllocs;
    }

    ControlledAllocer &operator=(const ControlledAllocer &other)
    {
        if (!allowedAllocs){
            throw std::bad_alloc();
        }
        --allowedAllocs;
        return *this;
    }
};

// define REQUIRE
#define REQUIRE(condition) \
    if (!(condition)) { \
        std::cout << "Line " << __LINE__ << ": requirement failed: " << #condition << std::endl; \
    }

// define REQUIRE_THROWS_AS
#define REQUIRE_THROWS_AS(expression, exceptionType) \
    try { \
        expression; \
        std::cout << "Line " << __LINE__ << ": expected exception: " << #expression << std::endl; \
    } catch (exceptionType&) { \
    } catch (...) { \
        std::cout << "Line " << __LINE__ << ": wrong exception type: " << #expression << std::endl; \
    }

    // define ControlledAllocer::allowedAllocs
    int ControlledAllocer::allowedAllocs = 1000;
int main() {
    printf("Hello, World!\n");
        ControlledAllocer::allowedAllocs = 1000;
        Queue<ControlledAllocer> q1, q2;
        ControlledAllocer c;
        for (int i = 0; i < 10; i++)
        {
            q1.pushBack(c);
        }

        ControlledAllocer::allowedAllocs = 0;

        REQUIRE_THROWS_AS(q1.pushBack(c), std::bad_alloc);

        REQUIRE_THROWS_AS(q2.pushBack(c), std::bad_alloc);

        ControlledAllocer::allowedAllocs = 5;

        REQUIRE_THROWS_AS(q2 = q1, std::bad_alloc);

        auto newCopyBadAllocerQ = [](Queue<ControlledAllocer> q)
        {
            Queue<ControlledAllocer> newQ(q);
        };
        ControlledAllocer::allowedAllocs = 5;
        REQUIRE_THROWS_AS(newCopyBadAllocerQ(q1), std::bad_alloc);

        auto newConstCopyBadAllocerQ = [](Queue<ControlledAllocer> q)
        {
            const Queue<ControlledAllocer> newQ(q);
        };
        ControlledAllocer::allowedAllocs = 5;
        REQUIRE_THROWS_AS(newConstCopyBadAllocerQ(q1), std::bad_alloc);

        q1.front().someInteger = 666;
        ControlledAllocer::allowedAllocs = 1000;
        Queue<ControlledAllocer> shortQ;
        for (int i = 0; i < 5; i++)
        {
            shortQ.pushBack(c);
        }

        shortQ.front().someInteger = -1;

        ControlledAllocer::allowedAllocs = 2;
        REQUIRE_THROWS_AS(q1 = shortQ, std::bad_alloc); // Use failing assainment operator
        REQUIRE(q1.size() == 10); // Check that q1 wasn't changes

        REQUIRE(q1.front().someInteger == 666); // Check that q1 wasn't changes

        int counter = 0;
        for (ControlledAllocer& data: q1){
            data.someInteger = 1;
            ++counter;
        }
        REQUIRE(counter == 10); // Check that q1 wasn't changes


    return 0;
}
