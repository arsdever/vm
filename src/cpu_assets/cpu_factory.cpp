#include "cpu_factory.h"

#include "atmega328p/atmega328p.h"
#include "cpu6502/cpu6502.h"
#include "cpu_opts.h"

namespace vm
{
    CPUFactory* CPUFactory::factory()
    {
        static CPUFactory s_instance;
        return &s_instance;
    }

    CPU* CPUFactory::getCPUInstance(CPUOptions const& opts)
    {
        switch(opts.cpu_model_uuid)
        {
            case ATmega328P::UUID: return ATmega328P::fromOptions(opts);
            case CPU6502::UUID: return ATmega328P::fromOptions(opts);
        }
    }
}