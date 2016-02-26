#ifndef __X86_ARCH_H__
#define __X86_ARCH_H__

#include <stdbool.h>
#include <stdint.h>

typedef enum X86CpuBrand {
    UNKNOWN = 0,
    INTEL,
    AMD,
    VIA
} X86CpuBrand;

typedef enum X86CpuidCodes {
    GET_VENDOR_ID = 0,
    GET_FEATURES = 1,
} X86CpuidCodes;

typedef enum X86EAXCpuInfo {
    EAX_INFO_STEPPING = 0xF,
    EAX_INFO_MODEL = 0xF0,
    EAX_INFO_FAMILY = 0xF00,
    EAX_INFO_EXTENDED_MODEL = 0xF0000,

    EAX_INFO_STEPPING_SHIFT = 0,
    EAX_INFO_MODEL_SHIFT = 4,
    EAX_INFO_FAMILY_SHIFT = 8,
    EAX_INFO_EXT_MODEL_SHIFT = 16 - 4, /* see Intel Document Number 253666,
                                       ** basically a 4-bits left shift is needed before doing the sum with the base model
                                       ** so we already adjust the value in only one shift
                                       */
} X86EAXCpuInfo;

static const char* INTEL_VENDOR_STR = "GenuineIntel";
static const char* AMD_VENDOR_STR   = "AuthenticAMD";
static const char* VIA1_VENDOR_STR  = "VIA VIA VIA ";
static const char* VIA2_VENDOR_STR  = "CentaurHauls";

typedef struct X86Cpu {
    X86CpuBrand brand;
    int model;
    int family;
    bool has_fast_bit_scan;
} X86Cpu;

#ifdef __GNUC__
	static inline void __cpuid(uint32_t regs[4], uint32_t code) {
		__asm__ volatile("cpuid" : "=a"(regs[0]), "=b"(regs[1]), "=c"(regs[2]), "=d"(regs[3]) : "a" (code));
	}
#endif

#endif /* __X86_ARCH_H__ */
