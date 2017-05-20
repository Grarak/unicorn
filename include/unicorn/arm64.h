/* Unicorn Emulator Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2015-2017 */
/* This file is released under LGPL2.
   See COPYING.LGPL2 in root directory for more details
*/

#ifndef UNICORN_ARM64_H
#define UNICORN_ARM64_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER
#pragma warning(disable : 4201)
#endif

//> ARM64 CPU
typedef enum uc_cpu_arm64 {
    UC_CPU_ARM64_A57 = 0,
    UC_CPU_ARM64_A53,
    UC_CPU_ARM64_A72,
    UC_CPU_ARM64_MAX,

    UC_CPU_ARM64_ENDING
} uc_cpu_arm64;

// ARM64 coprocessor registers, use this with UC_ARM64_REG_CP_REG to
// in call to uc_reg_write/read() to access the registers.
typedef struct uc_arm64_cp_reg {
    uint32_t crn; // Coprocessor register number
    uint32_t crm; // Coprocessor register number
    uint32_t op0; // Opcode0
    uint32_t op1; // Opcode1
    uint32_t op2; // Opcode2
    uint64_t val; // The value to read/write
} uc_arm64_cp_reg;

//> ARM64 registers
typedef enum uc_arm64_reg {
    UC_ARM64_REG_INVALID = 0,

    UC_ARM64_REG_X29,
    UC_ARM64_REG_X30,
    UC_ARM64_REG_NZCV,
    UC_ARM64_REG_SP,
    UC_ARM64_REG_WSP,
    UC_ARM64_REG_WZR,
    UC_ARM64_REG_XZR,
    UC_ARM64_REG_B0,
    UC_ARM64_REG_B1,
    UC_ARM64_REG_B2,
    UC_ARM64_REG_B3,
    UC_ARM64_REG_B4,
    UC_ARM64_REG_B5,
    UC_ARM64_REG_B6,
    UC_ARM64_REG_B7,
    UC_ARM64_REG_B8,
    UC_ARM64_REG_B9,
    UC_ARM64_REG_B10,
    UC_ARM64_REG_B11,
    UC_ARM64_REG_B12,
    UC_ARM64_REG_B13,
    UC_ARM64_REG_B14,
    UC_ARM64_REG_B15,
    UC_ARM64_REG_B16,
    UC_ARM64_REG_B17,
    UC_ARM64_REG_B18,
    UC_ARM64_REG_B19,
    UC_ARM64_REG_B20,
    UC_ARM64_REG_B21,
    UC_ARM64_REG_B22,
    UC_ARM64_REG_B23,
    UC_ARM64_REG_B24,
    UC_ARM64_REG_B25,
    UC_ARM64_REG_B26,
    UC_ARM64_REG_B27,
    UC_ARM64_REG_B28,
    UC_ARM64_REG_B29,
    UC_ARM64_REG_B30,
    UC_ARM64_REG_B31,
    UC_ARM64_REG_D0,
    UC_ARM64_REG_D1,
    UC_ARM64_REG_D2,
    UC_ARM64_REG_D3,
    UC_ARM64_REG_D4,
    UC_ARM64_REG_D5,
    UC_ARM64_REG_D6,
    UC_ARM64_REG_D7,
    UC_ARM64_REG_D8,
    UC_ARM64_REG_D9,
    UC_ARM64_REG_D10,
    UC_ARM64_REG_D11,
    UC_ARM64_REG_D12,
    UC_ARM64_REG_D13,
    UC_ARM64_REG_D14,
    UC_ARM64_REG_D15,
    UC_ARM64_REG_D16,
    UC_ARM64_REG_D17,
    UC_ARM64_REG_D18,
    UC_ARM64_REG_D19,
    UC_ARM64_REG_D20,
    UC_ARM64_REG_D21,
    UC_ARM64_REG_D22,
    UC_ARM64_REG_D23,
    UC_ARM64_REG_D24,
    UC_ARM64_REG_D25,
    UC_ARM64_REG_D26,
    UC_ARM64_REG_D27,
    UC_ARM64_REG_D28,
    UC_ARM64_REG_D29,
    UC_ARM64_REG_D30,
    UC_ARM64_REG_D31,
    UC_ARM64_REG_H0,
    UC_ARM64_REG_H1,
    UC_ARM64_REG_H2,
    UC_ARM64_REG_H3,
    UC_ARM64_REG_H4,
    UC_ARM64_REG_H5,
    UC_ARM64_REG_H6,
    UC_ARM64_REG_H7,
    UC_ARM64_REG_H8,
    UC_ARM64_REG_H9,
    UC_ARM64_REG_H10,
    UC_ARM64_REG_H11,
    UC_ARM64_REG_H12,
    UC_ARM64_REG_H13,
    UC_ARM64_REG_H14,
    UC_ARM64_REG_H15,
    UC_ARM64_REG_H16,
    UC_ARM64_REG_H17,
    UC_ARM64_REG_H18,
    UC_ARM64_REG_H19,
    UC_ARM64_REG_H20,
    UC_ARM64_REG_H21,
    UC_ARM64_REG_H22,
    UC_ARM64_REG_H23,
    UC_ARM64_REG_H24,
    UC_ARM64_REG_H25,
    UC_ARM64_REG_H26,
    UC_ARM64_REG_H27,
    UC_ARM64_REG_H28,
    UC_ARM64_REG_H29,
    UC_ARM64_REG_H30,
    UC_ARM64_REG_H31,
    UC_ARM64_REG_Q0,
    UC_ARM64_REG_Q1,
    UC_ARM64_REG_Q2,
    UC_ARM64_REG_Q3,
    UC_ARM64_REG_Q4,
    UC_ARM64_REG_Q5,
    UC_ARM64_REG_Q6,
    UC_ARM64_REG_Q7,
    UC_ARM64_REG_Q8,
    UC_ARM64_REG_Q9,
    UC_ARM64_REG_Q10,
    UC_ARM64_REG_Q11,
    UC_ARM64_REG_Q12,
    UC_ARM64_REG_Q13,
    UC_ARM64_REG_Q14,
    UC_ARM64_REG_Q15,
    UC_ARM64_REG_Q16,
    UC_ARM64_REG_Q17,
    UC_ARM64_REG_Q18,
    UC_ARM64_REG_Q19,
    UC_ARM64_REG_Q20,
    UC_ARM64_REG_Q21,
    UC_ARM64_REG_Q22,
    UC_ARM64_REG_Q23,
    UC_ARM64_REG_Q24,
    UC_ARM64_REG_Q25,
    UC_ARM64_REG_Q26,
    UC_ARM64_REG_Q27,
    UC_ARM64_REG_Q28,
    UC_ARM64_REG_Q29,
    UC_ARM64_REG_Q30,
    UC_ARM64_REG_Q31,
    UC_ARM64_REG_S0,
    UC_ARM64_REG_S1,
    UC_ARM64_REG_S2,
    UC_ARM64_REG_S3,
    UC_ARM64_REG_S4,
    UC_ARM64_REG_S5,
    UC_ARM64_REG_S6,
    UC_ARM64_REG_S7,
    UC_ARM64_REG_S8,
    UC_ARM64_REG_S9,
    UC_ARM64_REG_S10,
    UC_ARM64_REG_S11,
    UC_ARM64_REG_S12,
    UC_ARM64_REG_S13,
    UC_ARM64_REG_S14,
    UC_ARM64_REG_S15,
    UC_ARM64_REG_S16,
    UC_ARM64_REG_S17,
    UC_ARM64_REG_S18,
    UC_ARM64_REG_S19,
    UC_ARM64_REG_S20,
    UC_ARM64_REG_S21,
    UC_ARM64_REG_S22,
    UC_ARM64_REG_S23,
    UC_ARM64_REG_S24,
    UC_ARM64_REG_S25,
    UC_ARM64_REG_S26,
    UC_ARM64_REG_S27,
    UC_ARM64_REG_S28,
    UC_ARM64_REG_S29,
    UC_ARM64_REG_S30,
    UC_ARM64_REG_S31,
    UC_ARM64_REG_W0,
    UC_ARM64_REG_W1,
    UC_ARM64_REG_W2,
    UC_ARM64_REG_W3,
    UC_ARM64_REG_W4,
    UC_ARM64_REG_W5,
    UC_ARM64_REG_W6,
    UC_ARM64_REG_W7,
    UC_ARM64_REG_W8,
    UC_ARM64_REG_W9,
    UC_ARM64_REG_W10,
    UC_ARM64_REG_W11,
    UC_ARM64_REG_W12,
    UC_ARM64_REG_W13,
    UC_ARM64_REG_W14,
    UC_ARM64_REG_W15,
    UC_ARM64_REG_W16,
    UC_ARM64_REG_W17,
    UC_ARM64_REG_W18,
    UC_ARM64_REG_W19,
    UC_ARM64_REG_W20,
    UC_ARM64_REG_W21,
    UC_ARM64_REG_W22,
    UC_ARM64_REG_W23,
    UC_ARM64_REG_W24,
    UC_ARM64_REG_W25,
    UC_ARM64_REG_W26,
    UC_ARM64_REG_W27,
    UC_ARM64_REG_W28,
    UC_ARM64_REG_W29,
    UC_ARM64_REG_W30,
    UC_ARM64_REG_X0,
    UC_ARM64_REG_X1,
    UC_ARM64_REG_X2,
    UC_ARM64_REG_X3,
    UC_ARM64_REG_X4,
    UC_ARM64_REG_X5,
    UC_ARM64_REG_X6,
    UC_ARM64_REG_X7,
    UC_ARM64_REG_X8,
    UC_ARM64_REG_X9,
    UC_ARM64_REG_X10,
    UC_ARM64_REG_X11,
    UC_ARM64_REG_X12,
    UC_ARM64_REG_X13,
    UC_ARM64_REG_X14,
    UC_ARM64_REG_X15,
    UC_ARM64_REG_X16,
    UC_ARM64_REG_X17,
    UC_ARM64_REG_X18,
    UC_ARM64_REG_X19,
    UC_ARM64_REG_X20,
    UC_ARM64_REG_X21,
    UC_ARM64_REG_X22,
    UC_ARM64_REG_X23,
    UC_ARM64_REG_X24,
    UC_ARM64_REG_X25,
    UC_ARM64_REG_X26,
    UC_ARM64_REG_X27,
    UC_ARM64_REG_X28,

    UC_ARM64_REG_V0,
    UC_ARM64_REG_V1,
    UC_ARM64_REG_V2,
    UC_ARM64_REG_V3,
    UC_ARM64_REG_V4,
    UC_ARM64_REG_V5,
    UC_ARM64_REG_V6,
    UC_ARM64_REG_V7,
    UC_ARM64_REG_V8,
    UC_ARM64_REG_V9,
    UC_ARM64_REG_V10,
    UC_ARM64_REG_V11,
    UC_ARM64_REG_V12,
    UC_ARM64_REG_V13,
    UC_ARM64_REG_V14,
    UC_ARM64_REG_V15,
    UC_ARM64_REG_V16,
    UC_ARM64_REG_V17,
    UC_ARM64_REG_V18,
    UC_ARM64_REG_V19,
    UC_ARM64_REG_V20,
    UC_ARM64_REG_V21,
    UC_ARM64_REG_V22,
    UC_ARM64_REG_V23,
    UC_ARM64_REG_V24,
    UC_ARM64_REG_V25,
    UC_ARM64_REG_V26,
    UC_ARM64_REG_V27,
    UC_ARM64_REG_V28,
    UC_ARM64_REG_V29,
    UC_ARM64_REG_V30,
    UC_ARM64_REG_V31,

    //> pseudo registers
    UC_ARM64_REG_PC, // program counter register

    UC_ARM64_REG_CPACR_EL1,

    //> thread registers, depreciated, use UC_ARM64_REG_CP_REG instead
    UC_ARM64_REG_TPIDR_EL0,
    UC_ARM64_REG_TPIDRRO_EL0,
    UC_ARM64_REG_TPIDR_EL1,

    UC_ARM64_REG_PSTATE,

    //> exception link registers, depreciated, use UC_ARM64_REG_CP_REG instead
    UC_ARM64_REG_ELR_EL0,
    UC_ARM64_REG_ELR_EL1,
    UC_ARM64_REG_ELR_EL2,
    UC_ARM64_REG_ELR_EL3,

    //> stack pointers registers, depreciated, use UC_ARM64_REG_CP_REG instead
    UC_ARM64_REG_SP_EL0,
    UC_ARM64_REG_SP_EL1,
    UC_ARM64_REG_SP_EL2,
    UC_ARM64_REG_SP_EL3,

    //> other CP15 registers, depreciated, use UC_ARM64_REG_CP_REG instead
    UC_ARM64_REG_TTBR0_EL1,
    UC_ARM64_REG_TTBR1_EL1,

    UC_ARM64_REG_ESR_EL0,
    UC_ARM64_REG_ESR_EL1,
    UC_ARM64_REG_ESR_EL2,
    UC_ARM64_REG_ESR_EL3,

    UC_ARM64_REG_FAR_EL0,
    UC_ARM64_REG_FAR_EL1,
    UC_ARM64_REG_FAR_EL2,
    UC_ARM64_REG_FAR_EL3,

    UC_ARM64_REG_PAR_EL1,

    UC_ARM64_REG_MAIR_EL1,

    UC_ARM64_REG_VBAR_EL0,
    UC_ARM64_REG_VBAR_EL1,
    UC_ARM64_REG_VBAR_EL2,
    UC_ARM64_REG_VBAR_EL3,

    UC_ARM64_REG_CP_REG,

    //> floating point control and status registers
    UC_ARM64_REG_FPCR,
    UC_ARM64_REG_FPSR,

    UC_ARM64_REG_ESR,			// exception syndrome register

    UC_ARM64_REG_ENDING, // <-- mark the end of the list of registers

    //> alias registers

    UC_ARM64_REG_IP0 = UC_ARM64_REG_X16,
    UC_ARM64_REG_IP1 = UC_ARM64_REG_X17,
    UC_ARM64_REG_FP = UC_ARM64_REG_X29,
    UC_ARM64_REG_LR = UC_ARM64_REG_X30,
} uc_arm64_reg;

// Callback function for tracing MRS/MSR/SYS/SYSL. If this callback returns
// true, the read/write to system registers would be skipped (even though it may
// cause exceptions!). Note one callback per instruction is allowed.
// @reg: The source/destination register.
// @cp_reg: The source/destincation system register.
// @user_data: The user data.
typedef uint32_t (*uc_cb_insn_sys_t)(uc_engine *uc, uc_arm64_reg reg,
                                     const uc_arm64_cp_reg *cp_reg,
                                     void *user_data);

//> ARM64 instructions
typedef enum uc_arm64_insn {
    UC_ARM64_INS_INVALID = 0,

    UC_ARM64_INS_MRS,
    UC_ARM64_INS_MSR,
    UC_ARM64_INS_SYS,
    UC_ARM64_INS_SYSL,

    UC_ARM64_INS_ENDING
} uc_arm64_insn;

#ifdef __cplusplus
}
#endif

#endif
