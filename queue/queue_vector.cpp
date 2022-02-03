#include"queue_vector.hpp"
#include<vector>

         /** Insert an element into the queue. Return true if the operation is successful. */ 
       bool MyQueue :: enQueue(int x) {
            data.push_back(x);
            return true;
        }
         /** Checks whether the queue is empty or not. */
        bool MyQueue ::isEmpty()  {
            if(data.size() > 0)
                return false;
            return true;
        }
        /** Delete an element from the queue. Return true if the operation is successful. */
       bool MyQueue ::  deQueue() {
            int r;
            if (isEmpty()) {
                return false;
            }
            //delete the first element
            data.erase(data.begin());
            return true; 
        }

        int MyQueue::  Front() {
            return data[0];
        }
       
        /** returns the size of thr queue **/
        int MyQueue ::  sizeQ()
        {
            return data.size();
        }

