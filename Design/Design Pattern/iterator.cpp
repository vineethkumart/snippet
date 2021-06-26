template<typename T>
class Container {
public:
    Container() {};

    iterator begin() {
        iterator itr(this, idx);
        return itr;
    }
    iterator end() {
        iterator itr(this, size);
        return itr;
    }

public:
    class iterator {
    public:
        friend class Container;
        iterator(Container* c, int pos) : c(c) {}
        
        iterator(const iterator& that) {
            c = that.c;
            pos = that.pos;
        }

        iterator& operator=(const iterator& that) {
            c  = that.c;
            pos = that.pos;
            return *this;
        }

        // pre increment
        T& operator++() {
            pos++;
            return *this;
        }

        // post incrememtn
        T operator++(int) {
            iterator i(*this);
            pos++;
            return i;
        }
        
        bool operator==(const iterator& that) {
            return (pos == that.pos && c == that.c);
        }

        bool operator!=(const iterator& that) {
            return !operator==(that);
        }

    private:
        container* c;
        int pos;
    };

    T* storage;
    int size;

};

client()
{
    cont<T> c;
    cont<T>::iterator itr = c.begin();
    while (itr != c.end()) {
        cout << *itr;
        ++itr;
    }
}