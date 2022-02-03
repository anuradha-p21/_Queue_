#include"tsafe_queue.hpp"

/** it returns the element at the head of the queue */
int Tqueue :: front()
{
    unique_lock<mutex>mlock(Qmut);
    while (q.empty())
    {
        cout<< " Queue is empty , waiting on front..."<< endl;
        Qcond.wait(mlock);
    }
    return q.front();
}

 /** returns the size of the queue **/
int Tqueue ::  sizeQ()
{   unique_lock<mutex>mlock(Qmut);
    return q.size();
}

/* returns true if queue is empty or false if not.*/
bool Tqueue :: isEmpty()  
{
    if(q.size() > 0){
        return false;
    }
    return true;
}

/* This adds the incoming element at the tail of the queue */
bool Tqueue :: enQueue(int x)
{
    if(sizeQ() < QMAX_SIZE)
    {
         unique_lock<mutex>mlock(Qmut);
         q.push(x);
         mlock.unlock();
         Qcond.notify_one();
         return true;
    }
    return false;
}

/* deletes the head element of the queue */
  void Tqueue:: deQueue(){
       unique_lock<mutex>mlock(Qmut);
       while(isEmpty())
       {
           cout<< "Queue is empty, waiting on deQueue ... "<<endl;
           Qcond.wait(mlock);
       }
       q.pop();
  }

  