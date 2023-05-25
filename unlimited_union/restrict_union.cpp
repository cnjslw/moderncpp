#include <iostream>
using namespace std;

union U {
    int x1;
    float x2;
};
int main(int argc, char const* argv[])
{
    U u; // 只能由一个对象
    u.x1 = 5;
    cout << u.x1 << endl;
    cout << u.x2 << endl;
    u.x2 = 4.9;
    cout << u.x1 << endl;
    cout << u.x2 << endl;
    return 0;
}