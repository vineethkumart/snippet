template<typename U, typename V>
class same {
};

template<typename U>
class same<U,U> {
};

int main()
{
    return 0;
}



// So we can partially sepcify template as
//
template<typename U, typename V>
class x {
};

template<typename U>
class x<U, int> {};

template<typename U>
class x<U, U> {};


// Also a function alone in a class to be specialized to make it generic
//

class any {
    template<typename T>
    any(T* a) {};
};



