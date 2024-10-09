#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct Node* insert_front(struct Node* head, int data) {
    struct Node* new_node = create_node(data);
    new_node->right = head;
    if (head != NULL) {
        head->left = new_node;
    }
    return new_node; // Return new head
}

struct Node* insert_end(struct Node* head, int data) {
    struct Node* new_node = create_node(data);
    if (head == NULL) {
        return new_node; // New head if list is empty
    }
    struct Node* ptr = head;
    while (ptr->right != NULL) {
        ptr = ptr->right;
    }
    ptr->right = new_node;
    new_node->left = ptr;
    return head; // Return unchanged head
}

struct Node* insert_after(struct Node* head, int data, int key) {
    struct Node* new_node = create_node(data);
    if (head == NULL) {
        printf("Size Error: List is empty\n");
        free(new_node);
        return head;
    }
    struct Node* ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->right;
    }
    if (ptr == NULL) {
        printf("Key Error: Cannot find the key\n");
        free(new_node);
        return head;
    }
    new_node->right = ptr->right;
    new_node->left = ptr;
    if (ptr->right != NULL) {
        ptr->right->left = new_node;
    }
    ptr->right = new_node;
    return head; // Return unchanged head
}

struct Node* delete_head(struct Node* head) {
    if (head == NULL) {
        printf("Deletion Error: List is empty\n");
        return head;
    }
    struct Node* ptr = head;
    head = head->right;
    if (head != NULL) {
        head->left = NULL;
    }
    printf("Deleted node with data: %d\n", ptr->data);
    free(ptr);
    return head;
}

struct Node* delete_end(struct Node* head) {
    if (head == NULL) {
        printf("Deletion Error: List is empty\n");
        return head;
    }
    if (head->right == NULL) {
        printf("Deleted node with data: %d\n", head->data);
        free(head);
        return NULL;
    }
    struct Node* ptr = head;
    while (ptr->right != NULL) {
        ptr = ptr->right;
    }
    printf("Deleted node with data: %d\n", ptr->data);
    ptr->left->right = NULL; // Disconnect the last node
    free(ptr);
    return head;
}

struct Node* delete_after(struct Node* head, int key) {
    if (head == NULL) {
        printf("Deletion Error: List is empty\n");
        return head;
    }
    struct Node* ptr = head;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->right;
    }
    if (ptr == NULL || ptr->right == NULL) {
        printf("Key Error: Cannot find the key or no node exists after the key\n");
        return head;
    }

    struct Node* temp = ptr->right;
    ptr->right = temp->right;
    if (temp->right != NULL) {
        temp->right->left = ptr;
    }
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);
    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("Size Error: List is empty\n");
        return;
    }
    struct Node* ptr = head;
    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->right;
    }
    printf("\n");
}

void reverse(struct Node** head) {
    if (*head == NULL) return;

    struct Node* current = *head;
    struct Node* temp = NULL;
    
    while (current != NULL) {
        temp = current->left;
        current->left = current->right;
        current->right = temp;
        current = current->left;
    }
    if (temp != NULL) {
        *head = temp->left;
    }
}

struct Node* free_list(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        struct Node* temp = ptr;
        ptr = ptr->right;
        free(temp);
    }
    return NULL;
}

int main() {
    struct Node* head = NULL;
    int ch;
    printf("Double Linked List Operations:\n");
    printf("1. Insert Front\n");
    printf("2. Insert End\n");
    printf("3. Insert After\n");
    printf("4. Delete Head\n");
    printf("5. Delete End\n");
    printf("6. Delete After\n");
    printf("7. Display\n");
    printf("8. Reverse\n");
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
            case 8:
                reverse(&head);
                printf("List reversed.\n");
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
