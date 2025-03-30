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

void process(int & a)
{
    std::cout<< "process(int a)" ;
    std::cout << a << std::endl;
}

void process(int && a)
{
    std::cout<< "process(int && a)";
    std::cout << a << std::endl;
}

void process(int && a, int &b, int && c)
{
    std::cout<< "process(int && a, int &b, int && c)";
    std::cout << a << " " << b << " " << c << std::endl;
}

void process(int & a, int &&b, int & c)
{
    std::cout<< "process(int & a, int &&b, int & c)";
    std::cout << a << " " << b << " " << c << std::endl;
}

template <typename ...T>
void forwarder(T && ...a)
{
    process(std::forward<T>(a)...);
}



int main()
{

    int a = 20;
    int b = 30;
    forwarder(10);
    forwarder(a);
    forwarder(10, a, 20);
    forwarder(a, 40, b);

    return 0;
}
//output:
// process(int && a)10
// process(int a)20
// process(int && a, int &b, int && c)10 20 20
// process(int & a, int &&b, int & c)20 40 30
//std::forward pass the correct lvalue/rvalue ness to called function without forward it will be treated as lvalue
//use it in evry nested call wherever we need r value to pass to another function