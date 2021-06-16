#include <iostream>


using namespace std;

template<typename T>
class up
{
public:
    up() : p(0) {}
    up(T* p) : p(p) {}
    ~up() {
        delete[] p;
    }

    void set(T* t) {
        p = t;
    }
    T* get() { return p; }

    T& operator*() { return *p; }
    const T operator&() { return p; }

    up(const up&) = delete; // prevent copy
    T& operator=(const T& rhs) = delete;
private:
    T* p;
};

int main()
{
    up<int> p(new int);
    up<int> p1 = p;
    *p = 12;
    cout << *p;
    return 0;
}


template<typename T>
class sp {
public:
    sp() : p(0) {}
    sp(T* p) : p(p) {}

    ~sp() { 
        if (counter == 0) delete[] p;
        counter--;
    }

    sp(const sp& that) {
        counter++;

    }

    sp& operator=(const sp& that) {
        counter++;
    }

private:
    unsigned int counter;
    T* p;
};
