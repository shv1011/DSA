 #include<stdio.h>

    void ToH(int n, char to, char from, char aux )
    {
        if (n==1)
        {
            printf("Move disk 1 from %c to %c\n", from , to);
            return 1;
        }
        ToH(n-1,from, aux,to);
        printf("Move disk %d from %c to %c \n",n,  from , to);
        ToH(n-1, aux,to,from);
    }
int main()
{
    int n=4;
    ToH(n,'A','B','C');
    return 0;
}
