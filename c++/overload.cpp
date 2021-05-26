#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class Base {
public:
    Base(T d = 0) : id(d), a{d} {}


    Base(const Base& rhs) {
        //(void)operator=(rhs);
        id = rhs.id;
        memcpy(a, rhs.a,sizeof(a));
    }

    Base& operator=(const Base& rhs) {
        id = rhs.id;
        memcpy(a, rhs.a,sizeof(a));
        return *this;
    }

    T& operator[](int idx) { return a[idx]; }

private:
    T id;
    T a[10];
};

int main()
{
    Base<int> b(1);
    Base <int> c(2);

    Base<int> d, e;
    (d = c) = b; // if the assignment return Base instead of Base& this will give 2 instead of 1 ass d=c creates a new temp variable

    cout << d[0];
}
