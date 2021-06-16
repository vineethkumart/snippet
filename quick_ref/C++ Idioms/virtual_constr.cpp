// Also factory
class Base {
    virtual Base* create()  = 0;
};

class Der : Base {
    Base* create() { return new Der; };
};