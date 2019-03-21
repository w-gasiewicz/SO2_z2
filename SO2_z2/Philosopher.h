#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <stdbool.h>
#include <iostream>
#include <random>
#include <thread>
using namespace std;

class Philosopher {
public:
    Philosopher();
    int id; 
    bool isHungry;
    bool isThinking;
    bool leftForkReady, rightForkReady;
    bool canEat;
    int leftForkID,rightForkID;
    int eatingTime,philoTime,timeFromLastMeal;
    Philosopher(int pID, bool pIsHungry);
    void Philosophizing(Philosopher *p);
    void Eating(Philosopher *p); 
    int GetEatingTime();
    int GetPhiloTime();
    int GetTimeFromLastMeal();
    virtual ~Philosopher();
private:    
    double GenerateRandomTime();
};

#endif /* PHILOSOPHER_H */

