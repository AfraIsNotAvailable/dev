#include "sah.h"
#include <stdlib.h>

// Path: sah.h

int **FENtoBoard(char *FEN) {
    int **board = malloc(8 * sizeof(int *));
    for (int i = 0; i < 8; i++) {
        board[i] = malloc(8 * sizeof(int));
    }
    int i = 0;
    int j = 0;
    while (FEN[i] != ' ') {
        if (FEN[i] == '/') {
            j++;
        } else if (FEN[i] >= '1' && FEN[i] <= '8') {
            j += FEN[i] - '0';
        } else {
            board[j][i] = FEN[i];
            i++;
        }
    }
    return board;
}
