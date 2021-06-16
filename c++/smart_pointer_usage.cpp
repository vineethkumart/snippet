// auto_ptr deprecated
//
//
//


#include <iostream>
#include <memory>
using namespace std;
int main()
{
    unique_ptr<int> p(new int);
    unique_ptr<int> p1 = p;
    *p = 10;
    std::cout << *p << endl;
    std::cout << &p << endl;

    shared_ptr<int> sp(new int);
    shared_ptr<int> sp1 = sp;

    *sp1 = 12;
    cout << *sp;

    unique_ptr<int> up(new int[10]);
}

