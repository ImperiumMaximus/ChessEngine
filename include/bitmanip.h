// Copyright (C) 2016 Fioratto Raffaele

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


#ifndef __BITMANIP_H__
#define __BITMANIP_H__

#include <stdint.h>

void bit_manip_setup();

void bit_set(uint64_t* v, uint32_t pos);
void bit_reset(uint64_t* v, uint32_t pos);

/* Use ASM CPU intrinsics for fast bit scanning */
int bit_scan_forward_intrin(uint64_t x);
int bit_scan_reverse_intrin(uint64_t x);

/* 64bit byteswapping */
uint64_t bswap64_intrin(uint64_t x);

int bit_scan_forward_ll(uint64_t v);
int bit_scan_reverse_ll(uint64_t v);

#endif /* __BITSCAN_H__ */
