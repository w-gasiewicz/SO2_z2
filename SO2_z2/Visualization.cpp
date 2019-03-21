#include "Visualization.h"
#include <ncurses.h>
#include <iostream>
#include <mutex>

mutex control;

Visualization::Visualization() {
    initscr();
    noecho();
    resizeterm(256,70);
    curs_set(0);
    
}
void Visualization::CreateColors() {
    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);    
    init_pair(6, COLOR_CYAN, COLOR_BLACK);

    bkgd(COLOR_PAIR(1));
}
void Visualization::Legend() {

    attron(COLOR_PAIR(6));
    move(0,1);
    printw("Legend: ");
    move(1,1);
    printw("Press ESC button -> enter to stop");
    attron(COLOR_PAIR(4));

    attron(COLOR_PAIR(3));
    move(2,3);
    addch('\\');
    attron(COLOR_PAIR(1));
    printw(" Fork in use");

    attron(COLOR_PAIR(2));
    move(3,3);
    addch('\\');
    attron(COLOR_PAIR(1));
    printw(" Fork free");

    attron(COLOR_PAIR(2));
    move(4,1);
    addch('\\');
    attron(COLOR_PAIR(1));
    printw("o");
    attron(COLOR_PAIR(2));
    addch('/');
    attron(COLOR_PAIR(1));
    printw(" Philosopher with forks");
    
    attron(COLOR_PAIR(3));
    move(5,1);
    addch('\\');
    attron(COLOR_PAIR(1));
    printw("o");
    attron(COLOR_PAIR(3));
    addch('/');
    attron(COLOR_PAIR(1));
    printw(" Philosopher without forks");

    attron(COLOR_PAIR(6));
    move(0,35);
    printw("Visualisation: ");
    move(6,0);
    printw("Placement of forks and philosophers:");
    attron(COLOR_PAIR(1));
    move(7,1);
    printw("|--------------------|");
    move(8,1);
    printw("-| o | o | o | o | o v");
    move(9,1);
    printw(" 3 3 2 2 1 1 0 0 4 4");
    
    //draw philosophers:
    move(1,35);
    printw("Philosopher 0: ");    
    move(5,35);
    printw("Philosopher 1: ");
    move(9,35);
    printw("Philosopher 2: ");
    move(13,35);
    printw("Philosopher 3: ");
    move(17,35);
    printw("Philosopher 4: ");
    
    attron(COLOR_PAIR(2));
    for(int i=2;i<20;i+=2)
    {
        move(i,35);
        printw("Philosophing time: ");
        i++;
        move(i,35);
        printw("Eating time: ");
        i++;
        move(i,35);
        printw("Time from last meal: ");
    }
    attron(COLOR_PAIR(6));
    move(21,35);
    printw("End visualisation.");
}
void Visualization :: ChangeForkStatus(Philosopher *p){
    
    if(p->id==0)
    {
        move(1,50);
        DrawPhilo(p); 
    }
    else if(p->id==1)
    {
        move(5,50);
        DrawPhilo(p);
    }
    else if(p->id==2)
    {
        move(9,50);
        DrawPhilo(p);
    }
    else if(p->id==3)
    {
        move(13,50);
        DrawPhilo(p);
    }
    else
    {
        move(17,50);
        DrawPhilo(p);   
    }
}
void Visualization :: DrawPhilo(Philosopher *p)
{
    if(!p->leftForkReady)
        attron(COLOR_PAIR(3));
    else
        attron(COLOR_PAIR(2));
    addch('\\');
    attron(COLOR_PAIR(1));
    printw("o");
    if(!p->rightForkReady)
        attron(COLOR_PAIR(3));
    else
        attron(COLOR_PAIR(2));
    addch('/');
    
    int counter=2;    
    attron(COLOR_PAIR(2));
    for(int i=0;i<5;i++)
    {
        if(p->id==i && p->leftForkReady && p->rightForkReady)
        {       
            //counter++;
            //move(counter,48);
            //clrtoeol();
           // counter--;
            move(counter,54);
            printw("%d[ms]",p->GetPhiloTime());        
        }
        else if(!p->leftForkReady && !p->rightForkReady && p->id==i)
        {
            //move(counter,54);
            //clrtoeol();
            counter++;
            move(counter,48);
            printw("%d[ms]",p->GetEatingTime());
            counter--;
        }
        if(p->id==i)
        {
            counter+=2;
            move(counter,56);
            printw("%d[ms]",p->GetTimeFromLastMeal());
            counter-=2;
        }
        counter+=4;
    }   
}
void Visualization :: Start(Fork forks[], Philosopher philosophers[]){
    int inputChar;
    nodelay(stdscr,true);
    CreateColors();
    Legend();    
    while(true)
    {
        inputChar=getch();
        if(inputChar!=27)//while user dont press esc button
        {}
        else
            return;
        
        for(int i=0;i<5;i++)
        {
            //control.lock();
            ChangeForkStatus(&philosophers[i]);
            //control.unlock();
        }
    }
}
Visualization::~Visualization() {
    endwin();//close
}