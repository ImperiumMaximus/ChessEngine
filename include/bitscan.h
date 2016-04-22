#ifndef __BITSCAN_H__
#define __BITSCAN_H__

#include <stdint.h>

void bit_scan_setup();

void bit_set(uint64_t* v, uint32_t pos);
void bit_reset(uint64_t* v, uint32_t pos);

/* Use ASM CPU intrinsics for fast bit scanning */
int bit_scan_forward_intrin(uint64_t x);
int bit_scan_reverse_intrin(uint64_t x);

int bit_scan_forward_ll(uint64_t v);
int bit_scan_reverse_ll(uint64_t v);

#endif /* __BITSCAN_H__ */
