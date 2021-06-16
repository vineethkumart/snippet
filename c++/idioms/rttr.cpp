/*
Return Type Resolve
------------------
C++ function overloading wont work just by changing the return type. This is becuase the function can be called without getting its return type.
How can you write C++ function that can be overloaded on return type?

Sample uses:
Lets say we have to initialize a STL vector/list/map by taking return of a function.
We can't write something like
template<typename T>
T init(int n) {
    // generate n random values
    return T{v1,v2,v3};
}

vector<int> v = init(10);
list<int> l = init(10);

This is not possible without code duplication. how can we solve this?

Solution is Using Functor that overlads the
*/

//RTTR
//---

#include <iostream>
#include <vector>
#include <set>


using namespace std;

template<typename T>
class init {};

template<>
class init<int>
{
public:
    init(const int size) : size(size) {}

    template<typename Container>
    operator Container() {
        Container c;
        for (int i = 0; i < size; i++) {
            c.insert(c.end(), i);
        }

        return c;
    }

    // this is the way normal overloading of () works. The above one is not a functor.
    // just ignore this
    int operator()(int i)  {
        return i;
    }

private:
    int size;
};


int main()
{
    vector<int> v = init<int>(10);
    set<int> s = init<int>(10);
    init<int>(10);

    for (auto i : v) {
        cout << i << " ";
    }

    cout << endl;

    for (auto i : s) {
        cout << i << " ";
    }

    return 0;

}

