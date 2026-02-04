
#include "stdbool.h"
#include "stdio.h"

#define N 7
#define K 3

void part(int n, int A[N], int k, int i, int m, int s) {
    if (s > n) {
        return;
    }

    if (k - 1 == i) {
        A[k - 1] = n - s;
        if (A[k - 1] < m) {
            return;
        }
        for (int z = 0; z < k; z++) {
            printf("%i,", A[z]);
        }
        printf("\n");
    }

    for (int z = (n - k); z > 0; z--) {
        A[i] = z;
        part(n, A, k, i + 1, n - m, s + z);
    }
}

int main(void) {
    int A[N];

    part(N, A, K, 0, 1, 0);

    return 0;
}