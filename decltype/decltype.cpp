#include <assert.h>
#include <iostream>
using namespace std;

int global_x = 0;
decltype(global_x) sum(decltype(global_x) a1, decltype(global_x) a2)
{
    return a1 + a2;
}

template <class T>
auto return_ref(T& t) -> decltype(t)
{
    return t;
}

template <class T>
decltype(auto) return_ref_cpp14(T& t)
{
    return t;
}

template <decltype(auto) N>
void f()
{
    cout << N << endl;
}

int main(int argc, char const* argv[])
{
    cout << "----------------4.2------------------" << endl;
    int x1 = 0;
    decltype(x1) x2 = 0;
    cout << typeid(x2).name() << endl;
    double x3 = 0;
    decltype(x1 + x3) x4 = x1 + x3;
    cout << typeid(x4).name() << endl;
    cout << "----------------4.2------------------" << endl;
    struct s1 {
        int x1;
        decltype(x1) x2; // 解决auto不能推导非静态成员变量类型的问题
        double x3;
        decltype(x2 + x3) x4;
    };

    auto x5 = sum(5, 10);
    cout << "decltype在函数返回值和形参里的使用 = " << x5 << endl;

    int x6 = 0;
    static_assert(std::is_reference_v<decltype(return_ref(x6))>);
    cout << "----------------4.5------------------" << endl;
    int x7 = 0;
    static_assert(std::is_reference_v<decltype(return_ref_cpp14(x7))>);
    cout << "----------------4.6------------------" << endl;
    static const int x8 = 11;
    static int x9 = 7;
    f<x8>();
    f<(x8)>();
    // f<x9>();
    f<(x9)>();

    return 0;
}