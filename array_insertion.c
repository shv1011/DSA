#include<stdio.h>

int main()
{
    int i, t, a[10],n,m,s,j=0,b[10];
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Given values are :");
    for(i=0;i<n;i++){
        printf("a[%d] = %d ",i,a[i]);
    }
    printf("Enter the position of elements to be inserted: ");
    scanf("%d",&t);
    printf("Enter the value to be inserted : ");
    scanf("%d",&s);
    for(i=0;i<n;i++){
        b[j]=a[i];
        j++;
    }
        b[j]=s;
        j++;
        for(i=t;i<n;j++){
            b[j]=a[i];
            j++;
        }
    printf("Inserted value is : ");
    for(i=0;i<n;i++){
        printf("a[%d] = %d ",i,b[j]);
    }
    return 0;
}
