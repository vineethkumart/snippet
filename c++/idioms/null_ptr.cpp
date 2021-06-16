#define NULL ((void*)0);
//int *x = NULL; // this will fail in C++ because a void can't be converted implicitly to a int* or anything in C++



/*so we have to define as
 * #define NULL 0;
 *
 * */

// How the nullptr in c++ would have been implemented then? its not #define then? 
//
// ==> This is a very very good one!!!
//
//
// Can use the Return type Return Type Resolver for this


// remember nullptr is an object not class
#include <iostream>
class null_t {
public:
    template<typename T>
    operator T *() {
        return 0;
    }

    template<typename T, typename C>
    operator T C::*() {
        return 0; 
    }

    void operator&() = delete;

} np;

int main()
{
    int  *x = np;
    char *c = np;

    std::cout << x;
    std::cout << &x;

    std::cout << &np; // error
    return 0;
}


