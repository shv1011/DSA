# include <stdio.h>
# include <stdlib.h>

void Merge(int arr[], int p, int q, int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1], M[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[p+i];
    }
    for(int j=0;j<n2;j++){
        M[j]=arr[q+1+j];
    }
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(L[i]<=M[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=M[j];
            j++;
        }
        k++;
    }
    while(j<n2){
        arr[k]=M[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[], int l, int r){
    if(l<r){
        int m=1+(r-l)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, arr_size - 1);
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}