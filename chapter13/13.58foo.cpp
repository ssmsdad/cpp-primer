
#include<iostream>


class Foo{
public:
    Foo() = default;
    Foo(const Foo &f) { std::cout << "Foo(const Foo &f)" << std::endl; }
    Foo(Foo &&f) { std::cout << "Foo(Foo &&f)" << std::endl; }
    Foo &operator=(const Foo &f) { std::cout << "Foo &operator=(const Foo &f)" << std::endl; return *this; }
    Foo &operator=(Foo &&f) { std::cout << "Foo &operator=(Foo &&f)" << std::endl; return *this; }
    ~Foo() { std::cout << "~Foo()" << std::endl; }
    Foo sorted() &&;
    Foo sorted() const &;
};


Foo Foo::sorted() && {
    std::cout << "右值引用" << std::endl;
    return *this;
}

// Foo Foo::sorted() const & {
//     std::cout << "左值引用" << std::endl;
//     Foo ret(*this);
//     return ret.sorted();             //因为ret是左值，此时编译器会调用左值引用版本的sorted，陷入循环
// }


Foo Foo::sorted() const & {
    std::cout << "左值引用" << std::endl;
    return Foo(*this).sorted();         //此时编译器会将Foo(*this)视为一个右值，调用右值j引用版本的sorted
}


int main()
{
    Foo f;
    f.sorted();
    return 0;
}