#include <stdio.h>
#include <string.h>
#define MAX 50

char stk[MAX]; // stack for conversion
int stk1[MAX]; // for postfix evaluation
int top = -1, top1 = -1, j = 0; // for postfix expression
char post[MAX];

// Function to push an operator to the stack
void push(char ch) {
    stk[++top] = ch;
}

// Function to push an operand to the evaluation stack
void push1(int ch) {
    stk1[++top1] = ch;
}

// Function to pop and return the top operand from the evaluation stack
int pop1() {
    return stk1[top1--];
}

// Function to check the precedence of operators
int priority(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return 0;
}


int associativity(char c) {
    if (c == '^')
        return 1; 
    else
        return 0; 
}



int main() {
    char a[MAX], ch;
    
    printf("PROGRAM FOR INFIX TO POSTFIX CONVERSION \n\n");
    printf("Enter infix expression: ");
    gets(a); 
    
   
    for (int i = 0; a[i] != '\0'; i++) {
        ch = a[i];
        
        switch (ch) {
            case '(':
                push(ch);
                break;
            case ')':
                while (stk[top] != '(') {
                    post[j++] = stk[top--];
                }
                top--; 
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (top != -1 && stk[top] != '(' &&
                       ((associativity(ch) == 0 && priority(ch) <= priority(stk[top])) ||
                        (associativity(ch) == 1 && priority(ch) < priority(stk[top])))) {
                    post[j++] = stk[top--];
                }
                push(ch);
                break;
            default:
       
                if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                    post[j++] = ch;
                }
                break;
        }
    }


    while (top != -1) {
        post[j++] = stk[top--];
    }
    post[j] = '\0'; 


    printf("The postfix expression is: ");
    puts(post);

    
    return 0;
}
