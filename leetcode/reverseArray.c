// C program to reverse an array

#include<stdio.h>

void reverseArray(int arr[] , int size){
    for(int i = size-1; i>size/2 ; i--){
        printf("idx1:%d and idx2:%d\n" ,i , size-i-1 );
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}


int main(){
    int n;
    printf("Enter the size of the array:");
    scanf("%d" , &n);
    int arr[n];

    for(int i = 0 ; i< n; i++){
        printf("Enter the element ar index %d:" , i);
        scanf("%d" , &arr[i]);
    }

    reverseArray(arr , n);
    printf("\nAfter Reversing\n");

    for(int i = 0 ; i< n; i++){
        printf("%d " , arr[i]);
    }

    return 0;
}