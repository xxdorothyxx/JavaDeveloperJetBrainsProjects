#include <stdio.h>
#include <stdlib.h>

int main() {
    int T,N,X,i,k;
    scanf("%d",&T);
    for(k=1;k<=T;k++){
        scanf("%d%d",&N,&X);
        int *a=(int*)malloc(sizeof(int)*N);
        for(i=1;i<=N;i++){
            scanf("%d",&a[i]);
        }
        printf("\nCase #%d: ",k);
        int nr=0;
        while( nr != N){
            nr=0;
            for(i=1;i<=N;i++) {
                if (a[i] <= X && a[i] > 0) {
                    printf("%d ", i);
                    a[i] = 0;
                }
                if(a[i]>X){
                    a[i]=a[i]-X;
                }
                if(a[i]==0){
                    nr++;

                }
            }
        }
    }
    return 0;
}
