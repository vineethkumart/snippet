template<typename T>
class Base {
public:
    void doit() {
        static_cast<T*>(this)->doit();
    }
};

class Der : public Base<Der> {
    void doit();
};

template<typename T>
void common(T& base) { base.doit(); }

int main()
{
    Der1 d1;
    Der2 d2
    common(d1);
    common(d2);
}
