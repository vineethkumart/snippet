What
----
To implement a cache or another layer

class Memory {
public:
    write();
    read();
};

class Cache {
public:
    Cache() : m (new memory) {}
    write();
    read();
private:
    Memory* m;
};

=> Can use inhertiance as well instead of containment
But proxy DP advocates containment

TO hide actual object creation etc.,