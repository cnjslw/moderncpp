#include <iostream>
#include <string.h>
using namespace std;

class BigMemoryPool {
private:
    char* pool_;

public:
    static const int PoolSize = 4096;
    BigMemoryPool()
        : pool_(new char[PoolSize])
    {
    }
    ~BigMemoryPool()
    {
        if (pool_ != nullptr)
            delete[] pool_;
    }

    BigMemoryPool(const BigMemoryPool& other)
        : pool_(new char[PoolSize])
    {
        cout << "copy big memory pool." << endl;
        memcpy(pool_, other.pool_, PoolSize);
    }

    BigMemoryPool(BigMemoryPool&& other)
    {
        cout << "move big memory pool." << endl;
        pool_ = other.pool_;
        other.pool_ = nullptr;
    }
};

BigMemoryPool get_pool(const BigMemoryPool& pool)
{
    return pool;
}
BigMemoryPool make_pool()
{
    BigMemoryPool pool;
    return get_pool(pool);
}

void move_pool(BigMemoryPool&& pool)
{
    cout << "call move_pool" << endl;
    BigMemoryPool my_pool(pool);
}

int main(int argc, char const* argv[])
{
    cout << "---------------6.4-------------------" << endl;
    BigMemoryPool my_pool = make_pool();
    cout << "---------------6.7-------------------" << endl;
    move_pool(make_pool());

    return 0;
}