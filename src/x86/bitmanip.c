// Copyright (C) 2016 Fioratto Raffaele
// Bit manipulation routines for genmoves

// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.

// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.

// You should have received a copy of the GNU General Public License along
// with this program.  If not, see <http://www.gnu.org/licenses/>.


#include <bitmanip.h>
#include <stddef.h>
#include <cpu.h>

#include <stdio.h>

typedef int (*bs_ll_pfn)(uint64_t);

bs_ll_pfn bsf_pfn = NULL;
bs_ll_pfn bsr_pfn = NULL;

int bit_scan_forward_debruijn(uint64_t x);
int bit_scan_reverse_debruijn(uint64_t x);

void bit_manip_setup() {
    if (arch_cpu_has_fast_bitscan()) {
        bsf_pfn = &bit_scan_forward_intrin;
        bsr_pfn = &bit_scan_reverse_intrin;
        printf("CPU has fast bitscan instructions, using compiler intrinsics\n");
    } else {
        bsf_pfn = &bit_scan_forward_debruijn;
        bsr_pfn = &bit_scan_reverse_debruijn;
        printf("Using De Bruijn algorithms for bitscanning\n");
    }
}

int bit_scan_forward_ll(uint64_t v) {
    return bsf_pfn(v);
}
int bit_scan_reverse_ll(uint64_t v) {
    return bsr_pfn(v);
}

/* De Bruijn multiplication for bit scanning -> for CPUs that have poor performance on BSF/BSR */
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
