#include "HealthPoints.h"

HealthPoints::HealthPoints(int max_HP) {
    if(max_HP <= 0){
        throw HealthPoints::InvalidArgument();
    }
}

