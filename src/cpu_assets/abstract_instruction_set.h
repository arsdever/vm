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
            InstructionExecutor(InstructionExecutor *impl);
            
            virtual void operator() (AbstractCPU &cpu);
            virtual std::string disassemble(AbstractCPU &cpu) const = 0;
        
        private:
            void updateCPUFlags(AbstractCPU &cpu);

        protected:
            int __flags;
            InstructionExecutor *__impl;
        };

        typedef InstructionExecutor executor_t;

    public:
        void execute(AbstractCPU &);

    private:
        static std::unordered_map<int, executor_t*> s_mapping;
    };
}