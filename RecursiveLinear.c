# include<stdlib.h>
# include<stdio.h>

int search(int arr[],int n, int a, int index)
{
    if(index>=n){
        return -1;
    }
    if(arr[index]==a){
        return index;
    }
    else{
        return search(arr,n,a,index+1);
    }
}

int main()
{
    int arr[]={1,2,3,4,5};
    int a=2;
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("%d",search(arr,n,a,0));
    return 0;
}
