#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    {
        cout << "----------------7.7---------------" << endl;
        auto foo = [](auto a) { return a; };
        int three = foo(3);
        char const* hello = foo("hello");
        cout << three << endl;
        cout << hello << endl;
    }
    return 0;
}