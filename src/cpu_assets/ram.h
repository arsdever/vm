#pragma once

namespace vm
{
    class RAM
    {
    public:
        typedef int size_t;
        typedef int pos_t;

    public:
        RAM(size_t size);
        ~RAM();

        char& operator[] (pos_t pos);
        char const& operator[] (pos_t pos) const;

    private:
        char *__buffer;
    };
}