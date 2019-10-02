#include "abstract_instruction_set.h"
#include "abstract_cpu.h"
#include "instruction_set_executors_impl.h"
#include <assert.h>

namespace vm
{
    std::unordered_map<int, AbstractInstructionSet::executor_t*> AbstractInstructionSet::s_mapping = 
    {
        std::make_pair<int, AbstractInstructionSet::executor_t*>(0, new Instruction_ADC()),
        std::make_pair<int, AbstractInstructionSet::executor_t*>(1, new Instruction_ADD()),
        std::make_pair<int, AbstractInstructionSet::executor_t*>(2, new Instruction_SUB()),
        std::make_pair<int, AbstractInstructionSet::executor_t*>(3, new Instruction_MUL()),
        std::make_pair<int, AbstractInstructionSet::executor_t*>(3, new Instruction_ASG())
    };

    AbstractInstructionSet::InstructionExecutor::InstructionExecutor(InstructionExecutor *impl)
        : __impl(impl)
    {}

    void AbstractInstructionSet::InstructionExecutor::operator() (AbstractCPU &cpu)
    {
        __impl->__flags = cpu.__flags;
        (*__impl) (cpu);
        updateCPUFlags(cpu);
    }

    void AbstractInstructionSet::InstructionExecutor::updateCPUFlags(AbstractCPU &cpu) { cpu.__flags = __impl->__flags; }

    void AbstractInstructionSet::execute(AbstractCPU &cpu)
    {
        int opcode = ((char*)&cpu.getInstructionRegister())[0];
        (*s_mapping[opcode])(cpu);
    }
}