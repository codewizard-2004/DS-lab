#include <stdio.h>

// Function to count zeros in the matrix
int zeroCount(int arr[][10], int row, int col) {
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

// Function to calculate the sparsity of the matrix
float sparsity(int zero, int row, int col) {
    return (float)zero / (row * col);
}

int main() {
    int n, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Declare the array with a fixed column size
    int arr[n][10]; // Use a maximum of 10 columns

    // Input the matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter element at row %d col %d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Count zeros and check if the matrix is sparse
    int zeroCountResult = zeroCount(arr, n, m);
    if (zeroCountResult < (n * m) / 2) {
        printf("Not a sparse matrix\n");
    } else {
        printf("Sparsity: %.2f\n", sparsity(zeroCountResult, n, m));
    }

    return 0;
}
