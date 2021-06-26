What
----
Save Restore, History etc.,
Single responsibility


class Memento {
public:
    Memento(Application * ap) {
        ap = copy_from_Application(ap);
    }
private:
    Application ap;
};

class Application {
public:
    void take_snap() {
        return new Memento(this);
    }
    void restore(Memento *m) {
        // restore
    }
private:
// states
};

class History {
public:
    History(Application* a) : a(a);

    Save() {
        Memento* m = a->take_snap();
        h.push(m);
    }

    Unod() {
        a->restore(h.top());
        h.pop();
    }
private:
    stack<Memento*> h;
    Application *a;
};