#include <stdio.h>
#include <stdlib.h>

int **create(int n, int m, int L, int R) {
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            a[i][j] = (rand() % (R - L + 1)) + L;
        }
    }
    return a;
}

void print(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

int **select_rows(int **a, int cols, int l, int r) {
    int **b = (int **)malloc((r - l + 1) * sizeof(int *));
    for (int i = 0; i <= r - l; i++) {
        b[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            b[i][j] = a[i + l - 1][j];
        }
    }

    return b;
}

int **add_cols(int **a, int n, int m, int k, int L, int R) {
    for (int i = 0; i < n; i++) {
        a[i] = (int *)realloc(a[i], (m + k) * sizeof(int));
        for (int j = m; j < m + k; j++) {
            a[i][j] = (rand() % (R - L + 1)) + L;
        }
    }

    return a;
}

int main(int argv, char **argc) {
    int **v = create(3, 3, -4, 5);

    printf("\n");

    print(v, 3, 3);

    printf("\n");

    int **z = select_rows(v, 3, 2, 3);
    print(z, 2, 3);

    printf("\n");

    add_cols(z, 2, 3, 2, -10, 20);
    print(z, 2, 5);

    for (int i = 0; i < 2; i++) {
        free(z[i]);
    }
    free(z);
    for (int i = 0; i < 3; i++) {
        free(v[i]);
    }
    free(v);

    return 0;
}
