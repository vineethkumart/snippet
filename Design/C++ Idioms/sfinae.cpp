struct S {
    using mt = int;
};

template<typename T>
void do_op(typename T::mt x) { cout << x;} // patern 1

template<typename T>
void do_op(T x) { cout << x; } // pattern 2

int main()
{
    do_op<S>(1);
    do_op<int>(1);
}