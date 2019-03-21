#include "Fork.h"
#include <vector>
#include <mutex>
    mutex _mx;
Fork::Fork() {
}

Fork::Fork(int forkID,bool forkIsUsed) {
    id=forkID;
    isUsed=forkIsUsed;
}
void Fork::Release() {
    _mx.lock();
    isUsed=false;
    _mx.unlock();
}
void Fork::Take(){
    _mx.lock();
    isUsed=true;
    _mx.unlock();
}
Fork::~Fork() {
}

