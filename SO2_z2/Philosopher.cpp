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
}
void Philosopher :: Philosophizing(Philosopher *p)
{
    cout<<"Philosopher number: "<<p->id<<" is philosophizing."<<endl;  
    auto start= chrono :: high_resolution_clock::now();
    double time=GenerateRandomTime();
    int timeToWait=round(time*1000.0);
    
    this_thread :: sleep_for(chrono :: milliseconds(timeToWait));
    
    auto stop = chrono:: high_resolution_clock::now();      
    
    cout<< "Philosophizing taken: "<<chrono :: duration_cast<chrono :: milliseconds>(stop-start).count()/1000.0<<"s"<<endl;
    }
void Philosopher :: Eating(Philosopher *p)
{     
    cout<<"Philosopher number: "<<p->id<<" is eating."<<endl; 
    auto start= chrono :: high_resolution_clock::now();
    
    double time=GenerateRandomTime();
    int timeToWait=round(time*1000.0);
    
    this_thread :: sleep_for(chrono :: milliseconds(timeToWait));
    
    auto stop = chrono:: high_resolution_clock::now();      
    cout<< "Eating taken: "<<chrono :: duration_cast<chrono :: milliseconds>(stop-start).count()/1000.0<<"s"<<endl;
 }
double Philosopher :: GenerateRandomTime()
{//function generates random time in seconds as double value
    uniform_real_distribution<double> unif(2,5);    
    double value=unif(re);
    return value;
}
Philosopher::~Philosopher() {
}

