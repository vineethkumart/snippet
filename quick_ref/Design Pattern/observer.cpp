What
----
subscribe service


class Subscribable {
    virtual void Subscribe(Subscriber* s) = 0;
    virtual void UnSubscribe(Subscriever *s) = 0;
};

class Subscriber {
public:
    void receive();
};



class Application : Subscribable {
    void Subscribe() {
        ss.push()
    }
    
    void event() {
        for (auto s: ss) s->receive();
    }

private:
    list<Subscriber*> ss;
}