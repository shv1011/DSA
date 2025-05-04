# include <stdio.h>
# include <stdlib.h>
# define MAX 10
int count=0;
struct stack{
    int top;
    int items[MAX];
};
typedef struct stack st;
void createEmptyStack(st *s){
    s->top=-1;
}
int isFull(st *s){
    if(s->top==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(st *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(st *s,int value){
    if(isFull(s)){
        printf("Stack is full\n");
    }
    else{
        s->top++;
        s->items[s->top]=value;
        count++;
    }
}
void pop(st *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        printf("Item popped : %d",s->items[s->top]);
        s->top--;
        count--;
    }
}
void printStack(st *s){
        printf("Stack elements are : ");
        for(int i=0;i<count;i++){
            printf("%d ",s->items[i]);
        }
        printf("\n");
}
int main(){
    int ch;
    st*s=(st*)malloc(sizeof(st));
    createEmptyStack(s);
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    printStack(s);
    pop(s);
    printf("After popping an element\n");
    printStack(s);
    return 0;
}