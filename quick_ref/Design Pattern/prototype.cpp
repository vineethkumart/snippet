What
----
1. Clone
2. Useful if object creation is expensive

How
---
1. Clonable Interface
2. Product Base from Clonable
3. Concrete

Application
------------
1. Drag and Drop shapes/cloning etc.,
2. Create 100 players for a game etc.,


class Clonable {
public:
    virtual Clonable* clone() = 0;
};

class Product : public Clonable {

};

class Car : public Product {
    Car* clone() {
        Car* c = new Car(*this);
        return c;
    }
};

client()
{
    CarBuilder cb;
    cb.Build();
    Car* c = cb.Get();
    Car* d = c->clone();
}