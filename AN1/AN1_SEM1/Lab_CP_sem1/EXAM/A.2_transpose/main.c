#include <stdio.h>
#include <stdlib.h>

int **function(int **a,int m,int n){
    int i,j;
    int **t=(int**)malloc(sizeof(int*)*m);
    for(i=0;i<m;i++){
        t[i]=(int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            if(i!=j){
                t[i][j]=a[j][i];
            }
            else{
                t[i][j]=a[i][j];
            }
        }
    }
    return t;
}
int main() {
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int **a;
    a=(int **)malloc(sizeof(int*)*m);
    for (int i=0;i<m;i++){
        a[i]=(int *)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int **t=function(a,n,m);
    for(int i=0;i<m;i++){
        printf("\n");
        for(int j=0;j<m;j++){
            printf("%d ",t[i][j]);
        }
    }
    return 0;
}