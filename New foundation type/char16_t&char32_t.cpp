#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    cout << "-----------------------------" << endl;
    // char utf8c = u8'a';
    char16_t utf16c = u'好';
    char32_t utf32c = U'好';
    // cout << "utf8c = " << utf8c << " sizeof(utf8c) =  " << sizeof(utf8c) << endl;
    cout << "utf16c = " << utf16c << " sizeof(utf16c) =  " << sizeof(utf16c) << endl;
    cout << "utf32c = " << utf32c << " sizeof(utf32c) =  " << sizeof(utf32c) << endl;
    cout << "-----------------------------" << endl;

        return 0;
}