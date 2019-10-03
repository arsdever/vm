#pragma once

#include <unordered_map>
#include <string>

namespace vm
{
    class AbstractCPU;

    class AbstractInstructionSet
    {
    public:
        class InstructionExecutor
        {
        public:
            virtual ~InstructionExecutor() = default;
            
            virtual void execute () const = 0;
            virtual std::string disassemble() const = 0;
            virtual int instructionSize() const = 0;
            virtual int instructionDuration() const = 0;
        };

        typedef InstructionExecutor executor_t;
        typedef std::unordered_map<int, executor_t&> instruction_mapping_t;

    public:
        virtual void initMapping(AbstractCPU &cpu) = 0;
        virtual instruction_mapping_t const& getInstructionMapping() const = 0;
    };
}