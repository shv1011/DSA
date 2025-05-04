#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enQueue(int val) {
    if (rear == SIZE - 1)
        printf("Queue Full!\n");
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = val;
        printf("Inserted: %d\n", val);
    }
}

void deQueue() {
    if (front == -1)
        printf("Queue Empty!\n");
    else {
        printf("Deleted: %d\n", queue[front]);
        front++;
        if (front > rear){
            front = rear = -1;
        }
    }
}

void display() {
    if (rear == -1)
        printf("Queue Empty!\n");
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int items[SIZE],front=-1,rear=-1;
int main() {
    deQueue();
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);
    display();
    deQueue();
    display();
    return 0;
}
