#include"queue_vector.hpp"

int main() {
    MyQueue q;
    q.enQueue(5);
    q.enQueue(3);
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
    q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
   // q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
}

