// TO implement stack using singly linked lsit
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;
int size = 0;

struct Node* createNode(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->link = NULL;
    new->data = data;

    return new;
}

void push(int data){
    
    if (size == MAX){
        printf("\nStack Overflow\n");
        return;
    }
    struct Node* new = createNode(data);
    new->link = top;
    top = new;
    size++;
    
}

int pop(){
    if(size == 0){
        printf("\nStack Empty\n");
        return 0;
    }else{
        struct Node* ptr = top;
        if(ptr->link == NULL){
            top = NULL;
            int dat = ptr->data;
            free(ptr);
            size--;
            return dat;
            
        }else{
            top = top->link;
            int dat = ptr->data;        ptr = ptr->link;

            free(ptr);
            size--;
            return dat;
        }
    }
    
}

void display(){
    struct Node* ptr = top;
    if (size == 0){
        printf("\nStack Underflow\n");
    }
    else{
        
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

void freeStack(){
    struct Node* ptr = top;
    while(ptr != NULL){
        struct Node* temp = ptr;
        ptr = ptr->link;
        free(temp);
    }
    top = NULL;
    size = 0;
}

int main(){

    printf("1. Push\n2. Pop\n3. Display\n0. Delete and Exit\n");

    int ch;
    while(1){
        printf("\nEnter the choice:");
        scanf("%d" , &ch);
        switch (ch)
        {
        case 1:
            int ele;
            printf("Enter the element:");
            scanf("%d" , &ele);
            push(ele);
            break;
        case 2:
            int popped = pop();
            printf("\nElement Popped:%d\n",popped);
            break;
        case 3:
            display();
            break;
        case 0:
            freeStack();
            exit(1);
        
        default:
            printf("\nInvalid choice\n");
            break;
        }
    }


    return 0;
}