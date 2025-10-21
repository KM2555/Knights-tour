#ifndef KNIGHTS_TOUR_H
#define KNIGHTS_TOUR_H

#include <stdbool.h>
#include <stddef.h>

#define SIZE 8
#define MOVE_COUNT 8

typedef int board_t[SIZE][SIZE];

bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited);
unsigned int tour_greedy(size_t start_x, size_t start_y);
void print_board(board_t visited);

#endif // KNIGHTS_TOUR_H
