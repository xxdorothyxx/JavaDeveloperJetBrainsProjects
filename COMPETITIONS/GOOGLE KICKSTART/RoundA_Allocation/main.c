#include <stdio.h>
#include <stdlib.h>

int main() {
    int T,k;
    scanf("%d",&T);
    printf("%d\n",T);
    for( k=1;k<=T;k++) {
        int i,N,B;
        scanf("%d %d", &N, &B);
        int *houses=(int*)malloc(sizeof(int)*N);
        for(i=0;i<N;i++){
            scanf("%d",&houses[i]);
        }
        for (i = 0; i < N-1; i++) {
            for (int  j = i+1 ; j < N; j++) {
                if (houses[i] > houses[j]) {
                    int aux = houses[i];
                    houses[i] = houses[j];
                    houses[j] = aux;
                }
            }
        int nrHouses=0;
        int totalPrice=houses[0];
        for(i=1;i<N;i++){
            if(totalPrice <= B) {
                nrHouses++;
                totalPrice = totalPrice + houses[i];
            }
        }
        printf("\nCase #%d: %d",k,nrHouses);
    }
    return 0;
}

