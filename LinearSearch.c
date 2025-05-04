#include<stdlib.h>
int search(int arr[], int n, int a){
    for(int i=0; i<n; i++)
    {
        if(arr[i]==a)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[]={1,2,3,4,5};
    int a=2;
    int n= sizeof(arr)/sizeof(arr[0]);
    printf("%d", search(arr, n , a));
    return 0;
}

