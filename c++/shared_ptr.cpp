#include <iostream>
using namespace std;

template<typename T>
class sp_t {
public:
    sp_t() : ptr(0), rc(0) {}

    sp_t(T* rhs) : ptr(rhs), rc(new unsigned int(1)) {}

    sp_t(const sp_t& rhs) :
    ptr(rhs.ptr),
    rc(&(++*rhs.rc)) {}

    sp_t& operator=(const sp_t& that) {
        // increase ref count
        if (that.rc)
            ++*that.rc;

        if (rc && --*rc == 0) {
            // destruct this object
            delete ptr;
            delete rc;
        }

        ptr = that.ptr;
        rc = that.rc;

        return *this;
    }

    ~sp_t() {
        if (ptr && rc) {
            if (--*rc == 0) {
                delete ptr;
                delete rc;
            }
        }
    }

    T& operator*() { return *ptr; }
    T* operator&() { return ptr; }
    T* operator->() { return ptr; }

    int use_count() { if (rc) return *rc; return 0;}

private:
    T*            ptr;
    unsigned int* rc;
};

int main()
{
    sp_t<int> p;
    cout << p.use_count() << endl;

    sp_t<int> p1(new int(10));
    cout << p1.use_count() << endl;
    {
        sp_t<int> p2(p1);
        cout << p1.use_count() << endl;
        cout << p2.use_count() << endl;
        {
            sp_t<int> p3(p1);
            cout << p1.use_count() << endl;
        }
        cout << p1.use_count() << endl;
    }
    cout << p1.use_count() << endl;

    p = sp_t<int>();
    cout << p1.use_count() << endl;
}




/*
#include <memory>
int main()
{
    shared_ptr<int> p1(new int);
    cout << p1.use_count();

    shared_ptr<int> p2(p1);
    cout << p1.use_count();

    shared_ptr<int> p3(p2);
    cout << p1.use_count();

    p1 = shared_ptr<int>();
    cout << endl;

    cout << p1.use_count();
    cout << p2.use_count();
    cout << p3.use_count();

    return 0;
}*/
