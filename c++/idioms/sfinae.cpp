// SFINAE: Substitution failure is not an Error
// If there are overloaded parameterized template function, a substitution failure is not an error. Compiler tries to substitute with another available pattern
//
//
//

#include <iostream>
using namespace std;

struct Test {
    using mt = int;
};



template<typename T>
void do_op(typename T::mt x) { // pattern 1
    cout << x;
}

template<typename T>
void do_op(T x) {   // pattern 2
    cout << x;
}


int main()
{
    do_op<Test>(1); // calls pattern 1
    do_op<int>(1); // here pattern sub fails for pattern 1, but compiler ignores and deduces proper pattern

    return 0;
}
