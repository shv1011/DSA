#include <stdio.h>
#include <stdlib.h>

int RecursiveBinary(int arr[], int x, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == x) {
        return mid;
    }

    if (arr[mid] < x) {
        return RecursiveBinary(arr, x, mid + 1, high);
    } else {
        return RecursiveBinary(arr, x, low, mid - 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;

    int result = RecursiveBinary(arr, x, 0, n - 1);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
