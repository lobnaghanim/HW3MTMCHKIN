#include "HealthPoints.h"

HealthPoints::HealthPoints(int max_HP) {
    if(max_HP <= 0){
        throw InvalidArgument();
    }
    HP = max_HP;
    maxHP = max_HP;
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
    if (HP + healthPoints > maxHP) {
        HP = maxHP;
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

bool operator==(const HealthPoints &healthPoints1, const HealthPoints &healthPoints2){
    return healthPoints1.HP == healthPoints2.HP;
}

bool operator!=(const HealthPoints &healthPoints1, const HealthPoints &healthPoints2) {
    return !(healthPoints1 == healthPoints2);
}

bool operator<(const HealthPoints &healthPoints1, const HealthPoints &healthPoints2) {
    return (healthPoints1.HP < healthPoints2.HP);
}

bool operator>=(const HealthPoints &healthPoints1, const HealthPoints &healthPoints2) {
    return !(healthPoints1 < healthPoints2);
}

bool operator>(const HealthPoints &healthPoints1, const HealthPoints &healthPoints2) {
    return healthPoints2 < healthPoints1;
}

bool operator<=(const HealthPoints &healthPoints1, const HealthPoints &healthPoints2) {
    return !(healthPoints1 > healthPoints2);
}

std::ostream& operator<<(std::ostream& stream, const HealthPoints &healthPoints){
    stream << healthPoints.HP << '(' << healthPoints.maxHP << ')';
    return stream;
}

HealthPoints &HealthPoints::operator=(int healthPoints) {
    HealthPoints result = HealthPoints(healthPoints);
    HP = result.HP;
    maxHP = result.maxHP;
    return *this;
}




