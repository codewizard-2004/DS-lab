#include<stdio.h>

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

// Function to create the sparse matrix representation
void sparse(int row, int col, int arr[row][col], int rep[][3]) {
    int nonZeroCount = row * col - zeroCount(row, col, arr);
    
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
}

// Function to display a sparse matrix
void displaySparse(int sparse[][3], int nonZeroCount) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < nonZeroCount + 1; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

// Function to add two sparse matrices
void addSparse(int rep1[][3], int rep2[][3], int result[][3]) {
    if (rep1[0][0] != rep2[0][0] || rep1[0][1] != rep2[0][1]) {
        printf("Matrices cannot be added. Dimensions do not match.\n");
        return;
    }

    int row = rep1[0][0];
    int col = rep1[0][1];
    int nonZeroCount1 = rep1[0][2];
    int nonZeroCount2 = rep2[0][2];

    int i = 1, j = 1, k = 1;
    result[0][0] = row;
    result[0][1] = col;

    while (i <= nonZeroCount1 && j <= nonZeroCount2) {
        // If positions match, add the values
        if (rep1[i][0] == rep2[j][0] && rep1[i][1] == rep2[j][1]) {
            result[k][0] = rep1[i][0];
            result[k][1] = rep1[i][1];
            result[k][2] = rep1[i][2] + rep2[j][2];
            i++;
            j++;
            k++;
        }
        // Copy the element from rep1 if it comes first
        else if (rep1[i][0] < rep2[j][0] || (rep1[i][0] == rep2[j][0] && rep1[i][1] < rep2[j][1])) {
            result[k][0] = rep1[i][0];
            result[k][1] = rep1[i][1];
            result[k][2] = rep1[i][2];
            i++;
            k++;
        }
        // Copy the element from rep2 if it comes first
        else {
            result[k][0] = rep2[j][0];
            result[k][1] = rep2[j][1];
            result[k][2] = rep2[j][2];
            j++;
            k++;
        }
    }

    // Copy remaining elements from rep1
    while (i <= nonZeroCount1) {
        result[k][0] = rep1[i][0];
        result[k][1] = rep1[i][1];
        result[k][2] = rep1[i][2];
        i++;
        k++;
    }

    // Copy remaining elements from rep2
    while (j <= nonZeroCount2) {
        result[k][0] = rep2[j][0];
        result[k][1] = rep2[j][1];
        result[k][2] = rep2[j][2];
        j++;
        k++;
    }

    // Set the non-zero count of the result
    result[0][2] = k - 1;
}

int main() {
    int n, m;

    // Input matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of cols: ");
    scanf("%d", &m);

    int arr1[n][m], arr2[n][m];

    // Input first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Element at row %d col %d: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Element at row %d col %d: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }

    // Prepare sparse matrix representations
    int nonZeroCount1 = n * m - zeroCount(n, m, arr1);
    int nonZeroCount2 = n * m - zeroCount(n, m, arr2);
    int rep1[nonZeroCount1 + 1][3], rep2[nonZeroCount2 + 1][3];

    sparse(n, m, arr1, rep1);
    sparse(n, m, arr2, rep2);

    // Display sparse matrices
    printf("\nSparse Matrix 1:\n");
    displaySparse(rep1, nonZeroCount1);
    
    printf("\nSparse Matrix 2:\n");
    displaySparse(rep2, nonZeroCount2);

    // Add sparse matrices
    int result[nonZeroCount1 + nonZeroCount2 + 1][3];
    addSparse(rep1, rep2, result);

    // Display the result
    printf("\nResultant Sparse Matrix after Addition:\n");
    displaySparse(result, result[0][2]);

    return 0;
}
