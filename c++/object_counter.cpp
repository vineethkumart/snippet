// Design an object counter
// i.e Cound number of objects created for each object. How can you do this?
//
//
// Basically for a class A, you need a counter and for B you need a counter and so on...
// You can keep the counter as static inside A, B etc but thats not a central access point.
//
// Can use CRTP for this
//

#include <iostream>
using namespace std;

template<typename T>
class Counter {
    static int counter;
    public:
    Counter() { counter++; }
    static int get() { return counter; }
};


template<typename T>
int Counter<T>::counter = 0;

class A : Counter<A>
{
};

class B : Counter<B>
{
};


int main()
{
    A a,b,c,d;
    B p,q;

    cout << Counter<A>::get() << endl;
    cout << Counter<B>::get() << endl;

    return 0;
}
