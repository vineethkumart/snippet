// Excellent one to know!!!

/*
 * Use case. Define a class for 2D array. 
 * Challenge: A[][] needs to be supported i.e double operator overloading.
 *
 * */

#include <iostream>
using namespace std;
template<int n>
class twod {
public:
    twod() {
        a[0][0] = 12;
        a[1][1] = 13;
        a[1][2] = 99;
    }

    /*
    int operator[](int idx) {
        return a[idx][idx];
    }*/

    // how then operator[][]?

    /* Invalid 
    int operator[][](int i, int j) {
        return a[i][j];
    }
    */

    /* The  way this can be done is to introduce a proxy class. This is like our type-erasure
     * on operator[] on twod class return the proxy class
     * and then compiler wil call operator[] on the proxy class -> This will give the final value
     * */


private:
    class proxy {
        public:
        proxy(int* a) : a(a) {}
        int& operator[](int idx) { return a[idx]; }
        private:
        int* a;
    };

public:
    proxy operator[](int idx) {
        return proxy(a[idx]);
    }

private:
    int a[n][n];
};


int main()
{
    twod<5> a;
    cout << a[1][2];


    // how can we get a[0][0]
}
