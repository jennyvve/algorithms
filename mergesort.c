#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void _mergesort(int *a, int *b, int start, int end) {
    int len = (end - start);
    if (len > 1) {
        int mid = len / 2;
        int il = start;
        int ir = start + mid;
        int el = ir;

        _mergesort(a, b, il, el);
        _mergesort(a, b, ir, end);

        int ib = 0;
        while (il < el && ir < end) {
            b[ib++] = a[(a[il] > a[ir]) ? ir++ : il++];
        }

        while (il < el) {
            b[ib++] = a[il++];
        }

        while (ir < end) {
            b[ib++] = a[ir++];
        }

        for (int i = 0; i < ib; i++) {
            a[start + i] = b[i];
        }
    }
}

void mergesort(int *a, int *b, int size) {
    _mergesort(a, b, 0, size);
}

int main(void) {
    srand(time(NULL));

    int buf[SIZE] = {};
    int arr[SIZE] = {};
    for (int i = 0; i < 1000; i++) {
        for (int a = 0; a < SIZE; a++) {
            arr[a] = rand() % (SIZE * 10);
        }

        mergesort(arr, buf, SIZE);
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%i,", arr[i]);
    }
    printf("\n");

    return 0;
}