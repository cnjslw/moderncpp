#include <iostream>
using namespace std;

int x = 1;
int get_val()
{
    return x;
}

void set_val(int val)
{
    int* p = &val;
    x = val;
}

class X {
public:
    X() { cout << "默认构造函数" << endl; }
    X(const X&) { cout << "拷贝构造函数" << endl; }
    ~X() { cout << "析构函数" << endl; }
    X& operator=(const X&)
    {
        cout << "复制构造函数" << endl;
        return *this;
    }

    void show()
    {
        cout << "show X" << endl;
    }
};

X make_x()
{
    X x;
    return x;
}

int main()
{
    cout << "------------6.1------------------" << endl;
    // int* p = &x++; 编译错误
    int* q = &++x;
    auto* p = &"Hello World";
    cout << "------------6.2------------------" << endl;

    cout << "------------6.3------------------" << endl;
    X x1;
    cout << "-------x1--------" << endl;
    X x2(x1);
    cout << "-------x2--------" << endl;
    X x3(make_x());
    cout << "-------x3()--------" << endl;
    x3 = make_x();
    cout << "-------x3=--------" << endl;

    cout << "------------6.4------------------" << endl;
    X&& x4 = make_x();
    x4.show();
}