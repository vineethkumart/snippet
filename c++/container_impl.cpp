#include <iostream>
#include <memory>

using namespace std;


template<typename T>
class cont {
public:
    cont(int size = 0) : size(size) {
        if (!size) size = 128;
        storage = make_unique<T[]>(size);
    }

    ~cont() {}

public:
    class iterator {
        friend class cont;
        private:
            iterator(cont* c, int pos) : c(c), pos(pos) {}
        public:
            iterator(const iterator& that) {
                c = that.c;
                pos = that.pos;
            }

            iterator& operator=(const iterator& that) {
                c = that.c;
                pos = that.pos;
            }

            iterator& operator++() { // preincrement
                pos++;
                return *this;
            }

            iterator operator++(int) { // post increment
                iterator t(*this);
                pos++;
                return t;
            }

            T& operator*() {
                return (*c)[pos];
            }

            bool operator==(const iterator& that) {
                return (c == that.c && pos == that.pos);
            }

            bool operator!=(const iterator& that) {
                return (c != that.c || pos != that.pos);
            }

        private:
            cont* c; // the parent
            int pos; // position/state
    };

public:
    friend class cont<T>::iterator;

    // iterator functions
    iterator begin() {
        return iterator(this, 0);
    }

    iterator end() {
        return iterator(this, size);
    }

    T& operator[](int i) {
        return storage[i];
    }
private:
    int size;
    unique_ptr<T[]> storage;
};


int main()
{
    cont<int> c(10);
    for (auto i = c.begin(); i != c.end(); ++i) {
        cout << *i << endl;
    }
}
