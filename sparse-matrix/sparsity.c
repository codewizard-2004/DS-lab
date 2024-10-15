#include <stdio.h>

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

float sparsity(int row , int cols , int arr[row][cols]){
    int zeroes = countZeros(row , cols , arr);
    if (zeroes < (row*cols)/2){
        return -1;
    }else{
        return (float)zeroes/(row*cols);
    }
    
}





int main() {
    
    int arr[3][3] = {{0,0,2},
                     {3,1,0},
                     {0,0,0}};
    float f =  sparsity(3 ,3 ,arr);
    printf(f==-1?"Not a sparse Matrix":"Sparsity:%f" , f);

    return 0;
}