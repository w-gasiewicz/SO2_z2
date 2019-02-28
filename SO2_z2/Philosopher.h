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
    Philosopher(int pID, bool pIsHungry);
    void Philosophizing(Philosopher *p);
    void Eating(Philosopher *p); 
    virtual ~Philosopher();
private:    
    double GenerateRandomTime();
};

#endif /* PHILOSOPHER_H */

