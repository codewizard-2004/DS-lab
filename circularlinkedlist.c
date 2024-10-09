#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL; 
    return new_node;
}

// Function to insert at the front
struct Node* insert_front(struct Node* head, int data) {
    struct Node* new_node = create_node(data);
    if (head == NULL) {
        new_node->next = new_node; // Point to itself
        return new_node;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next; // Find the last node
    }
    temp->next = new_node; // Link the last node to the new node
    new_node->next = head; // New node points to head
    return new_node; 
}

// Function to insert at the end
struct Node* insert_end(struct Node* head, int data) {
    struct Node* new_node = create_node(data);
    if (head == NULL) {
        new_node->next = new_node; // Point to itself
        return new_node;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next; // Find the last node
    }
    temp->next = new_node; // Link the last node to the new node
    new_node->next = head; // New node points to head
    return head; // Head remains the same
}

// Function to insert after a key
struct Node* insert_after(struct Node* head, int data, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node* new_node = create_node(data);
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            new_node->next = temp->next; // Link new node to the next node
            temp->next = new_node; // Link the key node to the new node
            return head;
        }
        temp = temp->next;
    } while (temp != head);
    
    printf("Key %d not found.\n", key);
    free(new_node); // Free allocated memory for the new node
    return head;
}

// Function to delete the head node
struct Node* delete_head(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (head->next == head) { // Only one node
        free(head);
        return NULL; // List becomes empty
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next; // Find the last node
    }
    temp->next = head->next; // Last node points to the second node
    free(head); 
    return temp->next; 
}

// Function to delete a node after a key
struct Node* delete_after(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* to_delete = temp->next;
            if (to_delete == head) { // No node to delete
                printf("No node exists after key %d.\n", key);
                return head;
            }
            temp->next = to_delete->next; // Link to the next node
            free(to_delete); // Free the node
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Key %d not found.\n", key);
    return head;
}

// Function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to free the entire list
struct Node* free_list(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* current = head;
    struct Node* next_node;
    do {
        next_node = current->next; 
        free(current); 
        current = next_node; 
    } while (current != head);
    return NULL; 
}

// Main function to demonstrate circular linked list operations
int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert Front\n");
        printf("2. Insert End\n");
        printf("3. Insert After\n");
        printf("4. Delete Head\n");// Free current node
        printf("5. Delete After\n");
        printf("6. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                head = insert_front(head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insert_end(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                head = insert_after(head, data, key);
                break;
            case 4:
                head = delete_head(head);
                break;
            case 5:
                printf("Enter key after which to delete: ");
                scanf("%d", &key);
                head = delete_after(head, key);
                break;
            case 6:
                display(head);
                break;
            case 0:
                head = free_list(head);
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
