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


#ifndef __BOARD_H__
#define __BOARD_H__

#include <stdint.h>

typedef enum PieceType {
    FREE = 0,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    MAX_TYPE = KING
} PieceType;

typedef enum PieceColor {
    WHITE = -1,
    BLACK = +1,
    MAX_COLOR = 2
} PieceColor;

enum {
    BoardRowSize = 8,
    BoardColumnSize = 8
};

typedef struct Board {
    // pieces bitboards
    uint64_t piecesType[MAX_COLOR][MAX_TYPE];
    uint64_t piecesColor[MAX_COLOR];

    // mailbox
    uint8_t mailbox[BoardRowSize][BoardColumnSize];

    // color
    PieceColor turnColor;
} Board;

Board* board_new(void);
Board* board_dup(Board* other_board);
void   board_free(Board* b);

static inline void board_change_turn(Board* b) {
    b->turnColor = -(b->turnColor);
}

#endif /* __BOARD_H__ */
