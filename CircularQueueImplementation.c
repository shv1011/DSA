#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    if((front == (rear + 1) % SIZE) || (rear == SIZE - 1 && front == 0)){
        return 1;
    }
    else
        return 0;
}

int isEmpty() {
    if(front == -1){
        return 1;
    }
    else
        return 0;
}
void enQueue(int val) {
    if (isFull())
        printf("Queue is full!\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = val;
        printf("Inserted: %d\n", val);
    }
}

int deQueue() {
    int element;
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    else{
        element = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("Deleted: %d\n", element);
        return element;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    else{
        printf("Front -> %d\n", front);
        printf("Queue elements: ");
        for (int i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[rear]);
        printf("rear -> %d\n", rear);
    }
}

int main() {
    deQueue();
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    display();
    deQueue();
    display();
    enQueue(50);
    return 0;
}
