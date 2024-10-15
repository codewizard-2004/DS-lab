/*Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.*/


// Input the array from the user
// create an output loop of length 2
// create a nested for loop and get first element 
// add it with other elements till target is reached

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int arr[] , int target , int size){
    int* arr2 = (int*)malloc(2*sizeof(int));

    for(int i = 0 ; i<size-1 ; i++){
        for(int j = i+1 ;j < size ; j++){
            if((arr[i]+arr[j])== target){
                arr2[0] = i;
                arr2[1] = j;
                return arr2;
            }
        }
    }
    free(arr2);
    return NULL;

}

int main(){

    int marr[] = {3,3};
    int* result = twoSum(marr , 6 , sizeof(marr)/sizeof(marr[0]));
    if (*result == -1){
        printf("Does Not Exist");
    }else{
        printf("%d & %d" , *result , *(result+1));
    } 
    
}
