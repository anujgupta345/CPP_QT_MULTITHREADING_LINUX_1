#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <queue>

std::queue<int> q;
std::mutex mx;
std::condition_variable cond_var;
uint16_t queueSize = 1000;
int main()
{
    std::thread producer([](){

        for (size_t i = 1; i <= queueSize; i++)
        {
            std::unique_lock<std::mutex> lock(mx);
            std::cout << "pushing " << i << " " << std::endl;
            q.push(i);
            cond_var.notify_one();
        }
        

    });

    std::thread consumer([](){

        for (size_t i = 1; i <= queueSize; i++)
        {
            std::unique_lock<std::mutex> lock(mx);
            cond_var.wait(lock, []() {return !q.empty();});// if second argument is false cond var will wait
            std::cout << "reading";
            std:: cout << q.front() << std::endl;
            q.pop(); // so that example will return the recent pushed value otherwise front 
            //will give same value and we don't know about the new value pushed
        }
        

    });


    producer.join();
    consumer.join();


    return 0;
}