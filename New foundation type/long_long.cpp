// C++11
#include <climits>
#include <iostream>
#include <limits>
using namespace std;

void segmentation()
{
    cout << "---------------------------------" << endl;
}
int main(int argc, char const* argv[])
{
    segmentation();
    long long x1 = 65536LL;
    long long x2 = 65536;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    x1 = x1 << 16;
    cout << "x1<<16 = " << x1 << endl;
    x2 = x2 << 16;
    cout << "x2<<16 = " << x2 << endl;
    cout << "size of long long = " << sizeof(long long) << endl;
    segmentation();
    cout << "LLong_Max = " << LLONG_MAX << endl;
    cout << "LLong_Min = " << LLONG_MIN << endl;
    cout << "ULLong_Max = " << ULLONG_MAX << endl;
    segmentation();
    cout << "std::numeric_limits<long long> = " << numeric_limits<long long>::max() << endl;

    return 0;
}
