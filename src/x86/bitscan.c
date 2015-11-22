#include <bitscan.h>
#include <stddef.h>
#include <cpu.h>

#include <stdio.h>

typedef int (*bs_ll_pfn)(uint64_t);

bs_ll_pfn bsf_pfn = NULL;
bs_ll_pfn bsr_pfn = NULL;

void bit_set(uint64_t* value, uint32_t pos);
void bit_reset(uint64_t* value, uint32_t pos);

int bit_scan_forward_intrin(uint64_t x);
int bit_scan_reverse_intrin(uint64_t x);

int bit_scan_forward_debruijn(uint64_t x);
int bit_scan_reverse_debruijn(uint64_t x);

void bit_scan_setup() {
    if (arch_cpu_has_fast_bitscan()) {
        bsf_pfn = &bit_scan_forward_intrin;
        bsr_pfn = &bit_scan_reverse_intrin;
        printf("CPU has fast bitscan instructions, using compiler intrinsics\n");
    } else {
        bsf_pfn = &bit_scan_forward_debruijn;
        bsr_pfn = &bit_scan_reverse_debruijn;
        printf("Using DeBrunij algorithms for bitscanning\n");
    }
}

int bit_scan_forward_ll(uint64_t v) {
    return bsf_pfn(v);
}
int bit_scan_reverse_ll(uint64_t v) {
    return bsr_pfn(v);
}

void bit_set(uint64_t* value, uint32_t pos) {
#if defined(__x86_64__)
    __asm__ volatile("bts %[pos], %[value]\n\t"
                     :
                     : [value] "m"(*value), [pos] "r"(pos)
                    );
#elif defined(__i386__)
    uint32_t* value_32 = (uint32_t*) value;
    if (pos > 31) {
         __asm__ volatile("bts %[pos], %[value]\n\t"
                     :
                     : [value] "m"(*(value_32 + 1)), [pos] "r"(pos - 32));
    } else {
        __asm__ volatile("bts %[pos], %[value]\n\t"
                     :
                     : [value] "m"(*(value_32)), [pos] "r"(pos));
    }
#endif
}

void bit_reset(uint64_t* value, uint32_t pos) {
#if defined(__x86_64__)
    __asm__ volatile("btr %[pos], %[value]\n\t"
                     :
                     : [value] "m"(*value), [pos] "r"(pos)
                    );
#elif defined(__i386__)
    uint32_t* value_32 = (uint32_t*) value;
    if (pos > 31) {
         __asm__ volatile("btr %[pos], %[value]\n\t"
                     :
                     : [value] "m"(*(value_32 + 1)), [pos] "r"(pos - 32));
    } else {
        __asm__ volatile("btr %[pos], %[value]\n\t"
                     :
                     : [value] "m"(*(value_32)), [pos] "r"(pos));
    }
#endif
}

/* Use ASM CPU intrinsics for fast bit scanning */
int bit_scan_forward_intrin(uint64_t x) {
#if defined(__x86_64__)
    register int bit asm("rax");
    __asm__ volatile("bsf %[value], %%rax\n\t"
                     "jnz 1f\n\t"
                     "mov $-1, %%rax\n\t"
                     "1:\n": "=a" (bit) : [value] "g" (x));
#elif defined(__i386__)
    register int bit asm("eax");
    __asm__ volatile("bsf %[value_low], %%eax\n\t"
                     "jnz 2f\n\t"
                     "bsf %[value_high], %%eax\n\t"
                     "jnz 1f\n\t"
                     "mov $-1, %%eax\n\t"
                     "jmp 2f\n\t"
                     "1:\n\t"
                     "add $32, %%eax\n\t"
                     "2:\n\t" : "=a" (bit) : [value_low] "g" ((uint32_t)(x & 0xFFFFFFFF)), [value_high] "g" ((uint32_t)(x >> 32)));
#endif
    return bit;
}

int bit_scan_reverse_intrin(uint64_t x) {
#if defined(__x86_64__)
    register int bit asm("rax");
    __asm__ volatile("bsr %[value], %%rax\n\t"
                     "jnz 1f\n\t"
                     "mov $-1, %%rax\n\t"
                     "1:\n": "=a" (bit) : [value] "g" (x));
#elif defined(__i386__)
    register int bit asm("eax");
    __asm__ volatile("bsr %[value_high], %%eax\n\t"
                     "jnz 1f\n\t"
                     "bsr %[value_low], %%eax\n\t"
                     "jnz 2f\n\t"
                     "mov $-1, %%eax\n\t"
                     "jmp 2f\n\t"
                     "1:\n\t"
                     "add $32, %%eax\n\t"
                     "2:\n\t" : "=a" (bit) : [value_low] "g" ((uint32_t)(x & 0xFFFFFFFF)), [value_high] "g" ((uint32_t)(x >> 32)));
#endif
    return bit;
}

/* DeBrunij multiplication for bit scanning -> for CPUs that have poor performance on BSF/BSR */
const int index64[64] = {
    0, 47,  1, 56, 48, 27,  2, 60,
    57, 49, 41, 37, 28, 16,  3, 61,
    54, 58, 35, 52, 50, 42, 21, 44,
    38, 32, 29, 23, 17, 11,  4, 62,
    46, 55, 26, 59, 40, 36, 15, 53,
    34, 51, 20, 43, 31, 22, 10, 45,
    25, 39, 14, 33, 19, 30,  9, 24,
    13, 18,  8, 12,  7,  6,  5, 63
};

/**
 * bit_scan_forward_debruijn
 * @author Kim Walisch (2012)
 * @param bb bitboard to scan
 * @return index (0..63) of least significant one bit
 */
int bit_scan_forward_debruijn(uint64_t bb) {
    if (bb == 0)
        return -1;
    const uint64_t debruijn64 = (uint64_t) 0x03f79d71b4cb0a89;
    return index64[((bb ^ (bb-1)) * debruijn64) >> 58];
}

/**
 * bit_scan_reverse_debruijn
 * @authors Kim Walisch, Mark Dickinson
 * @param bb bitboard to scan
 * @return index (0..63) of most significant one bit
 */
int bit_scan_reverse_debruijn(uint64_t bb) {
    if (bb == 0)
        return -1;
    const uint64_t debruijn64 = (uint64_t) 0x03f79d71b4cb0a89;
    bb |= bb >> 1;
    bb |= bb >> 2;
    bb |= bb >> 4;
    bb |= bb >> 8;
    bb |= bb >> 16;
    bb |= bb >> 32;
    return index64[(bb * debruijn64) >> 58];
}
