# include <stdio.h>
# include <stdlib.h>

int main(){
    int i,n1,n2,*ptr;
    printf("Enter size : ");
    scanf("%d",&n1);
    ptr=(int*)malloc(n1*sizeof(int));
    printf("Address of previosuly allocated memory : \n");
    for(i=0;i<n1;i++){
        printf("%d ",ptr+i);
    }
    printf("\nEnter new size : ");
    scanf("%d",&n2);
    ptr=(int*)realloc(ptr,n2*sizeof(int));
    printf("Address of newly allocated memory : \n");
    for(i=0;i<n2;i++){
        printf("%d ",ptr+i);
    }
    printf("\n");
    free(ptr);
    return 0;
}