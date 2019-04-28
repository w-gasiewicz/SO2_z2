#include <iostream>
#include <thread>
#include <random>
#include "Philosopher.h"
#include "Fork.h"
#include "Visualization.h"
#include <mutex>
using namespace std;

static const int numOfPhilosophers=5;
thread t[numOfPhilosophers];
Philosopher philosophersTab[numOfPhilosophers];
Fork forks[numOfPhilosophers];
bool running=true;
mutex mut;

void Run(Philosopher *p)
{
    p->StartTimer();
    while(running)
    {
            if(philosophersTab[p->id].isHungry && !forks[p->leftForkID].isUsed)
            {//take up left fork
                forks[p->leftForkID].Take();
                p->leftForkReady=true;
            }
            if(philosophersTab[p->id].isHungry && !forks[p->rightForkID].isUsed)
            {//take up right fork
                forks[p->rightForkID].Take();
                p->rightForkReady=true; 
            }
            if(philosophersTab[p->id].isHungry && !philosophersTab[p->id].rightForkReady && philosophersTab[p->id].leftForkReady)
            {//if right fork wasn't taken put down left one
                forks[p->leftForkID].Release();
                p->leftForkReady=false;
            }
            if(philosophersTab[p->id].isHungry && philosophersTab[p->id].rightForkReady && !philosophersTab[p->id].leftForkReady)
            {//if left fork wasn't taken put down left one
                forks[p->rightForkID].Release();
                p->rightForkReady=false;
            }
            if(philosophersTab[p->id].leftForkReady && philosophersTab[p->id].rightForkReady)
            {//if philosopher have two fork he can eat                
                p->StopTimer();
                p->Eating(&philosophersTab[p->id]);
                philosophersTab[p->id].isHungry=false;
                   
                forks[p->leftForkID].Release();
                p->leftForkReady=false;
                forks[p->rightForkID].Release();
                p->rightForkReady=false;
                p->StartTimer();
            }
            else
            {//else he have to think
                p->Philosophizing(&philosophersTab[p->id]);
                philosophersTab[p->id].isHungry=true;
            }
    }
}
void CreatePhilosophersAndForks()
{//function create philosophers objects
     for(int i=0;i<numOfPhilosophers;i++)
    {
        philosophersTab[i] =  Philosopher(i,false);//create new philosopher passing id and isHungry,
        forks[i]=Fork(i,false);//create forks passing id and status(false=is possible to use)
     }
}
int main(int argc, char** argv) 
{       
    CreatePhilosophersAndForks();//run create philosophers and forks function
    for(int i=0;i<numOfPhilosophers;i++)
    {
        t[i]=thread(Run,&philosophersTab[i]);
    }
    
    Visualization vs = Visualization();
    vs.Start(philosophersTab);
    
    running=false;
    
    for(int i=0;i<numOfPhilosophers;i++)
    {
        t[i].join();
    }
    
    return 0;
}