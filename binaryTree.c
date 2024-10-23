#include<stdio.h>
#include<stdlib.h>

//Define the structure for a binary tree node
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

//function to create a new nde
struct Node* createNode(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->left = NULL;
    new->right = NULL;
    new->data = data;

    return new;
}

//Function to insert a new node in binary tree
struct Node* insert(struct Node* root , int data){
    if(root == NULL){
        return createNode(data);
    }
    if (data < root->data){
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;

}

// Function for in-order traversal (left, root, right)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {/* constant-expression */
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function for pre-order traversal (root, left, right)
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}



// Function for post-order traversal (left, right, root)
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    struct Node* root = NULL;
    printf("\n1. Add Node\n2. Preorderer Traversal\n3. InOrder Traversal\n4. PostOrder Traversal\n0. Exit & Delete tree\n");

    int ch;
    while(1){
        printf("\nEnter the choice:");
        scanf("%d" , &ch);
        switch (ch)
        {
        case 1:
            int ele;
            printf("Enter the data:");
            scanf("%d" , &ele);
            root = insert(root , ele);
            break;
        case 2:
            preOrderTraversal(root);
            break;
        case 3:
            inOrderTraversal(root);
            break;
        case 4:
            postOrderTraversal(root);
            break;
        case 0:
            freeTree(root);
            exit(1);
        
        default:
            printf("\nInvalid choice\n");
            break;
        }
    }


    return 0;

}


