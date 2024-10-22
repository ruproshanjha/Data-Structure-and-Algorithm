#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize head and tail
struct Node* head = NULL;
struct Node* tail = NULL;

// Function to insert an element at the front of the list
void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    
    if (tail == NULL) // If list was empty
        tail = head;
}

// Function to insert an element at the back of the list
void insertBack(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to insert an element at a specific position (1-based index)
void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        if (tail == NULL) // If list was empty
            tail = head;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range!\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL) {
        tail = newNode;
    }
}

// Function to delete the front element
void deleteFront() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    if (head == NULL) // List becomes empty
        tail = NULL;
}

// Function to delete the back element
void deleteBack() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head == tail) { // Single node case
        free(head);
        head = tail = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    free(tail);
    tail = temp;
    tail->next = NULL;
}

// Function to delete an element at a specific position (1-based index)
void deleteAtPosition(int position) {
    if (head == NULL || position < 1) {
        printf("List is empty or invalid position!\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        if (head == NULL)
            tail = NULL;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of range!\n");
            return;
        }
        temp = temp->next;
    }

    struct Node* toDelete = temp->next;
    if (toDelete == NULL) {
        printf("Position out of range!\n");
        return;
    }

    temp->next = toDelete->next;
    if (toDelete == tail) {
        tail = temp;
    }
    free(toDelete);
}

// Function to get the length of the list
int getLength() {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Function to peek the front element
void peekFront() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        printf("Front element: %d\n", head->data);
    }
}

// Function to peek the back element
void peekBack() {
    if (tail == NULL) {
        printf("List is empty!\n");
    } else {
        printf("Back element: %d\n", tail->data);
    }
}

// Function to display all elements in the list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else {
        struct Node* temp = head;
        printf("List elements: ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, value, position;

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert Front\n2. Insert Back\n3. Insert at Position\n");
        printf("4. Delete Front\n5. Delete Back\n6. Delete at Position\n");
        printf("7. Peek Front\n8. Peek Back\n9. Get Length\n10. Display\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at back: ");
                scanf("%d", &value);
                insertBack(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteBack();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                peekFront();
                break;
            case 8:
                peekBack();
                break;
            case 9:
                printf("Length of the list: %d\n", getLength());
                break;
            case 10:
                display();
                break;
            case 11:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 11);

    return 0;
}
