#include <iostream>
#include <string>
using namespace std;

template <typename T>
void show_type(T t)
{
    cout << typeid(T).name() << endl;
}

template <typename T>
void perfect_forwarding(T&& t)
{
    // show_type(static_cast<T&&>(t));
    show_type(forward<T>(t));
}

string get_string()
{
    return "hi world";
}

int main(int argc, char const* argv[])
{

    string s = "hi world";
    perfect_forwarding(s); // T& ==> T& + T&& = T& 保持左值属性
    perfect_forwarding(get_string()); // T&& ==> T&& + T&& = T&& 保持右值属性
    return 0;
}
