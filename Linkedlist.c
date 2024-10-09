#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* link;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

// Function to insert at the front
struct Node* insert_front(struct Node* head, int data) {
    struct Node* new_node = create_node(data);
    new_node->link = head;
    head = new_node;
    return head;
}

// Function to insert at the end
struct Node* insert_end(struct Node* head, int data) {
    struct Node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    struct Node* ptr = head;

    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new_node;
    return head;
}

// Function to insert after a given key
struct Node* insert_after(struct Node* head, int data, int key) {
    struct Node* new_node = create_node(data);
    if (head == NULL) {
        printf("Size Error: List is empty\n");
        free(new_node); 
        return head;
    }
    struct Node* ptr = head;

    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("Key Error: Cannot find the key\n");
        free(new_node);
        return head;
    } else {
        new_node->link = ptr->link;
        ptr->link = new_node;
    }
    return head;
}

// Function to delete the head node
struct Node* delete_head(struct Node* head) {
    if (head == NULL) {
        printf("Deletion Error: List is empty\n");
        return head;
    } else {
        struct Node* ptr = head;
        head = head->link;
        printf("Deleted node with data: %d\n", ptr->data);
        free(ptr);
        return head;
    }
}

// Function to delete the end node
struct Node* delete_end(struct Node* head) {
    if (head == NULL) {
        printf("Deletion Error: List is empty\n");
        return head;
    }
    if (head->link == NULL) {
        printf("Deleted node with data: %d\n", head->data);
        free(head);
        return NULL;
    }
    struct Node* ptr = head;
    struct Node* prev = NULL;

    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }
    printf("Deleted node with data: %d\n", ptr->data);
    free(ptr);
    prev->link = NULL;
    return head;
}

// Function to delete a node after a given key
struct Node* delete_after(struct Node* head, int key) {
    if (head == NULL) {
        printf("Deletion Error: List is empty\n");
        return head;
    }
    struct Node* ptr = head;

    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("Key Error: Cannot find the key\n");
        return head;
    }
    if (ptr->link == NULL) {
        printf("Deletion Error: No node exists after the given key\n");
        return head;
    }

    struct Node* temp = ptr->link;
    ptr->link = temp->link;
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);
    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Size Error: List is empty\n");
        return;
    }
    struct Node* ptr = head;
    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

// Function to free the entire list before exiting
struct Node* free_list(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        struct Node* temp = ptr;
        ptr = ptr->link;
        free(temp);
    }
    return NULL;
}

int main(){
    struct Node* head = NULL;
    int ch;
    printf("Singly Linked List Operations:\n");
    printf("1. Insert Front\n");
    printf("2. Insert End\n");
    printf("3. Insert After\n");
    printf("4. Delete Head\n");
    printf("5. Delete End\n");
    printf("6. Delete After\n");
    printf("7. Display\n");
    printf("0. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        if (scanf("%d", &ch) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (ch) {
            case 1: {
                int ele;
                printf("Enter the data to insert at front: ");
                if (scanf("%d", &ele) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                head = insert_front(head, ele);
                printf("Inserted %d at the front.\n", ele);
                break;
            }
            case 2: {
                int ele;
                printf("Enter the data to insert at end: ");
                if (scanf("%d", &ele) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                head = insert_end(head, ele);
                printf("Inserted %d at the end.\n", ele);
                break;
            }
            case 3: {
                int ele, key;
                printf("Enter the data to insert: ");
                if (scanf("%d", &ele) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                printf("Enter the key after which to insert: ");
                if (scanf("%d", &key) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                head = insert_after(head, ele, key);
                break;
            }
            case 4:
                head = delete_head(head);
                break;
            case 5:
                head = delete_end(head);
                break;
            case 6: {
                int key;
                printf("Enter the key after which to delete: ");
                if (scanf("%d", &key) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                head = delete_after(head, key);
                break;
            }
            case 7:
                display(head);
                break;
            case 0:
                head = free_list(head);
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Choice Error: Invalid option. Please try again.\n");
        }
    }

    head = free_list(head);
    return 0;
}
