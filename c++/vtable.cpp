#include <iostream>


using namespace std;
struct A {
    virtual void print() { cout << "A" << endl;}
    void privatef() { cout << "PA" << endl; }
};

struct B : virtual public A {
    virtual void print() { cout << "B" << endl;}
    void privatef() { cout << "PB" << endl; }
};

struct C : public B {
    virtual void print() { cout << "C" << endl;}
    void privatef() { cout << "PC" << endl; }

};

struct D : virtual public A {
    virtual void print() { cout << "D" << endl;}
    void privatef() { cout << "PC" << endl; }
};


struct diamond : B,D 
{
    virtual void print() { cout << "diamond" << endl;}
    void privatef() { cout << "Pdi" << endl; }

};



int main()
{
    /*
    A* a = new C();
    a->print();

    B* b = static_cast<B*>(a);
    b->print();

    C* c = static_cast<C*>(b);
    c->print();
    */


    diamond* d = new diamond;

    cout << d << endl;
    B* bd = static_cast<B*>(d);
    cout << bd << endl;
    D* dd = static_cast<D*>(d);
    cout << dd << endl;

    A* d1 = static_cast<A*>(bd);
    cout << d1 << endl;

    return 0;
}
