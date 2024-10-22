#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    char items[MAX][MAX];
} stack;

// Initialize stack
void initStack() {
    stack.top = -1;
}

// Push function
void push(char* value) {
    if (stack.top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    strcpy(stack.items[++stack.top], value);
}

// Pop function
char* pop() {
    if (stack.top == -1) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack.items[stack.top--];
}

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to reverse a string
void reverseString(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    initStack();
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If character is an operand, add it to the output
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If character is '(', push it to stack
        else if (ch == '(') {
            char temp[2] = {ch, '\0'};
            push(temp);
        }
        // If character is ')', pop and output from stack until '(' is found
        else if (ch == ')') {
            while (stack.top != -1 && stack.items[stack.top][0] != '(') {
                postfix[k++] = pop()[0];
            }
            pop(); // Pop '('
        }
        // Operator is encountered
        else if (isOperator(ch)) {
            while (stack.top != -1 && precedence(stack.items[stack.top][0]) >= precedence(ch)) {
                postfix[k++] = pop()[0];
            }
            char temp[2] = {ch, '\0'};
            push(temp);
        }
    }

    // Pop all remaining operators from stack
    while (stack.top != -1) {
        postfix[k++] = pop()[0];
    }
    postfix[k] = '\0';
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    reverseString(infix);  // Reverse the infix expression
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    char postfix[MAX];
    infixToPostfix(infix, postfix);
    reverseString(postfix); // Reverse the postfix result to get prefix
    strcpy(prefix, postfix);
}

// Function to convert postfix to infix
void postfixToInfix(char* postfix, char* infix) {
    initStack();
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            char temp[2] = {ch, '\0'};
            push(temp);
        } else if (isOperator(ch)) {
            char op1[MAX], op2[MAX], expr[MAX];

            strcpy(op2, pop());
            strcpy(op1, pop());

            sprintf(expr, "(%s%c%s)", op1, ch, op2);
            push(expr);
        }
    }

    strcpy(infix, pop());
}

// Function to convert postfix to prefix
void postfixToPrefix(char* postfix, char* prefix) {
    initStack();
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            char temp[2] = {ch, '\0'};
            push(temp);
        } else if (isOperator(ch)) {
            char op1[MAX], op2[MAX], expr[MAX];

            strcpy(op2, pop());
            strcpy(op1, pop());

            sprintf(expr, "%c%s%s", ch, op1, op2);
            push(expr);
        }
    }

    strcpy(prefix, pop());
}

// Function to convert prefix to infix
void prefixToInfix(char* prefix, char* infix) {
    reverseString(prefix); // Reverse the prefix expression
    initStack();

    for (int i = 0; prefix[i] != '\0'; i++) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            char temp[2] = {ch, '\0'};
            push(temp);
        } else if (isOperator(ch)) {
            char op1[MAX], op2[MAX], expr[MAX];

            strcpy(op1, pop());
            strcpy(op2, pop());

            sprintf(expr, "(%s%c%s)", op1, ch, op2);
            push(expr);
        }
    }

    strcpy(infix, pop());
}

// Function to convert prefix to postfix
void prefixToPostfix(char* prefix, char* postfix) {
    reverseString(prefix); // Reverse the prefix expression
    initStack();

    for (int i = 0; prefix[i] != '\0'; i++) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            char temp[2] = {ch, '\0'};
            push(temp);
        } else if (isOperator(ch)) {
            char op1[MAX], op2[MAX], expr[MAX];

            strcpy(op1, pop());
            strcpy(op2, pop());

            sprintf(expr, "%s%s%c", op1, op2, ch);
            push(expr);
        }
    }

    strcpy(postfix, pop());
}

int main() {
    char infix[MAX], prefix[MAX], postfix[MAX];

    // Example inputs
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Infix to Postfix
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    // Infix to Prefix
    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);

    // Postfix to Infix
    char infixFromPostfix[MAX];
    postfixToInfix(postfix, infixFromPostfix);
    printf("Postfix to Infix: %s\n", infixFromPostfix);

    // Postfix to Prefix
    char prefixFromPostfix[MAX];
    postfixToPrefix(postfix, prefixFromPostfix);
    printf("Postfix to Prefix: %s\n", prefixFromPostfix);

    // Prefix to Infix
    char infixFromPrefix[MAX];
    prefixToInfix(prefix, infixFromPrefix);
    printf("Prefix to Infix: %s\n", infixFromPrefix);

    // Prefix to Postfix
    char postfixFromPrefix[MAX];
    prefixToPostfix(prefix, postfixFromPrefix);
    printf("Prefix to Postfix: %s\n", postfixFromPrefix);

    return 0;
}
