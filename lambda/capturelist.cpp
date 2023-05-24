#include <iostream>
using namespace std;
class A {
public:
    void print()
    {
        cout << "class A" << endl;
    }

    void test()
    {
        auto foo = [this] {print();x=5; };
        foo();
    }

private:
    int x;
};

void f(void (*)()) { }
void g()
{
    f([] {});
}

int x = 2;
static int y = 2;
// auto res = [x,y]() { return x+y; };
// x,y都不能捕获
auto res = [] { return x + y; };
int main(int argc, char const* argv[])
{
    int j = 3;
    static int k = 4;
    // auto res = [x, y, j, k]() { return x + y + j + k; };
    // x,y,k都不能捕获

    cout << res() << endl;

    // {
    //     int x = 5, y = 8;
    //     auto foo = [x, y] {
    //         x += 1;//编译出错，捕获的变量默认为常量
    //         y += 2;
    //         return x * y;
    //     }
    // }

    {
        int x = 5, y = 8;
        auto foo = [&x, &y] {
            x += 1; // 编译出错，捕获的变量默认为常量
            y += 2;
            return x * y;
        };
        cout << foo() << endl;
    }

    {
        int x = 5, y = 8;
        auto foo = [x, y]() mutable {
            x += 1; // 编译出错，捕获的变量默认为常量
            y += 2;
            return x * y;
        };
        cout << foo() << endl;
    }
    {
        int x = 5, y = 8;
        auto foo = [x, &y]() mutable {
            x += 1; // 编译出错，捕获的变量默认为常量
            y += 2;
            return x * y;
        };
        foo();
        cout << "call_one x = " << x << " , y = " << y << endl;
        foo();
        cout << "call_two x = " << x << " , y = " << y << endl;
    }

    A a;
    a.test();

    {
        int i = 2;
        auto foo = [r = x + 1] { return r; };
        cout << foo() << endl;
    }

    return 0;
}