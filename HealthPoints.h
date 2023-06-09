#ifndef HEALTHPOINTS_H
#define HEALTHPOINTS_H
#define MAXHP 100
#include <iostream>


class HealthPoints {

public:
    HealthPoints(int max_HP = MAXHP);
    class InvalidArgument {};
    HealthPoints& operator-=(int healthPoints);
    HealthPoints& operator+=(int healthPoints);

    // we need HealthPoints hp = 100; to work and HealthPoints constructor to be explicit
    // so we need to define operator= for int
//    HealthPoints& operator=(int healthPoints);

    friend HealthPoints operator+(const HealthPoints& healthPoints , int healthPointsToAdd);
    friend HealthPoints operator+(int healthPointsToAdd, const HealthPoints& healthPoints);

    friend HealthPoints operator-(const HealthPoints& healthPoints ,int healthPointsToSub);
    friend HealthPoints operator-(int healthPointsToSub, const HealthPoints& healthPoints) = delete;

    friend bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
    friend bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

    friend bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
    friend bool operator>= (const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
    friend bool operator> (const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
    friend bool operator<= (const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);

    friend std::ostream& operator<<(std::ostream& stream, const HealthPoints& healthPoints);

protected:


    int HP; // move later to private
    int maxHP;
};



#endif