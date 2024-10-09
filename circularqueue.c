#include <stdio.h>

#define SIZE 5  

int queue[SIZE];
int front = -1;
int rear = -1;



int isFull() {
    return (front == (rear + 1) % SIZE);
}


int isEmpty() {
    return (front == -1);
}


void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        if (front == -1)  // First element being added
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}


int dequeue() {
    int value;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    } else {
        value = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("Deleted %d\n", value);
        return value;
    }
}

// Display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", queue[i]); 
    }
}

int main() {
    int x;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.isEmpty\n5.isFull\n0.Exit\n");

    int flag = 1;
    while(flag == 1){
        printf("Use the keys:");
        scanf("%d" , &x);

        if (x == 1){
            int ele;
            printf("Enter the element:");
            scanf("%d" , &ele);
            enqueue(ele);
        }
        else if(x == 2){
            printf("Element dequed: %d\n" , dequeue());
        }
        else if(x == 3){
            display();
        }
        else if(x == 4){
            if(!isEmpty()){
                printf("Not Empty\n");
            }else{
                printf("Empty\n");
            }
        }
        else if(x==5){
            if(isFull()){
                printf("Full\n");
            }else{
                printf("Not Full\n");
            }
        }
        else if(x == 0){
            flag = 0;
        }
        else{
            printf("Invalid choice");
        }
    }

    return 0;
}
