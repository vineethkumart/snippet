// compile time polymorphism

#include <iostream>
using namespace std;

typedef enum {
    type_1,
    type_2,
    type_3
} types_t;


class Base {
public:
    void common_fn() {
        cout << "Base common activities\n";
    }
};


template<types_t T>
class Der : public Base {
public:
    void common_fn() {                           // function overriding
        // nothing but do the common activities
        Base::common_fn();
        cout << "Der common\n";
    }
};


template<>
void Der<type_1>::common_fn() {
    Base::common_fn();
    cout << "Der type 1 common\n";
}

template<>
void Der<type_2>::common_fn() {
    Base::common_fn();
    cout << "Der type 1 common\n";
}


template<types_t T>
void fn(Base* b)
{
    b->common_fn();
}

/*
template<>
void fn<type_1> fn(Base* b) {
    Der<types_t>* d = static_cast<Der<types_t>*>(b);
    d->common_fn();
}
*/


template<typename T>
void doit() {};

template<int N>
void doit<10>() { cout << "10"; }


int main()
{
    Der<type_1> d;
    fn<type_1>(&d);
    return 0;
}
