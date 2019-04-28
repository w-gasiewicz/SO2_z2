 #include "Philosopher.h"
#include <iostream>
#include <random>
#include <thread>
default_random_engine re;
Philosopher::Philosopher()
{

}

Philosopher::Philosopher(int pID,bool pIsHungry) 
{
     id=pID;
     isHungry=pIsHungry;
     isThinking=false;
     leftForkReady=false;
     rightForkReady=false;
     eatingTime=0;
     philoTime=0;
     timeFromLastMeal=0;
     if(pID==4)
                leftForkID=0;
     else
        leftForkID=pID+1;
     rightForkID=pID;
}
void Philosopher :: Philosophizing(Philosopher *p)
{
    double time=GenerateRandomTime();
    int timeToWait=round(time*1000.0);
    p->philoTime=timeToWait;
    this_thread :: sleep_for(chrono :: milliseconds(timeToWait));
 }
void Philosopher :: Eating(Philosopher *p)
{
    double time=GenerateRandomTime();
    int timeToWait=round(time*1000.0);
    p->eatingTime=timeToWait;
    this_thread :: sleep_for(chrono :: milliseconds(timeToWait));
    }

double Philosopher :: GenerateRandomTime()
{//function generates random time in seconds as double value
    uniform_real_distribution<double> unif(2,5);    
    double value=unif(re);
    return value;
}
int Philosopher :: GetEatingTime()
{
    return this->eatingTime;
}
int Philosopher :: GetPhiloTime()
{
    return this-> philoTime;
}
void Philosopher :: StartTimer()
{
        start = chrono::high_resolution_clock::now();
}
void Philosopher :: StopTimer()
{    
	stop = chrono::high_resolution_clock::now();
        timeFromLastMeal = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
}
int Philosopher :: GetTimeFromLastMeal()
{
    return this->timeFromLastMeal;
}
Philosopher::~Philosopher() {
}

