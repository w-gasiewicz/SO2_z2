#include <iostream>
#include <thread>
#include <random>
#include <mutex>
#include "Philosopher.h"
#include "Fork.h"
using namespace std;

static const int numOfPhilosophers=5;
//mutex mu;
thread t[numOfPhilosophers];
Philosopher philosophersTab[numOfPhilosophers];
Fork forks[numOfPhilosophers];

int leftForkID,rightForkID;
    
//int GenerateRandomPhilosopher()
//{//function generates random philosopher number    
//    int value=rand() % 5+0;
//    return value;
//}
void Run(Philosopher *p,int index)
{
    //mu.lock();
            if(index==numOfPhilosophers-1)
                leftForkID=0;
            else
                leftForkID=index+1;
            rightForkID=index;
    //mu.unlock();    
            if(philosophersTab[p->id].isHungry && !forks[leftForkID].isUsed && !forks[rightForkID].isUsed)
            {
                forks[leftForkID].Take();
                forks[rightForkID].Take();
                             
                p->Eating(&philosophersTab[p->id]);
                philosophersTab[p->id].isHungry=false;
                
                forks[leftForkID].Release();
                forks[rightForkID].Release();
            }
            else if(!philosophersTab[p->id].isHungry)
            {
                p->Philosophizing(&philosophersTab[p->id]);
                philosophersTab[p->id].isHungry=true;
           }  
            else
                cout<<"Philospher number: "<<index<<" can't eat becouse of leak of forks."<<endl;
    
}
void CreatePhilosophersAndForks()
{//function create philosophers objects
     for(int i=0;i<numOfPhilosophers;i++)
    {
        philosophersTab[i] =  Philosopher(i,true);//create new philosopher passing id,isPhilosophizing,isEating,isHungry,
        forks[i]=Fork(i,false);//create forks passing id and status(false=is possible to use)
     }
}
int main(int argc, char** argv) 
{       
    CreatePhilosophersAndForks();
    cout<<"Philosophers and forks created."<<endl;
  
    for(int i=0;i<numOfPhilosophers;i++)
    {
        t[i]=thread(Run,&philosophersTab[i],i);
    }
    
    while(true)
    {
//        int index=GenerateRandomPhilosopher();//get random philospher        
//        t[index]=thread(Run,&philosophersTab[index],index);
//        t[index].join();        
        int x=cin.get();
        cout<<x<<endl;
    }
    return 0;
}