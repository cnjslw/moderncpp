#include <iostream>
#include <typeinfo>
using namespace std;

int main(int argc, char const* argv[])
{
    int n = 5;
    auto *pn = &n, m = 10;
    // auto *pm = &n, q = 1.2; 类型不一致，编译失败
    cout << typeid(n).name() << endl;
    cout << typeid(*pn).name() << endl;
    cout << "------------3.1.1-------------------" << endl;
    auto i = true ? 5 : 8.1;
    cout << typeid(i).name() << endl;
    cout << "------------3.1.2--------------------" << endl;

    // struct new_auto
    // {
    //     auto k = 4;
    // };
    // C++11下报错
    cout << "------------3.2.1--------------------" << endl;
    const int p = 5;
    auto j = p;
    auto& h = p;
    // auto* l = p;
    cout << typeid(j).name() << endl;
    cout << typeid(h).name() << endl;
    // cout << typeid(l).name() << endl;
    cout << "------------3.2.2---------------------" << endl;
    int a_2_1 = 5;
    int& a_2_2 = a_2_1;
    auto a_2_3 = a_2_2;
    cout << typeid(a_2_3).name() << endl;
    cout << "------------3.2.3---------------------" << endl;
    int a_3_1 = 5;
    auto&& a_3_2 = a_3_1;
    auto&& a_3_3 = 5;
    cout << typeid(a_3_2).name() << endl;
    cout << typeid(a_3_3).name() << endl;
    cout << "------------3.2.4---------------------" << endl;
    int a_4_1[5];
    auto a_4_2 = a_4_1;
    // int sum(int a1, int a2)
    // {
    //     return a1 + a2;
    // }
    // auto a_4_3 = sum;
    cout << typeid(a_4_2).name() << endl;
    // cout << typeid(a_4_3).name() << endl;

    return 0;
}