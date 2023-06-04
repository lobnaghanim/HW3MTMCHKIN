#ifndef HEALTHPOINTS_H
#define HEALTHPOINTS_H
#define MAXHP 100



class HealthPoints {

public:
    explicit HealthPoints(int max_HP = MAXHP);
    class InvalidArgument {};
    HealthPoints& operator-=(int healthPoints);
    HealthPoints& operator+=(int healthPoints);

    friend HealthPoints operator+(const HealthPoints& healthPoints ,int healthPointsToAdd);
    friend HealthPoints operator+(int healthPointsToAdd, const HealthPoints& healthPoints);

    friend HealthPoints operator-(const HealthPoints& healthPoints ,int healthPointsToSub);
    friend HealthPoints operator-(int healthPointsToSub, const HealthPoints& healthPoints) = delete;


    int HP;
private:
    int maximum_HP;


};



#endif