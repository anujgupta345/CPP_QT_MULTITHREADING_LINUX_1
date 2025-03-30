#include <iostream>


// error: call of overloaded 'process(int)' is ambiguous
//    27 |     process(10);

// void process(int a)
// {
//     std::cout<< "process(int a)" ;
//     std::cout << a << std::endl;
// }
// error: call of overloaded 'process(int)' is ambiguous
//    27 |     process(10);

void process(int& a)
{
    std::cout<< "process(int a)" ;
    std::cout << a << std::endl;
}

void process(int && a)
{
    std::cout<< "process(int && a)";
    std::cout << a << std::endl;
}
// template <typename T>
// void forwarder(T && a)
// {
//     process(std::forward<T>(a));
// }


int main()
{

    int a = 20;
    process(10);
    process(a);
    return 0;
}
// output:
// process(int && a)10
// process(int a)20
//process with int and int && will give complilation error only when process(10) is called because here 10 as temp value can be 
//passed to any of these two