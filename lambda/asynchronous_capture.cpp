#include <future>
#include <iostream>

class work {
private:
    int value;

public:
    work()
        : value(42)
    {
    }
    std::future<int> spawn()
    {
        return std::async([=, tmp = *this]() -> int { return tmp.value; });
    }
};

std::future<int> foo()
{
    work tmp;
    return tmp.spawn();
}

int main()
{
    std::future<int> f = foo();
    f.wait();
    std::cout << "f.get() = " << f.get() << std::endl;
}