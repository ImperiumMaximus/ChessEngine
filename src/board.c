// Copyright (C) 2016 Fioratto Raffaele
// ChessEngine's board interface

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


#include "board.h"

#include <string.h>
#include <glib.h>
#include <assert.h>

uint8_t board_initial_mailbox[8][8] = {
    { -ROOK, -KNIGHT, -BISHOP, -QUEEN, -KING, -BISHOP, -KNIGHT, -ROOK },
    { -PAWN, -PAWN, -PAWN, -PAWN, -PAWN, -PAWN, -PAWN, -PAWN },
    { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE },
    { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE },
    { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE },
    { FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE },
    { PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN },
    { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK },
};

Board* board_new(void) {
    Board* new_board = g_slice_new(Board);

    memset(new_board, 0, sizeof(Board));

    new_board->turnColor = WHITE;
    new_board->piecesColor[WHITE + 1] = 0xFFFF;
    new_board->piecesColor[BLACK] = (uint64_t) 0xFFFF << 48;

    new_board->piecesType[WHITE + 1][PAWN - 1] = 0xFF << 8;
    new_board->piecesType[WHITE + 1][KNIGHT - 1] = 0x42;
    new_board->piecesType[WHITE + 1][BISHOP - 1] = 0x24;
    new_board->piecesType[WHITE + 1][ROOK - 1] = 0x81;
    new_board->piecesType[WHITE + 1][QUEEN - 1] = 0x08;
    new_board->piecesType[WHITE + 1][KING - 1] = 0x10;

    new_board->piecesType[BLACK][PAWN - 1] = (uint64_t) 0xFF << 48;
    new_board->piecesType[BLACK][KNIGHT - 1] = (uint64_t) 0x42 << 56;
    new_board->piecesType[BLACK][BISHOP - 1] = (uint64_t) 0x24 << 56;
    new_board->piecesType[BLACK][ROOK - 1] = (uint64_t) 0x81 << 56;
    new_board->piecesType[BLACK][QUEEN - 1] = (uint64_t) 0x08 << 56;
    new_board->piecesType[BLACK][KING - 1] = (uint64_t) 0x10 << 56;

    memcpy(new_board->mailbox, board_initial_mailbox, sizeof(board_initial_mailbox));

    return new_board;
}

Board* board_dup(Board* other_board) {
    assert(other_board != NULL);

    Board* dup_board = g_slice_dup(Board, other_board);

    return dup_board;
}

void board_free(Board* b) {
    assert(b != NULL);

    g_slice_free(Board, b);
}
