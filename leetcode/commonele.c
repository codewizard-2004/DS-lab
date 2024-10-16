// C program to find common elements from two arrays
#include<stdio.h>

int binarySearch(int arr[] , int size , int target){
    int left = 0;
    int right = size-1;
    while(left<=right){
        int mid = (left+right)/2;
        if (arr[mid] == target){
            return mid;
        }else if(target > arr[mid]){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
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

void commonElements(int arr1[] , int size1 , int arr2[] , int size2){
    sortArray(arr2 , size2);
    for (int i = 0 ; i< size1 ; i++){
        int idx = binarySearch(arr2 , size2 , arr1[i]);
        //printf("iter: %d , idx:%d" , i , idx);
        if(idx != -1){
            printf("%d " , arr1[i]);
        }
    }
}

int main(){

    int arr1[] = {1,2,3,4,5};
    int arr2[] = {4,5,6,7,8,1};
    commonElements(arr1 , 5 , arr2 , 6);


    return 0;
}