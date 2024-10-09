#include <stdio.h>
#include <stdlib.h>
#include<math.h>

// Structure to represent a term in a multivariable polynomial
typedef struct {
    int coeff; // Coefficient
    int x;     // Power of x
    int y;     // Power of y
} Term;


// Function to print the polynomial in a readable format
void printPolynomial(Term poly[], int size) {
    if (size == 0) {
        printf("0\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        if (poly[i].coeff == 0)
            continue;

        // Handle sign
        if (poly[i].coeff > 0 && i != 0)
            printf(" + ");
        else if (poly[i].coeff < 0)
            printf(" - ");

        // Handle coefficient (absolute value if negative)
        int absCoeff = poly[i].coeff > 0 ? poly[i].coeff : -poly[i].coeff;
        if (!(absCoeff == 1 && (poly[i].x != 0 || poly[i].y != 0)))
            printf("%d", absCoeff);
        else if (absCoeff == 1 && poly[i].x == 0 && poly[i].y == 0)
            printf("1");

        // Handle x and y
        if (poly[i].x != 0) {
            printf("x");
            if (poly[i].x != 1)
                printf("^%d", poly[i].x);
        }
        if (poly[i].y != 0) {
            printf("y");
            if (poly[i].y != 1)
                printf("^%d", poly[i].y);
        }
    }
    printf("\n");
}

int evaluate(Term poly[] , int size , int valx , int valy){
    int sum = 0;
    for(int i = 0 ; i<size ; i++){
        sum += poly[i].coeff*pow(valx , poly[i].x)*pow(valy , poly[i].y);
    }
    return sum;
}

int main() {
    int size, x , y;

    printf("Enter number of terms in polynomial: ");
    scanf("%d" , &size);
    
    Term poly[size];
    
    for (int i = 0; i < size; i++) {
        printf("Term %d:\n", i+1);
        printf("Coefficent:");
        scanf("%d" , &poly[i].coeff);
        printf("Power of X:");
        scanf("%d" , &poly[i].x);
        printf("Power of Y:");
        scanf("%d" , &poly[i].y);
    }

    
    printf("Enter the value of x:");
    scanf("%d" , &x);
    printf("Enter the value of y:");
    scanf("%d" , &y);


    // Print the result
    printf("\nResultant Polynomial: ");
    printPolynomial(poly, size);
    printf("\n");
    printf("Result:%d" , evaluate(poly ,size, x , y));

    return 0;
}
