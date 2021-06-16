/* The method to implement compile time/static polymorphism *
 *
 * CRTP: Curiously Recurring Template Patterns */


#include <iostream>

using namespace std;

template<typename T>
class Base {
public:
    void common() {
        cout << "common at base\n";
        (static_cast<T*>(this))->common();
    }
};


class Der1 : public Base<Der1>
{
public:
    void common() {
        cout << "der1 common\n";
    }
};



template<typename T>
void execute(T& base) {
    base.common();
}

int main()
{
    Der1 d;
    execute(d);

    return 0;
}
