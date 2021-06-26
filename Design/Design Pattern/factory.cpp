// Usual
class Fact {
    Product* Create(type) => Based on type produce and return, Simple factory, not a DP
    // no runtime dispatch. - not good. not closed for modification,
}

What
----
1. virtual constructor, delegate constructor to concrete

Usage
-----
1. Factory => Interface
2. ConcreteFactory => Produces and return 

class Factory {
public:
    virtual Product* Create() = 0;
};

class CarFactory {
    Car* Create() { return new Car(); }
};

int client {
    CarFactory cf;
    Product* p = cf.Create();
}

3. Can add a director if required
