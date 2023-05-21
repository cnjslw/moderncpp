#include <iostream>
using namespace std;

namespace Parent {
namespace child_1 {
    void foo() { cout << "foo V1.0" << endl; }
}
inline namespace child_2 {
    void foo() { cout << "foo V2.0" << endl; }
}
/*
在上面的代码中，Child1不是一个内联命名空间，所以调用Child1的
foo函数需要明确指定所属命名空间。而调用Child2的foo函数则方便了许
多，直接指定父命名空间即可。
*/
/*
该特性可以帮助库作者无缝升级库代码，让客户不用修改任何
代码也能够自由选择新老库代码
*/
}

namespace A::B::C {
void foo() { cout << "C++17支持嵌套命名的简化语法" << endl; }
}

namespace D::inline E::F {
void foo() { cout << "C++20支持嵌套内联命名空间的简化语法" << endl; }
}

int main(int argc, char const* argv[])
{
    Parent::child_1::foo();
    Parent::foo();

    A::B::C::foo();
    D::F::foo();

    return 0;
}