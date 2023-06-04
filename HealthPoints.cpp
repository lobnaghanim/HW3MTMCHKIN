#include "HealthPoints.h"

HealthPoints::HealthPoints(int max_HP) {
    if(max_HP <= 0){
        throw HealthPoints::InvalidArgument();
    }
    HP = max_HP;
    maximum_HP = max_HP;
}

HealthPoints& HealthPoints::operator-=(int healthPoints) {
    if(HP - healthPoints < 0){
        HP = 0;
    }
    else{
        HP -= healthPoints;
    }
    return *this;
}

#include <iostream>
HealthPoints& HealthPoints::operator+=(int healthPoints) {
    if (HP + healthPoints > maximum_HP) {
        HP = maximum_HP;
    } else {
        HP += healthPoints;
    }
    return *this;

}

HealthPoints operator+(const HealthPoints& healthPoints ,int healthPointsToAdd){
    HealthPoints result = healthPoints;
    result += healthPointsToAdd;
    return result;
}
HealthPoints operator+(int healthPointsToAdd, const HealthPoints& healthPoints){
    HealthPoints result = healthPoints;
    result += healthPointsToAdd;
    return result;
}

HealthPoints operator-(const HealthPoints &healthPoints, int healthPointsToSub) {
    HealthPoints result = healthPoints;
    result -= healthPointsToSub;
    return result;
}

//HealthPoints operator-(int healthPointsToSub, const HealthPoints &healthPoints) {
//    HealthPoints result = healthPoints;
//    result -= healthPointsToSub;
//    return result;
//}
