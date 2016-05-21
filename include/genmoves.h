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


#ifndef __GENMOVES_H__
#define __GENMOVES_H__

#include <stdint.h>
#include <board.h>
#include <glib.h>

typedef struct chess_move {
    uint32_t from;
    uint32_t to;
} chess_move;

GSList* moves_generate(Board* b);

uint64_t genmoves_row_attacks(uint64_t occ, uint32_t pos);
uint64_t genmoves_diag_attacks(uint64_t occ, uint32_t pos);
uint64_t genmoves_anti_diag_attacks(uint64_t occ, uint32_t pos);
uint64_t genmoves_column_attacks(uint64_t occ, uint32_t pos);

#endif /* __GENMOVES_H__ */
