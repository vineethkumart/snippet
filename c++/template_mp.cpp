#include <iostream>
using namespace std;

template<typename T, int SIZE>
class arr {
public:
    arr() {}

private:
    T _a[SIZE];
};


template<int N>
struct fact
{
    static const int val = N * fact<N-1>::val;
};

template<>
struct fact<1> {
    static const int val = 1;
};


int main()
{
    cout << fact<5>::val;
    return 0;
}
