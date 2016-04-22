#include <stdio.h>

#include <board.h>
#include <cpu.h>
#include <bitscan.h>

int main (int argc, char** argv) {
    arch_setup();
    Board* b = board_new();

    uint64_t x = 0xaa55;
    x = __builtin_bswap64(x);

    printf("%lx\n", x);

    board_free(b);

    return 0;
}
