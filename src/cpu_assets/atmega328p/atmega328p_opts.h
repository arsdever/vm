#pragma once
#include <cpu_assets/cpu_opts.h>

namespace vm
{
    struct ATmega328POptions : public CPUOptions
    {
        int flash_size;
    };
}