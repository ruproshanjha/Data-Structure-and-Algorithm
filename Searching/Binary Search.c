#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid; // Return the index of the found element
        }
        // If key is greater, ignore left half
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        // If key is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int size;

    printf("Enter the number of elements (sorted): ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the sorted elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, size, key);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
