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
