//TODO: complete this

/*
 *
 *
 *
 * std::any is a c++17 feature and thats more of giving a feel of type unsafety feature in C++
 * Remeber C++ is strongly type and type of an object should be known at compile time./
 
 So whats 'any' how is it diff from auto?
 auto is just a alias for a type.

 any is a container. You can write

 std::any a = 12;
 a = "string"; // this is valid
 */

#include <iostream>
#include <memory>
using namespace std;

#if 0
int main()
{
    std::any a = 12;
    a = "vineeth";
    string b = any_cast<string>(a);
    int x = any_cast<int>(a) // error
        

    return 0;

}
#endif

class X {
public:
    template<typename T>
    X(const T& x) {
        (void) x;
    }
};





// std::any -> very advanced topic
// Idea is to define a generic any class and inside that define the concrete templatized class to store the actual type value, store in a pointer


class any {
public:
    template<typename T>
     any(T val) : c(make_unique<actual_cont<T>(val)>) {};

    template<typename T>
    any& operator=(const T& that) {
        c = make_unique<actual_cont<T>>(that);
        return c;
    }

private:
    class container {}; // just place holder
    // this is actual concrete container
    template<typename T>
    struct actual_cont : public container {
        actual_cont(T& val) : val(val) {}
        T val;
    };


    
private:
    unique_ptr<container> c;
};


int main()
{
    return 0;
    any x = 10;
}



