#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{

    cout << "-------------------typeof-------------------" << endl;
    int a = 0;
    // typeof(a) b = 10;
    // cout << " typeof(a) b = 10 " << b << endl;
    cout << "-------------------typeid-------------------" << endl;
    int x1 = 0;
    double x2 = 5.5;
    cout << " typeid: " << typeid(x1).name() << endl;
    cout << " typeid: " << typeid(x1 + x2).name() << endl;
    cout << " typeid: " << typeid(int).name() << endl;
    return 0;
}