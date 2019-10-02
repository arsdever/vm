#include "ram.h"

namespace vm
{
    RAM::RAM(size_t size)
        : __buffer(new char[size]{ 0 })
    {}

    RAM::~RAM()
    {
        delete[] __buffer;
    }

    char& RAM::operator[] (pos_t pos)
    {
        return __buffer[pos];
    }

    char const& RAM::operator[] (pos_t pos) const
    {
        return __buffer[pos];
    }
}