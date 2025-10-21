#include <stdio.h>
#include "knights_tour.h"

int main() {
    size_t start_x = 0, start_y = 0; // starting position (change as needed)

    printf("Starting Knight's Tour on %d x %d board...\n", SIZE, SIZE);

    unsigned int visitedSquares = tour_greedy(start_x, start_y);

    printf("Visited %u squares starting at (%zu, %zu)\n", visitedSquares, start_x, start_y);

    // Optional: print the visited pattern
    static int visited[SIZE][SIZE] = {0};
    // Collect visited pattern
    // (we can modify tour_greedy to fill this if needed)
    // For simplicity, let's just print a pattern
    // Note: In this implementation, visited is local to tour_greedy, so you'd want to modify code to output it

    return 0;
}
