#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

// Function to insert an element at the front of the list
void insertFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    } else {
        tail = newNode; // If list was empty, set tail
    }
    head = newNode;
}

// Function to insert an element at the back of the list
void insertBack(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL) {
        tail->next = newNode;
    } else {
        head = newNode; // If list was empty, set head
    }
    tail = newNode;
}

// Function to insert an element at a specific position (1-based index)
void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertFront(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

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
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    } else {
        tail = newNode;
    }

    temp->next = newNode;
}

// Function to delete the front element
void deleteFront() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL; // List becomes empty
    }

    free(temp);
}

// Function to delete the back element
void deleteBack() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = tail;
    tail = tail->prev;

    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL; // List becomes empty
    }

    free(temp);
}

// Function to delete an element at a specific position (1-based index)
void deleteAtPosition(int position) {
    if (position < 1 || head == NULL) {
        printf("List is empty or invalid position!\n");
        return;
    }

    if (position == 1) {
        deleteFront();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position; i++) {
        if (temp == NULL) {
            printf("Position out of range!\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
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

// Function to display the list in forward direction
void displayForward() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display the list in reverse direction
void displayBackward() {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = tail;
    printf("List (Backward): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, position;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert Front\n2. Insert Back\n3. Insert at Position\n");
        printf("4. Delete Front\n5. Delete Back\n6. Delete at Position\n");
        printf("7. Peek Front\n8. Peek Back\n9. Get Length\n10. Display Forward\n11. Display Backward\n12. Exit\n");
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
                displayForward();
                break;
            case 11:
                displayBackward();
                break;
            case 12:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 12);

    return 0;
}
