Usage
-----
1. Constructor args are added periodically
2. “telescopic constructor”.

Steps:
------
1. Create Base Bridge
2. Concrete Bridge                  => creates and keeps object
3. Director(Bridge) for building    => can create builder inside based on type as well
4. Get Product from Director

class Builder {
public:
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void get() = 0;
};

class CarBuilder : Builder {
    // implementation
    void get() return c;
private:
    Car* c;
};

class Director { // optional
    Director(Builder* b);
    void Start() {
        // 
    }
};

int client()
{
    Builder* b = new CarBuilder();
    Director d(b);
    d.build();

    Car* c = b->get();
}