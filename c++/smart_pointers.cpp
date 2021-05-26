//Any class that manages a resource (a wrapper, like a smart pointer) needs to implement The Big Three.
// Copy Constructor
// Assignment Operator
// Destructor
//
//
/*
 * Copy constructor - no issues
 * copy assignment - little complicated as the object is already in a valid constructed stage, so handle that.
 *
 *
 *
 * So when should we declare those special member functions explicitly? When our class manages a resource, that is, when an object of the class is responsible for that resource.
 * RAII = Resource Acquisition is Initialization
 * // 1. copy constructor
 person(const person& that)
    {
        name = new char[strlen(that.name) + 1];
        strcpy(name, that.name);
        age = that.age;
    }

// 2. copy assignment operator
person& operator=(const person& that)
    {
    if (this != &that)
    {
        delete[] name;
        // This is a dangerous point in the flow of execution!
        // We have temporarily invalidated the class invariants,
        // and the next statement might throw an exception,
        // leaving the object in an invalid state :(
        name = new char[strlen(that.name) + 1];
        strcpy(name, that.name);
        age = that.age;
    }
    return *this;
    }

    // Do as
    char* local_name = new char[strlen(that.name) + 1];
    // If the above statement throws,
    // the object is still in the same state as before.
    // None of the following statements will throw an exception :)
    strcpy(local_name, that.name);
    delete[] name;
    name = local_name;
    age = that.age;
    return *this;


    Noncopyable resources
Some resources cannot or should not be copied, such as file handles or mutexes. In that case, simply declare the copy constructor and copy assignment operator as private without giving a definition:

private:

    person(const person& that);
    person& operator=(const person& that);
Alternatively, you can inherit from boost::noncopyable or declare them as deleted (in C++11 and above):

person(const person& that) = delete;
person& operator=(const person& that) = delete;
 */


/*
 * The rule of three
 * -----------------
 *  If you need to explicitly declare either the destructor, copy constructor or copy assignment operator yourself, you probably need to explicitly declare all three of them.
 *
 * The rule of five
 * ---------------
 *  C++ 11 + move and copy
 *  class person
{
    std::string name;
    int age;

public:
    person(const std::string& name, int age);        // Ctor
    person(const person &) = default;                // 1/5: Copy Ctor
    person(person &&) noexcept = default;            // 4/5: Move Ctor
    person& operator=(const person &) = default;     // 2/5: Copy Assignment
    person& operator=(person &&) noexcept = default; // 5/5: Move Assignment
    ~person() noexcept = default;                    // 3/5: Dtor
};

    Rule of zero
    ------------
    all default


    Copy and Swap Idiom
    ------------------
    To implement assignment operator. THis is required if the object is already constructor, we need to free it.
    B& operator=(const B& that)
    {
        B dummy(that);          // uses copy constr.
        swap(*this, dummy);     // swaps to temp so that temp is freed on exit of this function, should use our own swap, std::swap uses copy constructor
        return *this;
    }
*/



#include <iostream>
using namespace std;

class X {
public:
    X(int i) : i(i) {}
    X& operator++() { i++; return *this; } // pre icrement
    X  operator++(int) {X tmp(*this); ++*this; return tmp;} // post increment
public:
    int i;
};

int main()
{
    X x(1);
    x++;
    cout << x.i;
    ++x;
    cout << x.i;
    return 0;

}

