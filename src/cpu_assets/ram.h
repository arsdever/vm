#pragma once

#include <stdint.h>
#include <initializer_list>

namespace vm
{
    /**
     * @brief This is a simple RAM implementation.
     * 
     * @details It is used by CPU for instruction fetching, stack manipulations and other stuff.
     * 
     * @see RAM
     * @author [arsdever](https://github.com/arsdever)
     */
    class RAM
    {
    public:
        typedef int size_t;
        typedef int pos_t;

    public:
        /**
         * @brief Construct a new RAM object.
         * 
         * @param size the RAM size
         */
        RAM(size_t size) : __size(size), __buffer(new uint8_t[size]{ 0 }) {}

        /**
         * @brief Destroy the RAM object
         */
        ~RAM() { delete[] __buffer; }

        /**
         * @brief Get the data reference.
         * 
         * @details Returns a reference to the data cell taking place at specified address.
         * 
         * @tparam VALUE_TYPE type of data to be accessed. uint8_t is used by default.
         * @param pos the address to be accessed
         * @return VALUE_TYPE& the requested data reference
         */
        template <typename VALUE_TYPE = uint8_t>
        VALUE_TYPE& operator[] (pos_t pos) { return (VALUE_TYPE&)__buffer[pos]; }

        /**
         * @brief Get the data const reference.
         * 
         * @details Returns a const reference to the data cell taking place at specified address.
         * 
         * @tparam VALUE_TYPE type of data to be accessed. uint8_t is used by default.
         * @param pos the address to be accessed
         * @return VALUE_TYPE const& the requested data reference
         */
        template <typename VALUE_TYPE = uint8_t>
        VALUE_TYPE const& operator[] (pos_t pos) const { return (VALUE_TYPE&)__buffer[pos]; }

        /**
         * @brief Set RAM content.
         * 
         * @details Operator simply clears and rewrites the content from begginning.
         * 
         * @param list the data to be written
         * @return RAM& current object reference
         */
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