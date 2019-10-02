#include "cpu_model.h"

namespace vm
{
    void CPUModel::decode()
    {
        ++__instruction_pointer;
    }

    void CPUModel::execute()
    {
        __instruction_set.execute(*this);
    }
}