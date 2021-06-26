What
----
1. multiple phases and each phase do or pass
2. To do things in phases

How
---
1. Interface for a phase
2. Concreate phases


class Handler {
public:
    virtual void process() = 0;
    void setNext(Handler* h) : n(h) {}

private:
    Handler* n;
};

class H1 : Handler {
    void process()
    {
        // process it and then:
        if (hasNext())
            GetNext()->prcess();
    }
};
class H2 : Handler {};

client()
{
    Director d;
    Handler* h1,h2,h3;
    d.build(type1, type2, type3, h1, h2, h3);

    h1->setNext(h2);
    h2->setNext(h3);
    h3->setNext(h4);
    
    h1->process(); // proc
}