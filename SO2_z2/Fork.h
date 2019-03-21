#ifndef FORK_H
#define FORK_H
#include <vector>
#include <mutex>
using namespace std;
class Fork {
public:
    Fork();
    Fork(int forkID,bool forkIsUsed);
    void Take();
    void Release();
    virtual ~Fork();
    int id;
    bool isUsed;
private:
    //mutex _mx;
};

#endif /* FORK_H */

