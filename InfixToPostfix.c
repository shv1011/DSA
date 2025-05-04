# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

int precedence(char c) {
    if(c == '^') 
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void InfixToPostfix(char *exp)
{
    int len = strlen(exp);
    char result[len + 1];
    char stack[len];
    int j = 0, top = -1;
    for(int i = 0; i < len; i++) {
        char c = exp[i];
        if(isalnum(c)) {
            result[j++] = c;
        } else if(c == '(') {
            stack[++top] = c;
        } else if(c == ')') {
            while(top != -1 && stack[top] != '(') {
                result[j++] = stack[top--];
            }
            top--; 
        } else {
            while((top != -1 && precedence(stack[top]) > precedence(c)) || (precedence(c) == precedence(stack[top]))) {
                result[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while(top != -1){
        result[j++]=stack[top--];
    }
    result[j] = '\0';
    printf("Postfix Expression: %s\n", result);
}

int main(){
    char exp[]="A+B*(C^D-E)";
    InfixToPostfix(exp);
    return 0;
}