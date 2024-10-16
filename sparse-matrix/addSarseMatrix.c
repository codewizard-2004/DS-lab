#include<stdio.h>

typedef struct{
    int row;
    int col;
    int data;
}coo;

void printSparse(coo spr[]){
    printf("Rows\tCols\tData\n");
    for(int i = 0; i<spr[0].data+1 ; i++){
        printf("%d\t%d\t%d\n" , spr[i].row , spr[i].col , spr[i].data);
    }
}

void addSparse(coo spr1[], coo spr2[] , coo result[]){
    if(spr1[0].row != spr2[0].row || spr1[0].col != spr2[0].col){
        printf("Addition Not possible\n");
    }
    int i=1 , j=1 , k=1;
    result[0].row = spr1[0].row;
    result[1].col = spr1[0].col;
    while(i < spr1[0].data+1 && j<spr2[0].data+1){
        if (spr1[i].row == spr2[j].row && spr1[i].col == spr2[j].col){
            result[k].row = spr1[i].row;
            result[k].col = spr1[i].col;
            result[k].data = spr1[i].data+spr2[j].data;
            i++;
            j++;
            k++;
        }
        else if(spr1[i].row < spr2[j].row || (spr1[i].row == spr2[j].row && spr1[i].col <spr2[j].col)){
            result[k] = spr1[i];
            k++;
            i++;
        }else{
            result[k] = spr2[j];
            k++;
            j++;
        }
    }
    //copy remaining elements from spr1
    while(i < spr1[0].data+1){
        result[k] = spr1[i];
        i++;
        k++;
    }
    while(j < spr2[0].data+1){
        result[k] = spr2[j];
        j++;
        k++;
    }

    result[0].data = k-1;
}

int main(){
    coo spr1[] = {{3,3,3},
                  {0,2,5},
                  {1,1,3},
                  {2,1,7}};

    coo spr2[] = {{3,3,3},
                  {0,2,2},
                  {1,0,5},
                  {2,2,9}}; 

    coo res[3+3+1];
    addSparse(spr1 , spr2 , res);
    printSparse(res);      
    return 0;
}