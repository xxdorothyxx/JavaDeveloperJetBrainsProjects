#include <stdio.h>
#include <stdlib.h>

int **function(int **a,int **b,int n) {
    int i, j;
    int k;
    scanf("%d",&k);
    if(k>n*n){
        k=k-n;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
              b[i][j]=a[k/n][k%n];
        }
    }
    return b;
}

int main() {
    int n;
    scanf("%d", &n);
    int **a;
    a = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        a[i] = (int *) malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int **b = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        b[i] = (int *) malloc(sizeof(int) * n);
    b = function(a, b, n);
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
    }
    return 0;
}
}