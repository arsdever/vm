#pragma once

#include <stdint.h>

namespace vm
{
    class RAM
    {
    public:
        typedef int size_t;
        typedef int pos_t;

    public:
        RAM(size_t size) : __buffer(new uint8_t[size]{ 0 }) {}
        ~RAM() { delete[] __buffer; }

        template <typename VALUE_TYPE = uint8_t>
        VALUE_TYPE& operator[] (pos_t pos) { return (VALUE_TYPE&)__buffer[pos]; }

        template <typename VALUE_TYPE = uint8_t>
        VALUE_TYPE const& operator[] (pos_t pos) const { return (VALUE_TYPE&)__buffer[pos]; }

        template <typename VALUE_TYPE = uint8_t>
        VALUE_TYPE readDataLSB(pos_t pos)
        {
            VALUE_TYPE result = 0;
            for(int i = 0; i < sizeof(VALUE_TYPE); ++i)
            {
                result <<= 8;
                result &= ~0xff;
                result |= __buffer[pos + i];
            }
            return result;
        }

        template <typename VALUE_TYPE = uint8_t>
        void writeDataLSB(pos_t pos, VALUE_TYPE data)
        {
            for(int i = sizeof(VALUE_TYPE) - 1; i >= 0; ++i)
            {
                __buffer[pos + i] = data & 0xff;
                data >>= 8;
            }
        }

    private:
        uint8_t *__buffer;
    };
}