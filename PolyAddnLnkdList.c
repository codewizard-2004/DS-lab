#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* link;
};

// Function to create a new node
struct Node* create_node(int coeff, int exp) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->link = NULL;  
    return new_node;
}

// Function to add two polynomials
struct Node* add_poly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;  // Result linked list
    struct Node* rtr = NULL;  // Pointer to track the last node in the result

    while (poly1 != NULL || poly2 != NULL) {
        struct Node* new_node = NULL;

        int coeff = 0;
        int exp = 0;

        // Determine which polynomial to take the term from
        if (poly1 != NULL && (poly2 == NULL || poly1->exp > poly2->exp)) {
            coeff = poly1->coeff;
            exp = poly1->exp;
            poly1 = poly1->link;
        } else if (poly2 != NULL && (poly1 == NULL || poly2->exp > poly1->exp)) {
            coeff = poly2->coeff;
            exp = poly2->exp;
            poly2 = poly2->link;
        } else {
            // Exponents are the same, combine coefficients
            coeff = poly1->coeff + poly2->coeff;
            exp = poly1->exp;
            poly1 = poly1->link;
            poly2 = poly2->link;
        }

        // Create a new node with the coefficient and exponent
        new_node = create_node(coeff, exp);

        // Append to the result linked list
        if (result == NULL) {
            result = new_node;
            rtr = result;
        } else {
            rtr->link = new_node;
            rtr = rtr->link;
        }
    }

    return result;
}


// Function to print a polynomial
void print_poly(struct Node* poly) {
    struct Node* current = poly;
    while (current) {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->link) {
            printf(" + ");
        }
        current = current->link;
    }
    printf("\n");
}

int main() {
    int size1, size2;

    // Input for Polynomial 1
    printf("Enter number of terms for Polynomial 1: ");
    scanf("%d", &size1);
    struct Node* poly1 = NULL;
    struct Node* tail1 = NULL;

    for (int i = 0; i < size1; i++) {
        int coeff, exp;
        printf("Enter coefficient: ");
        scanf("%d", &coeff);
        printf("Enter exponent: ");
        scanf("%d", &exp);
        struct Node* new_node = create_node(coeff, exp);
        if (poly1 == NULL) {
            poly1 = new_node;
            tail1 = new_node;
        } else {
            tail1->link = new_node;
            tail1 = new_node;
        }
    }

    // Input for Polynomial 2
    printf("Enter number of terms for Polynomial 2: ");
    scanf("%d", &size2);
    struct Node* poly2 = NULL;
    struct Node* tail2 = NULL;

    for (int i = 0; i < size2; i++) {
        int coeff, exp;
        printf("Enter coefficient: ");
        scanf("%d", &coeff);
        printf("Enter exponent: ");
        scanf("%d", &exp);
        struct Node* new_node = create_node(coeff, exp);
        if (poly2 == NULL) {
            poly2 = new_node;
            tail2 = new_node;
        } else {
            tail2->link = new_node;
            tail2 = new_node;
        }
    }

    // Add the polynomials
    struct Node* result = add_poly(poly1, poly2);

    // Display the result
    printf("Result Polynomial: ");
    print_poly(result);

    return 0;
}
