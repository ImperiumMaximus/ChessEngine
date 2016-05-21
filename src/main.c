// Copyright (C) 2016 Fioratto Raffaele
// ChessEngine's frontend entry point

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

#include <stdio.h>

#include <board.h>
#include <cpu.h>
#include <bitmanip.h>


int main (int argc, char** argv) {
    arch_setup();
    Board* b = board_new();

	uint64_t v = 0;
	bit_set(&v, 35);

	printf("%lld\n", v);

	printf("%d\n", bit_scan_forward_intrin(v));
	printf("%d\n", bit_scan_reverse_intrin(v));

    uint64_t x = 0x0123456789abcdef;
    x = bswap64_intrin(x);

    printf("%llx\n", x);

    board_free(b);

	getchar();

    return 0;
}
