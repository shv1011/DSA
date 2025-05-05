#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if(s->top < MAX_SIZE - 1) {
        s->arr[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if(s->top >= 0) {
        return s->arr[(s->top)--];
    }
    return 0; 
}

int evaluatePostfix(char *exp[], int n) {
    Stack s;
    initStack(&s);

    for(int i = 0; i < n; i++){
        char *token = exp[i];

        if(isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&s, atoi(token));
        } else {
            int val1 = pop(&s);
            int val2 = pop(&s);

            if(strcmp(token, "+") == 0)
                push(&s, val2 + val1);
            else if(strcmp(token, "-") == 0)
                push(&s, val2 - val1);
            else if(strcmp(token, "*") == 0)
                push(&s, val2 * val1);
            else if(strcmp(token, "/") == 0)
                push(&s, val2 / val1);
            else if(strcmp(token, "^") == 0)
                push(&s, (int)pow(val2, val1));
        }
    }

    return pop(&s);
}

int main() {
    char *arr[] = { "10", "20", "+", "30", "*" };  // (10 + 20) * 30 = 900
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = evaluatePostfix(arr, n);
    printf("Result: %d\n", result);

    return 0;
}
