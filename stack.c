#include<stdio.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

int isFull(){
    return top == SIZE;
}

int isEmpty(){
    return top == -1;
}

void push(int data){
    if (isFull()){
        printf("\nStack Overflow\n");
    }else{
        top++;
        stack[top] = data;
        printf("\nElement Pushed: %d\n" , data);
    }
}

int pop(){
    if (isEmpty()){
        printf("\nStack Empty");
        return 0;
        printf("\n");
    }else{
        int ele = stack[top];
        top--;
        return ele;
    }
}

int peek(){
    if (isEmpty()){
        printf("\nStack Empty\n");
    }else{
        return stack[top];
    }
}

int main(){
    int ch , ele;
    printf("1. Push\n2. Pop\n3. Peek\n4. isFull\n 5.isEmpty \n0. Exit\n");

    int flag = 1;
    while(flag == 1){
        printf("Use the keys: ");
        scanf("%d" , &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element:");
            scanf("%d" , &ele);
            push(ele);
            break;
        
        case 2:
            printf("\nElement Popped:%d\n" , pop());
            break;
        case 3:
            printf("\nTop:%d\n", peek());
            break;
        case 4:
            printf(isFull()?"\nStack Overflow\n":"\nNot Full\n");
            break;
        case 5:
            printf(isEmpty()?"\nStack Empty\n":"\nStack Not empty\n");
            break;
        case 0:
            flag = 0;
            break;
        
        default:
            printf("\nInvalid Key\n");
            break;
        }
        
    }

    return 0;
}