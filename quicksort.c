#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

inline void swap(int *a, int x, int y) {
    int t = a[x];
    a[x] = a[y];
    a[y] = t;
}

int partition(int *a, int start, int end) {
    int piv = a[start];
    int ps = start - 1;
    int pe = end + 1;

    for (;;) {
        while (a[++ps] < piv);
        while (a[--pe] > piv);

        if (ps >= pe) {
            return pe;
        }

        swap(a, ps, pe);
    }
}

void _quicksort(int *a, int start, int end) {
    if (start >= 0 && start < end && end >= 0) {
        int piv = partition(a, start, end);
        _quicksort(a, start, piv);
        _quicksort(a, piv + 1, end);
    }
}
void quicksort(int *a, int size) { _quicksort(a, 0, size - 1); }

int main(void) {
    srand(time(NULL));

    int buf[SIZE] = {};
    int arr[SIZE] = {};
    for (int i = 0; i < 1000; i++) {
        for (int a = 0; a < SIZE; a++) {
            arr[a] = rand() % (SIZE * 10);
        }

        quicksort(arr, SIZE);
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%i,", arr[i]);
    }
    printf("\n");

    return 0;
}