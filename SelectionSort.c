# include <stdio.h>
# include <stdlib.h>

void swap( int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}   
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
