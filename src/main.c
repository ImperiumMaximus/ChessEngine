#include <stdio.h>

#include <board.h>
#include <cpu.h>
#include <bitscan.h>

int main (int argc, char** argv) {
    arch_setup();
    Board* b = board_new();

    getchar();

    board_free(b);

    return 0;
}
