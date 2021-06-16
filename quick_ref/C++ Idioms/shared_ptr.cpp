template<typename T>
class sp_t {
public:
    sp_t() : ptr(0), rc(0) {}

    sp_t(T* rhs) : ptr(rhs), rc(new unsigned int(1)) {}

    sp_t(const sp_t& rhs) {
        ptr = &rhs.ptr;
        if (rhs.rc) rhs.rc++;
    }

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
    sp<int> x(new int);
    *x = 1;
    sp<int> x1(x);
    cout << *x1;
    sp<int> x2;
    x = x2;
}