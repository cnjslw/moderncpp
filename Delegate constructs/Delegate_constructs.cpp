#include <iostream>
using namespace std;

class X {
private:
    int a_;
    int b_;

public:
    X()
    try : X(0) {
    } catch (int e) {
        cout << "catch: " << e << endl;
        throw 3;
    }

    X(int a)
    try : X(a, 0.) {
    } catch (int e) {
        cout << "catch: " << e << endl;
        throw 2;
    }

    X(double b)
    try : X(0, b) {
    } catch (int e) {
        cout << "catch: " << e << endl;
        throw 4;
    }

    X(int a, double b)
        : a_(a)
        , b_(b)
    {
        throw 1;
    }

    ~X() { }
};

int main(int argc, char const* argv[])
{
    try {
        X x;
    } catch (int e) {
        cout << "catch: " << e << endl;
    }
    return 0;
}