#include <stdio.h>

int zeroCount(int row, int col, int arr[row][col]) {
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == 0) {
                sum++;
            }
        }
    }
    return sum;
}

void getRepresentative(int row, int col, int arr[row][col]) {
    int nonZeroCount = row * col - zeroCount(row, col, arr);
    
    int rep[nonZeroCount+1][3];
    rep[0][0] = row;
    rep[0][1] = col;
    rep[0][2] = nonZeroCount;

    int index = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] != 0) {
                rep[index][0] = i;  
                rep[index][1] = j;  
                rep[index][2] = arr[i][j];
                index++;
            }
        }
    }

    printf("Row\tCol\tValue\n");
    for (int i = 0; i < nonZeroCount+1; i++) {
        printf("%d\t%d\t%d\n", rep[i][0], rep[i][1], rep[i][2]);
    }
}

int main() {
    int n, m;

    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of cols: ");
    scanf("%d", &m);

    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter element at row %d col %d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    getRepresentative(n, m, arr);

    return 0;
}
