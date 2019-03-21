#ifndef VISUALIZATION_H
#define VISUALIZATION_H
#include "Philosopher.h"
#include "Fork.h"
#include <ncurses.h>
class Visualization {
public:
    Visualization();
    void Start(Fork forks[],Philosopher philosophers[]);
    virtual ~Visualization();
private:
    void CreateColors();
    void Legend();
    void ChangeForkStatus(Philosopher *p);
    void DrawPhilo(Philosopher *p);
};

#endif /* VISUALIZATION_H */

