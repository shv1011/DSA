#include<stdio.h>

int main()
{
    int i, t, a[10], n, s, j=0, b[11]; 
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\nGiven values are:\n");
    for(i = 0; i < n; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("\nEnter the position of element to be inserted: ");
    scanf("%d", &t);
    printf("Enter the value to be inserted: ");
    scanf("%d", &s);
    for(i = 0; i < t; i++){
        b[j++] = a[i];
    }
    b[j++] = s;
    for(i = t; i < n; i++){
        b[j++] = a[i];
    }
    printf("\nFinal array after insertion:\n");
    for(i = 0; i < j; i++){
        printf("a[%d] = %d\n", i, b[i]);
    }
    return 0;
}
