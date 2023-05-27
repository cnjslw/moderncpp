#include <iostream>
using namespace std;

class Base {
private:
    int a_;
    double b_;

public:
    Base(/* args */) { cout << "Base()" << endl; }
    Base(int a)
        : Base(a, 0.)
    {
        cout << "Base(int)" << endl;
    }
    Base(int a, double b)
        : a_(a)
        , b_(b)
    {
        cout << "Base(int a, double b)" << endl;
    }
    ~Base() { }
};

class Derived : public Base {
private:
    int c_;

public:
    using Base::Base;
    Derived() { cout << "Derived()" << endl; }
    Derived(int a, double b, int c)
        : c_(c)
        , Base(a, b)
    {
        cout << "Derived(int)" << endl;
    }
};

int main(int argc, char const* argv[])
{
    cout << "--------" << endl;
    Derived d0;
    cout << "--------" << endl;
    Derived d1(1);
    cout << "--------" << endl;
    Derived d2(1, 2.1, 3);
    return 0;
}