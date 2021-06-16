
1. The identifier typename was introducted to let the compiler know that the identifier that follows is a TYPE. initially before c++11 typename was not there
When is it really required: refere typename.cpp

2. Template can be with a type of Value - We heavily use Value template to specialize at compile time to achieve ccp

- A template is not a class or a function. A template is a “pattern” that the compiler uses to generate a family of classes or functions.
- In order for the compiler to generate the code, it must see both the template definition (not just declaration) and the specific types/whatever used to “fill in” the template. 
- For example, if you’re trying to use a Foo<int>, the compiler must see both the Foo template and the fact that you’re trying to make a specific Foo<int>.
- Your compiler probably doesn’t remember the details of one .cpp file while it is compiling another .cpp file. 
- It could, but most do not and if you are reading this FAQ, it almost definitely does not. BTW this is called the “separate compilation model.”


template<typename T>
class Vec {
};


template<typename T>
Vec<T>::fn

template<>
class Vec<int>  {}

template<>
Vec<int>::fn


1. Template functions can be called without explicitly specifiying the type
i.e

template<typename T>
int mul(T a, T b) {}

can be called as mul(a,b) compiler will do type deduction automatically


2. Class template has to be specified
Vec a => is not valid
Vec<T> always


3. Specialization
template<typename T> T mul(T a, T b);
template<> int mul<int>(int a, int b);


How to get compile type polymorphism properly without code duplication - refer template_ccp.cpp

class Base {



};
