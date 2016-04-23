#include <stdio.h>

#include <board.h>
#include <cpu.h>
#include <bitmanip.h>


int main (int argc, char** argv) {
    arch_setup();
    Board* b = board_new();

    uint64_t x = 0x0123456789abcdef;
    x = bswap64_intrin(x);

    printf("%lx\n", x);

    board_free(b);

    return 0;
}
