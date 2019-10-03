#include <exception>
#include <string>

namespace vm
{
    class InstructionNotFound : public std::exception
    {
    public:
        InstructionNotFound() : std::exception() {}
        char const* what() const noexcept override { return "Cannot allocate instruction"; }
    };
}
