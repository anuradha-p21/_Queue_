
#include<iostream>
#include<vector>
using namespace std;

class MyQueue{

    private:
        // store elements
        vector<int> data;       
        // a pointer to indicate the start position         
    public:
        MyQueue() {}
        /** Insert an element into the queue. Return true if the operation is successful. */
         bool enQueue(int x);
        /** Delete an element from the queue. Return true if the operation is successful. */
        bool deQueue();
        /** Get the front item from the queue. */ 
        int Front();
        /** Get the size of the queue. */ 
        int sizeQ();
        bool isEmpty();
};