#include <iostream>
using namespace std;

// The big 3 -> Copy constructor, Assignment and Destructor - If you define 1 you better define all 3


/*
 * Remember about RAII  - Resource Acquisition is Intialization
 * CADR - Constructor Acquires and Destructor Releases - same - follow this pattern as much as possible for error free code
 * i.e in case of mutex of shared ptr - this makes more sense
 * lock inside a constructor of youre lock manager and destructor has to unlock it - exception safe
 * */

/*
 *
 The RAII design is often used for controlling mutex locks in multi-threaded applications. In that use, the object releases the lock when destroyed. Without RAII in this scenario the potential for deadlock would be high and the logic to lock the mutex would be far from the logic to unlock it. With RAII, the code that locks the mutex essentially includes the logic that the lock will be released when execution leaves the scope of the RAII object.*

 Another typical example is interacting with files: We could have an object that represents a file that is open for writing, wherein the file is opened in the constructor and closed when execution leaves the object's scope. In both cases,

 Ownership of dynamically allocated objects (memory allocated with new in C++) can also be controlled with RAII, such that the object is released when the RAII (stack-based) object is destroyed. For this purpose, the C++11 standard library defines the smart pointer classes std::unique_ptr for single-owned objects and std::shared_ptr for objects with shared ownership
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

class Base {
public:
    Base() {
        x = 10;
        y = new int[x];
    }

public:
    ~Base() {
        delete[] y;
    }

    Base(const Base& that) {
        // construct
        x = that.x;
        y = new int[x];
        memcpy(y, that.y, x);
    }

    Base& operator=(const Base& that)
    {
        if (this == &that) return;

        // do the cleanup first, destruct this object

        // construct
    }
    // CAS
    Base& operator=(const Base& that) {
        // This is slighty different that copy constructor
        // as the object is already constructed
        // should do proper cleanup - MUST

        // use copy and swap
        Base T(that);
        Swap(T, *this);

        return *this;
    }
private:
    /*
    void Swap(Base& a, Base& b)
    {
        swap(a.x, b.x);
        swap(a.y, b.y);
    }
    */

    int x;
    int* y;
};

int main()
{
    return 0;
}

