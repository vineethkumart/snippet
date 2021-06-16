// Curiously Recurring Template Pattern - This is to achieve compile time polymorphism

#include <iostream>
using namespace std;

template<typename T>
class Base {
public:
    void do_op()
    {
        static_cast<T*>(this)->do_op();
    }
};


class Der1 : public Base<Der1>
{
public:
    void do_op() {
        cout << "dr1"; 
    }
};


class Der2 : public Base<Der2>
{
public:
    void do_op();
};


template<typename T>
void do_op(T& base)
{
    base.do_op();
}

// OR

template<typename T>
void do_op1(Base<T>& base)
{
    base.do_op();
}

int main()
{
    Der1 d;
    do_op(d);
    do_op1(d);
}
