#include "knights_tour.h"
#include <stdio.h>

/** Knight moves: X and Y offsets */
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

/** Checks if a move is valid (inside bounds and not visited) */
bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited) {
    int new_x = x + MOVES_X[move_id];
    int new_y = y + MOVES_Y[move_id];

    if (new_x >= 0 && new_x < SIZE && new_y >= 0 && new_y < SIZE) {
        if (visited[new_y][new_x] == 0) { // Check if square is unvisited
            return true; // Move is valid
        }
    }
    return false; // Move is invalid or outside board
}

/** Executes a greedy tour starting from (start_x, start_y) */
unsigned int tour_greedy(size_t start_x, size_t start_y) {
    int visited[SIZE][SIZE] = {0};          // Keep track of visited squares
    unsigned int count = 1;                   // Count starting position as visited

    size_t cur_x = start_x;                   // Current position x
    size_t cur_y = start_y;                   // Current position y

    visited[cur_y][cur_x] = 1;                // Mark starting square visited

    while (true) {
        bool move_found = false;              // Flag for move possibility

        // Try all possible moves in order
        for (size_t move_id = 0; move_id < MOVE_COUNT; ++move_id) {
            if (move_is_possible(move_id, cur_x, cur_y, visited)) {
                // Make the move
                cur_x += MOVES_X[move_id];
                cur_y += MOVES_Y[move_id];

                // Mark new square as visited
                visited[cur_y][cur_x] = 1;
                count++;                        // Increment visited squares count

                move_found = true;              // A move was made
                break;                          // Wait no more, take the first move
            }
        }

        if (!move_found) {
            // No further moves possible, exit loop
            break;
        }
    }

    return count;                             // How many squares were visited
}


/** Prints the visited board (for debug) */
void print_board(board_t visited) {
    for (int y = 0; y < SIZE; ++y) {
        for (int x = 0; x < SIZE; ++x) {
            printf("%2d ", visited[y][x]);
        }
        printf("\n");
    }
}
