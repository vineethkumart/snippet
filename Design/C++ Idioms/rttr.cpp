// Overloading with return type - Return Type Resolver
template<typename T>
class init { }

template<>
class init<int> {
public:
    init(int size) :size(size)  {}
    template<typename C>
    operator C() {
        C c;
        return c;
    }
private:
int size;
};



client()
{
    list<int> l = init<int>(10);
    set<int>  s = init<int>(10);
}