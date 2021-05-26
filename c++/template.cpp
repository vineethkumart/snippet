#include <iostream>

using namespace std;
template<typename T>
class A {
public:
    A() : id(0) {}
    A(int i) : id(i) {}

/* there are 2 ways of writing copy construtors for a templated class
 * if you want enforce that A<int> gets initialized with another A<int>only, then don't use any other new type U for the rhs
 * else you can use compatible types*/
    template<typename U>
    A(const A<U>& rhs) {
        id = rhs.id;
    }
    // or you can support specialized overloading
    A(const A<int>& rhs) {
        id = rhs.id;
    }

    // same goes here
    template<typename U>
    A& operator=(const A<U>& rhs)
    {
        id = rhs.id;
    }

public:
    T id;
};

int main()
{
    A<char> a(1);
    A<int> b(a);

    cout << b.id;
    return 0;
}
