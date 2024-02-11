#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char c1, c2;
    int r1, r2;
} move;

char **FENtoBoard(char *FEN) {
    char **board = malloc(8 * sizeof(int *));
    for (int i = 0; i < 8; i++) {
        board[i] = malloc(8 * sizeof(int));
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (FEN[i] != ' ') {
        if (FEN[i] == '/') {
            j++;
            i++;
            k = 0;
        } else if (FEN[i] >= '1' && FEN[i] <= '8') {
            k += FEN[i] - '0';
            i++;
        } else {
            board[j][k] = FEN[i];
            i++;
            k++;
            // printf("j:%d\n", j%8);
            // printf("k:%d\n", (k-1)%8);
            // printf("FEN:%c BOARD:%c\n", FEN[i-1], board[j%8][k%8]);
        }
    }
    return board;
}

void check_bishop(char **table, int i, int j, int queen) { // diagonal lines
    int k = 1;
    int initial_i = i;
    int initial_j = j;
    while (i + k < 8 && j + k < 8) {
        if (table[i + k][j + k] != 0) {
            break;
        }
        if (queen) {
            printf("queen to:%c%d\n", 'a' + j - k, i + (8 - k));
        } else {
            printf("%c%d-%c%d\n", 'a' + j, 8 - i, 'a' + j + k, i + (2 - k)); // dreapta-jos
        }
        k++;
    }
    k = 1;
    while (i - k >= 0 && j - k >= 0) {
        if (table[i - k][j - k] != 0) {
            break;
        }
        if (queen) {
            printf("queen to:%c%d\n", 'a' + j - k, i + (8 - k));
        } else {
            printf("bishop to:%c%d\n", 'a' + j - k, i +k +2); // stanga-sus
        }
        k++;
    }
    k = 1;
    while (i + k < 8 && j - k >= 0) {
        if (table[i + k][j - k] != 0) {
            break;
        }
        if (queen) {
            printf("queen to:%c%d\n", 'a' + j - k, i + (8 - k));
        } else {
            printf("bishop to:%c%d\n", 'a' + j - k, i  - k + 2); // stanga-jos
        }
        k++;
    }
    k = 1;
    while (i - k >= 0 && j + k < 8) {
        if (table[i - k][j + k] != 0) {
            break;
        }
        if (queen) {
            printf("queen to:%c%d\n", 'a' + j - k, i + (8 - k));
        } else {
            printf("bishop to:%c%d\n", 'a' + j + k, i + k + 2); // dreapta-sus
        }
        k++;
    }
}

void check_rook(char **table, int i, int j, int queen) {
    int k = 1;
    while (i + k < 8) {
        if (table[i + k][j] != 0) {
            break;
        }
        if (queen) {
            printf("queen to:%c%d\n", 'a' + j, i + (8 - k));
        } else {
            printf("rook to:%c%d\n", 'a' + j, i + (8 - k));
        }
        k++;
    }
    k = 1;
    while (i - k >= 0) {
        if (table[i - k][j] != 0) {
            break;
        }
        if (queen) {
            printf("queen to:%c%d\n", 'a' + j, i - (8 - k));
        } else {
            printf("rook to:%c%d\n", 'a' + j, i - (8 - k));
        }
        k++;
    }
    k = 1;
    while (j + k < 8) {
        if (table[i][j + k] != 0) {
            break;
        }
        if (queen) {
            printf("queen to:%c%d\n", 'a' + j + k, i);
        } else {
            printf("rook to:%c%d\n", 'a' + j + k, i);
        }
        k++;
    }
    k = 1;
    while (j - k >= 0) {
        if (table[i][j - k] != 0) {
            break;
        }
        if (queen) {
            printf("queen to:%c%d\n", 'a' + j - k, i);
        } else {
            printf("rook to:%c%d\n", 'a' + j - k, i);
        }
        k++;
    }
}

void check_queen(char **table, int i, int j) {
    check_bishop(table, i, j, 1);
    check_rook(table, i, j, 1);
}

void check_piece(char **table, int i, int j) {
    if (table[i][j] == 'Q' || table[i][j] == 'q') {
        check_queen(table, i, j);
    } else if (table[i][j] == 'B' || table[i][j] == 'b') {
        check_bishop(table, i, j, 0);
    } else if (table[i][j] == 'R' || table[i][j] == 'r') {
        check_rook(table, i, j, 0);
    }
}

// tomove: 'b' or 'w'
// returns a list of moves for the queen, the bishop and the rook of the given
// color
void all_moves(char **table, char tomove) {
    move *moves = malloc(3 * sizeof(move));

    int k = 0;
    char mapW[3] = {'Q', 'R', 'B'};
    char mapB[3] = {'q', 'r', 'b'};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tomove == 'w') {
                if (table[i][j] == 'Q' || table[i][j] == 'B' ||
                    table[i][j] == 'R') {
                    while (k < 3) {
                        if (table[i][j] == mapW[k]) {
                            break;
                        }
                        k++;
                    }
                    moves[k].c1 = (char)('a' + i);
                    moves[k].r1 = j;
                    // moves[k].c2 = i;
                    // moves[k].r2 = j;

                    check_piece(table, i, j);
                }
            } else if (tomove == 'b') {
                if (table[i][j] == 'q' || table[i][j] == 'b' ||
                    table[i][j] == 'r') {
                    while (k < 3) {
                        if (table[i][j] == mapB[k]) {
                            break;
                        }
                        k++;
                    }
                    moves[k].c1 = (char)('a' + i);
                    moves[k].r1 = j;
                    // moves[k].c2 = i;
                    // moves[k].r2 = j;

                    check_piece(table, i, j);
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    char **board = FENtoBoard("8/8/8/8/2b5/8/8/8 ");

    for (int i = 0; i < 8; i++) {
        printf("%d: ", 8 - i);
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 0) {
                printf("□ ");
            } else {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("  ");
    for (int j = 0; j < 8; j++) {
        printf(" %c", 'a' + j);
    }
    printf("\n");

    all_moves(board, 'b');

    return 0;
}
