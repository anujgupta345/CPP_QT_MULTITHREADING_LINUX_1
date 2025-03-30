#include <iostream>
#include <queue>
#include <vector>
#include <atomic>
int main()
{
    std::cout<<"Hello World" << std::endl;
    auto comp = [](int a, int b){return a<b;};
    std::priority_queue<int, std::vector<int>, decltype(comp) > pq(comp);
    for (size_t i = 0; i < 10; i++)
    {
        pq.push(i);
    }

    std::cout<<"top " << pq.top() << std::endl;
    pq.pop();
    std::cout<<"top " << pq.top() << std::endl;
    
}