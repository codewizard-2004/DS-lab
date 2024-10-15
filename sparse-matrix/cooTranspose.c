#include<stdio.h>

//1. To Input a sparse matrix from user 
//2. Convert it to representative form 
//3. Find the transpose of the matrix

typedef struct{
    int row;
    int col;
    int data;
}coo;

int countZeros(int row , int cols , int arr[row][cols]){
    int count = 0;
    for (int i = 0; i<row ; i++){
        for(int j = 0; j<cols ; j++){
            if (arr[i][j] == 0){
                count++;
            }
        }
    }
    return count;
    
}

void printSparse(coo spr[] , int rows){
    printf("Rows\tCols\tData\n");
    for(int i = 0; i<rows ; i++){
        printf("%d\t%d\t%d\n" , spr[i].row , spr[i].col , spr[i].data);
    }
}

void take_transpose(coo spr[] , int rows){
    for(int i = 0; i<rows ; i++){
        int temp = spr[i].row;
        spr[i].row = spr[i].col;
        spr[i].col = temp;
    }
}

void convert_to_coo(int row , int cols , int arr[row][cols]){
    int zeroes = countZeros(row , cols , arr);
    coo spr[(row*cols)-zeroes+1];
    //Updating the metadata;
    spr[0].row = row;
    spr[0].col = cols;
    spr[0].data = (row*cols)-zeroes;

    int index = 1;
    for (int i = 0; i< row ; i++){
        for(int j = 0; j < cols; j++){
            if (arr[i][j] != 0){
                spr[index].row = i;
                spr[index].col = j;
                spr[index].data = arr[i][j];
                index++;
            }
        }
    }
    printf("Input Matrix\n");
    printSparse(spr , (row*cols)-zeroes+1);
    take_transpose(spr , (row*cols)-zeroes+1);
    printf("\nAfter Transposing\n");
    printSparse(spr , (row*cols)-zeroes+1);
}

int main() {
    
    int arr[3][3] = {{0,0,2},
                     {3,1,0},
                     {0,0,0}};
    convert_to_coo(3 , 3 , arr);

    return 0;
}