What
-----
1. Loose coupling of interacting classes

How
---
1. Interface and Implementation base classes and design


class interface {
    interface(implementation* i) : i(i) {}
    virtual void do1() = 0;
private:
    implementation* i;
};

class ConcreteInterface : interface {
    ConcreteInterface(implementation *i) : interface(i) {}
};

class implementation {}
class impl1 : public implementation {};

client()
{
    implementation* im = new impl1();
    interface* in = new ConcreteInterface(im);

    in->do1();
}