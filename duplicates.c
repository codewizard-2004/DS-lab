#include<stdio.h>

// To find Duplicate elements in an array

void getDuplicates2(int arr[] , int n){
    //only printing
    for (int i = 0; i< n-1 ; i++){
        for(int j = i+1; j<n ; j++){
            if (arr[i] == arr[j]){
                printf("Duplicate element:%d\n" , arr[i]);
            }
        }
    }
}

void sortArray(int arr[] , int n){
    for (int i = 0 ; i<n-1 ; i++){
        for(int j = 0 ; j< n-i-1 ; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

void getDuplicates3(int arr[] , int n){
    //Sorting algorithm
    sortArray(arr , n);
    for(int i = 0 ; i<n-1 ; i++){
        if(arr[i] == arr[i+1]){
            printf("Dupliate element: %d\n" , arr[i]);
        }
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

    getDuplicates3(arr , n);

    return 0;
}