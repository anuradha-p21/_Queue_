#include<iostream>
#include<queue>
#include<mutex>
#include <condition_variable>
using namespace std;


#define QMAX_SIZE 10

#include<iostream>
#include<queue>
using namespace std;

class Tqueue{
    queue<int> q;
    mutex Qmut;
    condition_variable Qcond;
    int size;

    public:
    Tqueue(){}
    /* add and element to the queue at the tail. */
     bool enQueue(int x);
    /** Delete an element from the queue head. Return true if the operation is successful. */
    void deQueue();
    /** Get the front item from the queue. */ 
    int front();
    /** Get the size of the queue. */ 
    int sizeQ();
    /* check if queue is empty or not */
    bool isEmpty();
};