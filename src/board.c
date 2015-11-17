#include "board.h"

#include <string.h>
#include <glib.h>

Board* board_new(void) {
    Board* new_board = g_slice_new(Board);

    memset(new_board, 0, sizeof(Board));

    return new_board;
}
