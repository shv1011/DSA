# include <stdio.h>
# include <stdlib.h>

void Swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int Partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            Swap(&arr[i],&arr[j]);
        }
    }
    Swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void QuickSort(int arr[], int low, int high){
    if(low<high){
        int pi=Partition(arr,low,high);
        QuickSort(arr,pi+1,high);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, arr_size - 1);
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}