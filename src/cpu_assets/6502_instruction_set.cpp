#include "6502_instruction_set.h"
#include "cpu6502.h"

namespace vm
{
    void InstructionSetFor6502::initMapping(AbstractCPU &cpu)
    {
        CPU6502 &rcpu = static_cast<CPU6502 &>(cpu);
        __instruction_set.insert({ 0x61, rcpu.ADC_impl });
        __instruction_set.insert({ 0x65, rcpu.ADC_impl });
        __instruction_set.insert({ 0x69, rcpu.ADC_impl });
        __instruction_set.insert({ 0x6d, rcpu.ADC_impl });
        __instruction_set.insert({ 0x71, rcpu.ADC_impl });
        __instruction_set.insert({ 0x75, rcpu.ADC_impl });
        __instruction_set.insert({ 0x79, rcpu.ADC_impl });
        __instruction_set.insert({ 0x7d, rcpu.ADC_impl });

        __instruction_set.insert({ 0x21, rcpu.AND_impl });
        __instruction_set.insert({ 0x25, rcpu.AND_impl });
        __instruction_set.insert({ 0x29, rcpu.AND_impl });
        __instruction_set.insert({ 0x2d, rcpu.AND_impl });
        __instruction_set.insert({ 0x31, rcpu.AND_impl });
        __instruction_set.insert({ 0x35, rcpu.AND_impl });
        __instruction_set.insert({ 0x39, rcpu.AND_impl });
        __instruction_set.insert({ 0x3d, rcpu.AND_impl });

        __instruction_set.insert({ 0x06, rcpu.ASL_impl });
        __instruction_set.insert({ 0x0a, rcpu.ASL_impl });
        __instruction_set.insert({ 0x0e, rcpu.ASL_impl });
        __instruction_set.insert({ 0x16, rcpu.ASL_impl });
        __instruction_set.insert({ 0x1e, rcpu.ASL_impl });

        __instruction_set.insert({ 0x90, rcpu.BCC_impl });

        __instruction_set.insert({ 0xb0, rcpu.BCS_impl });

        __instruction_set.insert({ 0xf0, rcpu.BEQ_impl });

        __instruction_set.insert({ 0x24, rcpu.BIT_impl });
        __instruction_set.insert({ 0x2c, rcpu.BIT_impl });

        __instruction_set.insert({ 0x30, rcpu.BMI_impl });

        __instruction_set.insert({ 0xd0, rcpu.BNE_impl });

        __instruction_set.insert({ 0x10, rcpu.BPL_impl });

        __instruction_set.insert({ 0x00, rcpu.BRK_impl });

        __instruction_set.insert({ 0x50, rcpu.BVC_impl });

        __instruction_set.insert({ 0x70, rcpu.BVS_impl });

        __instruction_set.insert({ 0x28, rcpu.CLC_impl });

        __instruction_set.insert({ 0xd8, rcpu.CLD_impl });

        __instruction_set.insert({ 0x58, rcpu.CLI_impl });

        __instruction_set.insert({ 0x88, rcpu.CLV_impl });
        
        __instruction_set.insert({ 0xc1, rcpu.CMP_impl });
        __instruction_set.insert({ 0xc5, rcpu.CMP_impl });
        __instruction_set.insert({ 0xc9, rcpu.CMP_impl });
        __instruction_set.insert({ 0xcd, rcpu.CMP_impl });
        __instruction_set.insert({ 0xd1, rcpu.CMP_impl });
        __instruction_set.insert({ 0xd5, rcpu.CMP_impl });
        __instruction_set.insert({ 0xd9, rcpu.CMP_impl });
        __instruction_set.insert({ 0xdd, rcpu.CMP_impl });

        __instruction_set.insert({ 0xe0, rcpu.CPX_impl });
        __instruction_set.insert({ 0xe4, rcpu.CPX_impl });
        __instruction_set.insert({ 0xec, rcpu.CPX_impl });

        __instruction_set.insert({ 0xc0, rcpu.CPY_impl });
        __instruction_set.insert({ 0xc4, rcpu.CPY_impl });
        __instruction_set.insert({ 0xcc, rcpu.CPY_impl });

        __instruction_set.insert({ 0xc6, rcpu.DEC_impl });
        __instruction_set.insert({ 0xce, rcpu.DEC_impl });
        __instruction_set.insert({ 0xd6, rcpu.DEC_impl });
        __instruction_set.insert({ 0xde, rcpu.DEC_impl });

        __instruction_set.insert({ 0xca, rcpu.DEX_impl });

        __instruction_set.insert({ 0x88, rcpu.DEY_impl });

        __instruction_set.insert({ 0x41, rcpu.EOR_impl });
        __instruction_set.insert({ 0x45, rcpu.EOR_impl });
        __instruction_set.insert({ 0x49, rcpu.EOR_impl });
        __instruction_set.insert({ 0x4d, rcpu.EOR_impl });
        __instruction_set.insert({ 0x51, rcpu.EOR_impl });
        __instruction_set.insert({ 0x55, rcpu.EOR_impl });
        __instruction_set.insert({ 0x59, rcpu.EOR_impl });
        __instruction_set.insert({ 0x5d, rcpu.EOR_impl });

        __instruction_set.insert({ 0xe6, rcpu.INC_impl });
        __instruction_set.insert({ 0xee, rcpu.INC_impl });
        __instruction_set.insert({ 0xf6, rcpu.INC_impl });
        __instruction_set.insert({ 0xfe, rcpu.INC_impl });

        __instruction_set.insert({ 0xe8, rcpu.INX_impl });

        __instruction_set.insert({ 0xc8, rcpu.INY_impl });

        __instruction_set.insert({ 0x4c, rcpu.JMP_impl });
        __instruction_set.insert({ 0x6c, rcpu.JMP_impl });

        __instruction_set.insert({ 0x20, rcpu.JSR_impl });
        
        __instruction_set.insert({ 0xa1, rcpu.LDA_impl });
        __instruction_set.insert({ 0xa5, rcpu.LDA_impl });
        __instruction_set.insert({ 0xa9, rcpu.LDA_impl });
        __instruction_set.insert({ 0xad, rcpu.LDA_impl });
        __instruction_set.insert({ 0xb1, rcpu.LDA_impl });
        __instruction_set.insert({ 0xb5, rcpu.LDA_impl });
        __instruction_set.insert({ 0xb9, rcpu.LDA_impl });
        __instruction_set.insert({ 0xbd, rcpu.LDA_impl });

        __instruction_set.insert({ 0xa2, rcpu.LDX_impl });
        __instruction_set.insert({ 0xa6, rcpu.LDX_impl });
        __instruction_set.insert({ 0xae, rcpu.LDX_impl });
        __instruction_set.insert({ 0xb6, rcpu.LDX_impl });
        __instruction_set.insert({ 0xbe, rcpu.LDX_impl });

        __instruction_set.insert({ 0xa0, rcpu.LDY_impl });
        __instruction_set.insert({ 0xa4, rcpu.LDY_impl });
        __instruction_set.insert({ 0xac, rcpu.LDY_impl });
        __instruction_set.insert({ 0xb4, rcpu.LDY_impl });
        __instruction_set.insert({ 0xbc, rcpu.LDY_impl });

        __instruction_set.insert({ 0x4a, rcpu.LSR_impl });
        __instruction_set.insert({ 0x46, rcpu.LSR_impl });
        __instruction_set.insert({ 0x4e, rcpu.LSR_impl });
        __instruction_set.insert({ 0x56, rcpu.LSR_impl });
        __instruction_set.insert({ 0x5e, rcpu.LSR_impl });

        __instruction_set.insert({ 0xea, rcpu.NOP_impl });
        
        __instruction_set.insert({ 0x01, rcpu.ORA_impl });
        __instruction_set.insert({ 0x05, rcpu.ORA_impl });
        __instruction_set.insert({ 0x09, rcpu.ORA_impl });
        __instruction_set.insert({ 0x0d, rcpu.ORA_impl });
        __instruction_set.insert({ 0x11, rcpu.ORA_impl });
        __instruction_set.insert({ 0x15, rcpu.ORA_impl });
        __instruction_set.insert({ 0x19, rcpu.ORA_impl });
        __instruction_set.insert({ 0x1d, rcpu.ORA_impl });
        
        __instruction_set.insert({ 0x48, rcpu.PHA_impl });

        __instruction_set.insert({ 0x08, rcpu.PHP_impl });

        __instruction_set.insert({ 0x78, rcpu.PLA_impl });

        __instruction_set.insert({ 0x28, rcpu.PLP_impl });

        __instruction_set.insert({ 0x2a, rcpu.ROL_impl });
        __instruction_set.insert({ 0x26, rcpu.ROL_impl });
        __instruction_set.insert({ 0x2e, rcpu.ROL_impl });
        __instruction_set.insert({ 0x36, rcpu.ROL_impl });
        __instruction_set.insert({ 0x3e, rcpu.ROL_impl });

        __instruction_set.insert({ 0x6a, rcpu.ROR_impl });
        __instruction_set.insert({ 0x66, rcpu.ROR_impl });
        __instruction_set.insert({ 0x6e, rcpu.ROR_impl });
        __instruction_set.insert({ 0x76, rcpu.ROR_impl });
        __instruction_set.insert({ 0x7e, rcpu.ROR_impl });

        __instruction_set.insert({ 0x40, rcpu.RTI_impl });

        __instruction_set.insert({ 0x60, rcpu.RTS_impl });
        
        __instruction_set.insert({ 0xf1, rcpu.SBC_impl });
        __instruction_set.insert({ 0xf5, rcpu.SBC_impl });
        __instruction_set.insert({ 0xf9, rcpu.SBC_impl });
        __instruction_set.insert({ 0xfd, rcpu.SBC_impl });
        __instruction_set.insert({ 0xe1, rcpu.SBC_impl });
        __instruction_set.insert({ 0xe5, rcpu.SBC_impl });
        __instruction_set.insert({ 0xe9, rcpu.SBC_impl });
        __instruction_set.insert({ 0xed, rcpu.SBC_impl });

        __instruction_set.insert({ 0x38, rcpu.SEC_impl });

        __instruction_set.insert({ 0xf8, rcpu.SED_impl });

        __instruction_set.insert({ 0x78, rcpu.SEI_impl });

        __instruction_set.insert({ 0x81, rcpu.STA_impl });
        __instruction_set.insert({ 0x85, rcpu.STA_impl });
        __instruction_set.insert({ 0x8d, rcpu.STA_impl });
        __instruction_set.insert({ 0x91, rcpu.STA_impl });
        __instruction_set.insert({ 0x95, rcpu.STA_impl });
        __instruction_set.insert({ 0x99, rcpu.STA_impl });
        __instruction_set.insert({ 0x9d, rcpu.STA_impl });

        __instruction_set.insert({ 0x86, rcpu.STX_impl });
        __instruction_set.insert({ 0x8e, rcpu.STX_impl });
        __instruction_set.insert({ 0x96, rcpu.STX_impl });

        __instruction_set.insert({ 0x84, rcpu.STY_impl });
        __instruction_set.insert({ 0x8c, rcpu.STY_impl });
        __instruction_set.insert({ 0x94, rcpu.STY_impl });

        __instruction_set.insert({ 0xaa, rcpu.TAX_impl });
        
        __instruction_set.insert({ 0xa8, rcpu.TAY_impl });

        __instruction_set.insert({ 0xba, rcpu.TSX_impl });

        __instruction_set.insert({ 0x8a, rcpu.TXA_impl });

        __instruction_set.insert({ 0x9a, rcpu.TXS_impl });

        __instruction_set.insert({ 0xd8, rcpu.TYA_impl });
    }

    std::unordered_map<int, AbstractInstructionSet::executor_t&> const& InstructionSetFor6502::getInstructionMapping() const { return __instruction_set; }
}