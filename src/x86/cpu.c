#include <cpu.h>
#include <bitscan.h>
#include <x86/arch.h>

#include <string.h>

X86Cpu arch_running_cpu;

void arch_setup(void) {
    uint32_t regs[4];
    char vendor_string[13];

    cpuid(GET_VENDOR_ID, regs);

    memcpy(vendor_string, regs + 1, 4);
    memcpy(vendor_string + 4, regs + 3, 4);
    memcpy(vendor_string + 8, regs + 2, 4);

    vendor_string[12] = 0;

    if (!strcmp(vendor_string, INTEL_VENDOR_STR)) {
        arch_running_cpu.brand = INTEL;
    } else if (!strcmp(vendor_string, AMD_VENDOR_STR)) {
        arch_running_cpu.brand = AMD;
    } else if (!strcmp(vendor_string, VIA1_VENDOR_STR) || !strcmp(vendor_string, VIA2_VENDOR_STR)) {
        arch_running_cpu.brand = VIA;
    } else {
        arch_running_cpu.brand = UNKNOWN;
    }

    cpuid(GET_FEATURES, regs);

    arch_running_cpu.family = (regs[0] & EAX_INFO_FAMILY) >> EAX_INFO_FAMILY_SHIFT;
    arch_running_cpu.model = (regs[0] & EAX_INFO_MODEL) >> EAX_INFO_MODEL_SHIFT;

    if (arch_running_cpu.family == 0x6 || arch_running_cpu.family == 0xF) {
        arch_running_cpu.model |= ((regs[0] & EAX_INFO_EXTENDED_MODEL) >> EAX_INFO_EXT_MODEL_SHIFT);
    }

    switch(arch_running_cpu.brand) {
    case INTEL:
        if (arch_running_cpu.family < 6) // running this on a Pentium I?
            arch_running_cpu.has_fast_bit_scan = false;
        else if (arch_running_cpu.family == 6) { // Everything throw out by Intel except Pentium I and IV
            if (arch_running_cpu.model == 28) // Special case for Atom
                arch_running_cpu.has_fast_bit_scan = false;
            else
                arch_running_cpu.has_fast_bit_scan = true;
        } else if (arch_running_cpu.family == 0x0F) // Pentium IV
            arch_running_cpu.has_fast_bit_scan = false;
        else // Buggy CPU?
            arch_running_cpu.has_fast_bit_scan = false;
        break;
    case AMD:
        if (arch_running_cpu.family < 0x10) // K7, K8
            arch_running_cpu.has_fast_bit_scan = false;
        else
            arch_running_cpu.has_fast_bit_scan = true;
    case VIA:
    case UNKNOWN:
    default:
        arch_running_cpu.has_fast_bit_scan = false;
    }

    bit_scan_setup();
}

bool arch_cpu_has_fast_bitscan(void) {
    return arch_running_cpu.has_fast_bit_scan;
}
