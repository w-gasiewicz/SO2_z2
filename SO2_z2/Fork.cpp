#include "Fork.h"
#include <vector>
#include <mutex>

    mutex mx;
Fork::Fork() {
}

Fork::Fork(int forkID,bool forkIsUsed) {
    id=forkID;
    isUsed=forkIsUsed;
}
void Fork::Release() {
    mx.lock();
    isUsed=false;
    mx.unlock();
}
void Fork::Take(){
    mx.lock();
    isUsed=true;
    mx.unlock();
}
Fork::~Fork() {
}

