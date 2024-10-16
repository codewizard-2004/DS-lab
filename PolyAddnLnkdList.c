// Cprogram to implement an array using linkedlist

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int exp;
    struct Node* link;
};

struct Node* create_node(int coeff , int exp){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->coeff = coeff;
    new->exp = exp;
    return new;
}

struct Node* add_poly(struct Node* poly1 , struct Node* poly2 , struct Node* result){
    struct Node* ptr1 = poly1;
    struct Node* ptr2 = poly2;
    struct Node* rtr = result;
    while(ptr1->link != NULL && ptr2->link != NULL){
        // if power of poly 1 is equal to poly 2
        if(ptr1->exp == ptr2->exp){
            if(rtr->coeff == NULL || rtr->exp ==NULL){
                rtr->coeff = ptr1->coeff + ptr2->coeff;
                rtr->exp = ptr1->exp;
                ptr1 = ptr1->link;
                ptr2 = ptr2->link;
            }else{
                struct Node* new = create_node(ptr1->coeff+ptr2->coeff , ptr1->exp);
                rtr->link = new;
                rtr = rtr->link;
                ptr1 = ptr1->link;
                ptr2 = ptr2->link;
            }
        }
        else if (ptr1->exp > ptr2->exp){
            // put the ptr1;
            if(rtr->coeff == NULL || rtr->exp ==NULL){
                rtr->coeff = ptr1->coeff;
                rtr->exp = ptr1->exp;
                ptr1 = ptr1->link;
            }else{
                struct Node* new = create_node(ptr1->coeff , ptr1->exp);
                rtr->link = new;
                ptr1 = ptr1->link;
            }
        }else{
            if(rtr->coeff == NULL || rtr->exp ==NULL){
                rtr->coeff = ptr2->coeff;
                rtr->exp = ptr2->exp;
                ptr2 = ptr2->link;
            }else{
                struct Node* new = create_node(ptr2->coeff, ptr2->exp);
                rtr->link = new;
                ptr2 = ptr2->link;
            }
        }
    }
    //input the remaining nodes
    while(ptr1->link != NULL){
        struct Node* new = create_node(ptr1->coeff , ptr1->exp);
        rtr->link = new;
    }

    while(ptr2->link != NULL){
        struct Node* new = create_node(ptr2->coeff , ptr2->exp);
        rtr->link = new;
    }

    return result;

}


int main(){
    int size1 , size2;
    printf("Enter terms for Polynomial 1:");
    scanf("%d" , &size1);
    
    struct Node* poly1 = create_node(NULL , NULL);
    struct Node* ptr = poly1;
    for(int i = 0 ; i< size1 ; i++){
        int coeff , exp;
        printf("Enter coeffiecient:");
        scanf("%d" , &coeff);
        printf("Enter Power:");
        scanf("%d" , &exp);
        if(i == 0){
            ptr->coeff = coeff;
            ptr->exp = exp;
        }else{
            struct Node* new = create_node(coeff , exp);
            ptr->link = new;
        }
    }

    printf("Enter terms for Polynomial 2:");
    scanf("%d" , &size2);
    
    struct Node* poly2 = create_node(NULL , NULL);
    struct Node* ptr2 = poly1;
    for(int i = 0 ; i< size2 ; i++){
        int coeff , exp;
        printf("Enter coeffiecient:");
        scanf("%d" , &coeff);
        printf("Enter Power:");
        scanf("%d" , &exp);
        if(i == 0){
            ptr2->coeff = coeff;
            ptr2->exp = exp;
        }else{
            struct Node* new = create_node(coeff , exp);
            ptr2->link = new;
        }
    }

    struct Node* result = create_node(NULL , NULL);
    result = add_poly(poly1 , poly2 , result);


    return 0;
}