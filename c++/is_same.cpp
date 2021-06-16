#include <iostream>
using namespace std;

template<typename U, typename V>
class same {
public:
    const static bool value = false;
};


template<typename U>
class same<U, U> {
public:
    const static bool value = true;
};


template<typename U, typename V>
bool same_v()


int main()
{
    cout << same<int, int>::value << endl;
    cout << same<int, char>::value << endl;

    return 0;
}
