#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

void bubblesort(int *b, int size) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < size - 1; i++) {
            if (b[i] > b[i + 1]) {
                int t = b[i + 1];
                b[i + 1] = b[i];
                b[i] = t;
                sorted = false;
            }
        }
    }
}

int main(void) {
    srand(time(NULL));

    int buf[SIZE] = {};
    int arr[SIZE] = {};
    for (int i = 0; i < 10000; i++) {
        int size = (SIZE / 2) + rand() % (SIZE - SIZE / 2);

        for (int a = 0; a < size; a++) {
            arr[a] = rand() % (SIZE * 10);
        }

        bubblesort(arr, size);
    }

    return 0;
}