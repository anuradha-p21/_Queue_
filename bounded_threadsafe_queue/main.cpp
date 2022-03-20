#include<iostream>
#include<thread>
#include<mutex>
#include <atomic>
#include<unordered_map>
using namespace std;

mutex m1;
int buffer =0;
void task(const char* threadN, int loop)
{
   // unique_lock<mutex>lock(m1);
    for(int i =0; i<loop; ++i)
    {
        buffer++;
       
        cout<< threadN<<" "<< buffer<< endl;
        this_thread::sleep_for(chrono::seconds(3));

    }

}
class mythread {
    static int threadId;
        struct ThreadData
        {
            std::atomic_bool finished;
            std::thread thread;
        };

        std::mutex mMutex;
        std::unordered_map<int, ThreadData> mThreads;
        public : 

      void execute_thread(int id, int client_fd);

     void create_thread(int client_fd);

     


}
int main(){
    thread t0(task, "T0", 10);
     thread t1(task, "T1", 10);
    // t0.join();
    // t1.join();
     return 0;
}