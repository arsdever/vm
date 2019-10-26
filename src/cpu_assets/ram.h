#pragma once

#include <stdint.h>
#include <initializer_list>

namespace vm
{
    class RAM
    {
    public:
        typedef int size_t;
        typedef int pos_t;

    public:
        RAM(size_t size) : __size(size), __buffer(new uint8_t[size]{ 0 }) {}
        ~RAM() { delete[] __buffer; }

        template <typename VALUE_TYPE = uint8_t>
        VALUE_TYPE& operator[] (pos_t pos) { return (VALUE_TYPE&)__buffer[pos]; }

        template <typename VALUE_TYPE = uint8_t>
        VALUE_TYPE const& operator[] (pos_t pos) const { return (VALUE_TYPE&)__buffer[pos]; }

        RAM& operator = (std::initializer_list<uint8_t> const& list)
        {
            delete[] __buffer;
            __buffer = new uint8_t[__size] { 0 };
            int i = 0;
            for (uint8_t n : list)
            {
                __buffer[i++] = n;
            }
            return *this;
        }

    private:
        uint8_t *__buffer;
        uint32_t __size;
    };
}