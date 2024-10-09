#include <stdio.h>
#include <stdlib.h>

// Function to add two polynomials
void addPolynomials(int poly1[], int degree1, int poly2[], int degree2, int polySum[]) {
    int maxDegree = (degree1 > degree2) ? degree1 : degree2;
    for (int i = 0; i <= maxDegree; i++) {
        int coef1 = (i <= degree1) ? poly1[i] : 0;
        int coef2 = (i <= degree2) ? poly2[i] : 0;
        polySum[i] = coef1 + coef2;
    }
}

void printPolynomial(int poly[], int degree) {
    int started = 0; 
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (started) {
                if (poly[i] > 0)
                    printf(" + ");
                else {
                    printf(" - ");
                    poly[i] = -poly[i]; 
                }
            } else {
                if (poly[i] < 0) {
                    printf("-");
                    poly[i] = -poly[i]; 
                }
                started = 1;
            }

            if (i == 0 || poly[i] != 1)
                printf("%dx^%d", poly[i], i);
            else
                printf("x^%d", i);
        }
    }
    if (!started)
        printf("0");
    printf("\n");
}

int main() {
    int degree1, degree2;

    // Input for first polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    int poly1[degree1 + 1];
    printf("Enter the coefficients of the first polynomial (from x^0 to x^%d):\n", degree1);
    for (int i = 0; i <= degree1; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    // Input for second polynomial
    printf("\nEnter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    int poly2[degree2 + 1];
    printf("Enter the coefficients of the second polynomial (from x^0 to x^%d):\n", degree2);
    for (int i = 0; i <= degree2; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    int maxDegree = (degree1 > degree2) ? degree1 : degree2;
    int polySum[maxDegree + 1];

    for (int i = 0; i <= maxDegree; i++) {
        polySum[i] = 0;
    }

    // Add the polynomials
    addPolynomials(poly1, degree1, poly2, degree2, polySum);

    
    printf("Result: ");
    printPolynomial(polySum, maxDegree);

    return 0;
}
