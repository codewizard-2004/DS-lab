#include <stdio.h>

#define SIZE 5  


int deque[SIZE];
int front = -1;
int rear = -1;



// Check if the deque is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Insert an element at the front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full\n");
    } else {
        if (front == -1) { 
            front = 0;
            rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE; 
        }
        deque[front] = value;
        printf("Inserted %d at front\n", value);
    }
}

// Insert an element at the rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE; 
        }
        deque[rear] = value;
        printf("Inserted %d at rear\n", value);
    }
}

// Remove an element from the front
int deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    } else {
        int value = deque[front];
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % SIZE; 
        }
        printf("Deleted %d from front\n", value);
        return value;
    }
}

// Remove an element from the rear
int deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    } else {
        int value = deque[rear];
        if (front == rear) { 
            front = rear = -1; 
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }
        printf("Deleted %d from rear\n", value);
        return value;
    }
}


void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
    } else {
        int i = front;
        printf("Deque elements: ");
        while (i != rear) {
            printf("%d ", deque[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", deque[i]); 
    }
}



int main() {
    int choice, value;
    printf("\nMenu:\n");
    printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. isEmpty\n7. isFull\n0. Exit");

    while (1) {
        printf("Use the keys: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                if (isEmpty())
                    printf("Deque is empty\n");
                else
                    printf("Deque is not empty\n");
                break;
            case 7:
                if (isFull())
                    printf("Deque is full\n");
                else
                    printf("Deque is not full\n");
                break;
            case 0:
                printf("Exiting...\n");
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
