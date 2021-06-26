Also known as Wrapper
What
----
1. Dynamically wrap/create new type of object
2. Decorates in each wrapping, like a pipeline


How
----
1. Decorator Interface with containment
2. Concrete Decorators

class Notify {
public:
    void sendNot() {
        // send default notification
    }
};

class NotDec : Notify {
public:
    NotDec(Notify* n) : n(n);
private:
    Notify* n;
};

class SmsNot : public NotDec {
    SmsNot(Notify *n) : NotDec(n) {}
    void notify() {
        // send
        // then:
        n->notify();
    }
};

class MailNot : public NotDec {
    MailNot(Notify* n) : NotDec(n) {}
    void notify() {
        // send notification first

        // then delegate
        n->notify();
    }
};

client()
{
    Notify * n = new Notify();
    if (smsneeded) {
        n = new SmsNot(n);
    }
    if (mailneeded) {
        n = new MailNot(n);
    }

    n->notify();
}

Uses:
1. Many BufferedinputReader
2. Compress and Encode file etc.,