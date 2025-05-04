# include <stdio.h>
# include <stdlib.h>
# define V 4

void init(int arr[][V]){
    int i,j;
    for(i = 0 ; i < V ; i++){
        for(j = 0 ; j < V ; j++){
            arr[i][j] = 0;
        }
    }
}
void addEdge(int arr[][V], int i, int j){
    arr[i][j] = 1;
    arr[j][i] = 1;
}
void printAdjMatirx(int arr[][V]){
    int i,j;
    for(i = 0 ; i < V ; i++){
        printf("%d",i);
        for(j = 0 ; j < V ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int adjMatirx[V][V];
    init(adjMatirx);
    addEdge(adjMatirx,0,1);
    addEdge(adjMatirx,0,2);
    addEdge(adjMatirx,1,2);
    addEdge(adjMatirx,2,3);
    addEdge(adjMatirx,2,0);
    printAdjMatirx(adjMatirx);
    return 0;
}