#include <iostream>
#include <functional>
class LambdaTester
{
    public:
    std::function<int(void)> testLambda();
    LambdaTester();
    int someVar1;
};
int main()
{
    LambdaTester tester;
    auto lam = tester.testLambda();
    lam(); // otherwise only returns function and if not called values wont change
    std::cout << tester.someVar1;
    return 0;
}

std::function<int(void)> LambdaTester::testLambda()
{
    return [*this](){
        someVar1 = 2;// error
        return someVar1;
    };
}
/*
* [] => this wont pass - using member var => compile error
* [this] => this will pass by ref
* [&] => this will pass by ref
* [=] => this will pass by ref
* [*this] => this will pass by value => writing to member variable => compile error
*/
LambdaTester::LambdaTester():someVar1(1)
{
}
