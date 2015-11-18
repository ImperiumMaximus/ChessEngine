#ifndef __BITSCAN_H__
#define __BITSCAN_H__

#include <stdint.h>

void bit_scan_setup();

int bit_scan_forward_ll(uint64_t v);
int bit_scan_backward_ll(uint64_t v);

#endif /* __BITSCAN_H__ */
