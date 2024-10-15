// To convert a normal matrix into COO form using structures

#include<stdio.h>


typedef struct{
    int row;
    int col;
    int data;
}COO;

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

void printSparse(COO spr[] , int rows){
    printf("Rows\tCols\tData\n");
    for(int i = 0; i<rows ; i++){
        printf("%d\t%d\t%d\n" , spr[i].row , spr[i].col , spr[i].data);
    }
}

void create_coo(int rows , int cols , int arr[rows][cols]){
    int zeroes = countZeros(rows , cols , arr);
    COO spr[(rows*cols)-zeroes+1];
    // Setup the metadata;
    spr[0].row = rows;
    spr[0].col = cols;
    spr[0].data = (rows*cols)-zeroes;
    int index = 1;
    for(int i = 0 ; i< rows; i++){
        for(int j = 0 ; j<cols ; j++){
            if(arr[i][j] != 0){
                spr[index].row = i;
                spr[index].col = j;
                spr[index].data = arr[i][j];
                index++;
            }
        }
    }
    printSparse(spr , (rows*cols)-zeroes+1);

}

int main() {
    
    int arr[3][3] = {{0,0,2},
                     {3,1,0},
                     {0,0,0}};
    create_coo(3 , 3 ,arr);

    return 0;
}