#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <stdbool.h>
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
using namespace std;

class Philosopher {
public:
    Philosopher();
    int id; 
    bool isHungry;
    bool isThinking;
    bool leftForkReady, rightForkReady;
    int leftForkID,rightForkID;
    int eatingTime,philoTime,timeFromLastMeal;
    Philosopher(int pID, bool pIsHungry);
    void Philosophizing(Philosopher *p);
    void Eating(Philosopher *p); 
    int GetEatingTime();
    int GetPhiloTime();
    void StartTimer();
    void StopTimer();
    int GetTimeFromLastMeal();
    virtual ~Philosopher();
private:    
    double GenerateRandomTime();
    chrono::high_resolution_clock::time_point start , stop;
};

#endif /* PHILOSOPHER_H */

