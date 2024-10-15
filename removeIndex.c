//C program to remove an element at a list at a given index
#include<stdio.h>

void removeElement(int arr[] , int *size , int index){
    /*
        This function will remove an element at the specified index
        Args:
            arr[]: the input array in which operation need to be done
            *size: the pointer of the size of the array(used pointer to reduce size of array)
            index: the index of element to be removed
    */

   for (int i = index ; i < (*size)-1 ; i++){
        arr[i] = arr[i+1];
   }
   (*size)--;
}


int main(){
    int arr[] = {5,3,7,5,6,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    removeElement(arr , &size , 2);

    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}