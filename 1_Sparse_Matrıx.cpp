#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

int main() {
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int r = 4, c = 5;
    int size = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] != 0) size++;
        }
    }

    struct Element sparse[size];
    int k = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    return 0;
}
