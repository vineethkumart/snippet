// To implement a state machine
// Changes state dynamically


class State {

};

class State1 {

};

class State2 {

};


class Application {
public:
    void SetState(State* s) {
        cs = s;
    }
    void Start()
    {
        SetState(new State1);
    }
private:
    State* cs;
};