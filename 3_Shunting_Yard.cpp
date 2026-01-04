#include <stdio.h>
#include <ctype.h>
#include <string.h>

int oncelik(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* infix) {
    char stack[100], postfix[100];
    int top = -1, j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } 
        else if (c == '(') {
            stack[++top] = c;
        } 
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            top--; 
        } 
        else {
            while (top != -1 && oncelik(stack[top]) >= oncelik(c))
                postfix[j++] = stack[top--];
            stack[++top] = c;
        }
    }

    while (top != -1)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main() {
    char ifade[100];
    printf("Infix ifadeyi girin: ");
    scanf("%s", ifade);
    infixToPostfix(ifade);
    return 0;
}
