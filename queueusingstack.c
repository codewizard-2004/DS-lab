#include<stdio.h>

#define SIZE 5

int stack1[SIZE];
int stack2[SIZE];
int top1 = -1;
int top2 = -1;

int isFull(int top){
    return top == SIZE;
}

int isEmpty(int top){
    return top == -1;
}

void push(int stack[] , int *top , int data){
    if (isFull(*top)){
        printf("Stack FUll");
    }else{
        (*top)++;
        stack[*top] = data;
    }
}

int pop(int stack[] , int *top){
    if (isEmpty(*top)){
        printf("Stack Empty");
        return 0;
    }else{
        int ele = stack[*top];
        (*top)--;
        return ele;
    }
}

void enqueue(int data){
    // We enqueue into the stack 1
    push(stack1 , &top1 , data);
}

int dequeue(){
    //If stack2 is empty then flush all of stack 1 to stack 2
    if (isEmpty(top2)){
        while(!isEmpty(top1)){
            int popped = pop(stack1 , &top1);
            push(stack2 , &top2 , popped);
        }
    }

    if(isEmpty(top2)){
        printf("\nQueue Empty\n");
        return -1;
    }else{
        int popped2 = pop(stack2 , &top2);
        return popped2;
    }
}

int peek(){
    if(isEmpty(top1)){
        printf("Stack Empty");
        return -1;
    }else{
        return stack1[top1];
    }
}

int main() {
    int choice, value;

    printf("1. Enqueue\n2. Dequeue\n3. Peek\n0. Exit\n");

    int flag =1;
    while (flag == 1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("\nElement Dequeued: %d\n", value);
                }
                break;
            case 3:
                printf("\nFront:%d\n" , peek());
                break;
            case 0:
                flag = 0;
            default:
                printf("\nInvalid Choice\n");
        }
    }

    return 0;
}