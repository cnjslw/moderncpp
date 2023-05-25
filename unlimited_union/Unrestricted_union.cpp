#include <iostream>
#include <string>
#include <vector>
using namespace std;

union U {
    U() { }
    ~U() { }
    int x1;
    float x2;
    string x3;
    vector<int> x4;
    static int x5;
};
int U::x5 = 42;

int main(int argc, char const* argv[])
{
    U u;
    new (&u.x3) string("hello world");
    cout << u.x3 << endl;
    u.x3.~basic_string();

    new (&u.x4) vector<int>;
    u.x4.push_back(58);
    cout << u.x4[0] << endl;
    u.x4.~vector();

    return 0;
}