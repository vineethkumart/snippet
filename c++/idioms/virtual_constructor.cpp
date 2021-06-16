// This is a very good thing to know just like other idioms
//
//
// We have this concept of virtual destructor i.e
//

#include <iostream>
using namespace std;
class animal {
public:
    ~animal() {
        cout << "animal destructed\n";
    }

    virtual void who() = 0;

    virtual animal* construct_me() = 0;
};

class dog : public animal {
public:
    ~dog() {
        cout << "animal destructed\n";
    }
    void who() { cout << "dog"; }

    animal* construct_me() {
        return new dog();
    }
};


void delete_me(animal* a)
{
    delete a;
}

animal* create_another(animal* a)
{
    // can this be done?
    // Yes by using Factory Design Pattern. i.e Delegate the construction to the concrete class
    return a->construct_me();
}

int main()
{
    animal *a = new dog();
    delete_me(a);


    dog* d = new dog();
    animal* b = create_another(d);

    b->who();

    return 0;
}




// Use case: Designing a generic create/clone - Define on base class virtual and implement in concrete class
