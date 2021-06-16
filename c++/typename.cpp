#include <iostream>

using namespace std;

struct X {
    typedef enum {
        c1,
        c2
    } type_t;
};

template<typename T>
struct Y {
    Y() {
	typename T::type_t t; /*typename.cpp:15:9: error: need ‘typename’ before ‘T::type_t’ because ‘T’ is a dependent scope */

    }
};

int main()
{
    Y<X> t;
    return 0;
}
