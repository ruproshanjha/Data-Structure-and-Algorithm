#include <stdio.h>
#define MAX 5 // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to enqueue (add) an element to the queue
void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) { // First element to be enqueued
            front = rear = 0;
        } else if (rear == MAX - 1 && front != 0) { // Circular condition
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

// Function to dequeue (remove) an element from the queue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! No element to dequeue.\n");
    } else {
        printf("%d dequeued from queue.\n", queue[front]);
        
        if (front == rear) { // Queue becomes empty
            front = rear = -1;
        } else if (front == MAX - 1) { // Wrap around
            front = 0;
        } else {
            front++;
        }
    }
}

// Function to peek at the front element of the queue
void peek() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

// Function to display all elements in the queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (int i = front; i < MAX; i++) {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
