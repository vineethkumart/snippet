What
----
1. Separation of concerns
2. Dont embed action inside a command, keep them separate

class Action {
    virtual void doit() = 0;
};

class CopyAction {
    void doit() { do copy };
};

class Command {
    void SetAction(Action* a) {
        act = a;
    }
private:
    Action* a;
};

class Button : Command {
public:
    void click() {
        if (hasAction()) {
            getAction()->doit();
        }
    }
};



