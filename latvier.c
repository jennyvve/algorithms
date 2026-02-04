
#include "stdbool.h"
#include "stdio.h"

#define N 3

void print_lat(int n, int A[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%i,", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void latvi(int n, int A[N][N], int i, int j) {
    if (j >= n) {
        latvi(n, A, i + 1, 1);
    }

    if (i >= n) {
        print_lat(n, A);
    }

    for (int z = 0; z < n; z++) {
        bool aanwezig = false;

        for (int a = 0; a < i; a++) {
            if (A[a][j] == z) {
                aanwezig = true;
                break;
            }
        }

        for (int a = 0; a < j; a++) {
            if (A[i][a] == z) {
                aanwezig = true;
                break;
            }
        }

        if (!aanwezig) {
            A[i][j] = z;
            latvi(n, A, i, j + 1);
        }
    }
}

int main(void) {
    int A[N][N];

    for (int i = 0; i < N; i++) {
        A[i][0] = i;
        A[0][i] = i;
    }

    latvi(N, A, 1, 1);

    return 0;
}