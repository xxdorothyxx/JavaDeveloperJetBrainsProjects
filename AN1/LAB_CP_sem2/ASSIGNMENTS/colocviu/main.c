//
//  main.c
//  colocviu
//
//  Created by Sandor Doroteea on 5/21/20.
//  Copyright © 2020 Doroteea Sandor. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int **AdjMatrix;
int **fillAdjMatrix(FILE *f,int N){
    AdjMatrix=(int**)malloc(sizeof(int*)*N);
    for(int i=0;i<N;i++){
        AdjMatrix[i]=(int*)malloc(sizeof(int)*N);
        for(int j=0;j<N;j++){
                AdjMatrix[i][j]=0;
        }
    }
    char *p;
    char *strbuf=(char*)malloc(sizeof(char)*100);
    for(int i=0;i<N;i++){
        fgets(strbuf,100,f);
        p=strtok(strbuf," ");
        int nod=*p-'A';
        p=strtok(NULL, " ");
        while(p){
            AdjMatrix[nod][*p-'A']=1;
            p=strtok(NULL," ");
        }
    }
    return AdjMatrix;
}
void printAdjMatrix(int N) {
    int i, j;
    printf("\nThe matrix is:\n");
    printf("    ");
    for (i = 0; i < N; i++) {
        printf("%c   ", 'A' + i);
    }
    printf("\n");
    for (i = 0; i < N; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < N; j++)
            printf("%3d ", AdjMatrix[i][j]);
        printf("\n");
    }
    printf("\n");
}
int isFriend(int k,int *output,int j){
    int ok=1,i;
    for(i=0;i<k;i++){
        if(output[i]==j)
            ok=0;
    }
    return ok;
}
void secondBestFriend(int **AdjMatrix,char a,int N){
    int a_node=a-'A';
    int k=0;
    int *output=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        if(AdjMatrix[a_node][i]){                    //cautam prieten al numelui
            for(int j=0;j<N;j++){
                if(AdjMatrix[i][j] &&               // verifica urmatorul prieten al prietenului numelui introdus
                    AdjMatrix[a_node][j]==0 &&     //verificam daca prietenul prietenului nu este si prietenul numelui cautat
                     isFriend(k,output,j)==1&&    //verificam sa nu il fi pus deja de la alt prieten
                   j!=a_node) {                   // verificam sa nu fie chiar numele cautat prieten cu primul prieten
                    output[k]=j;
                    k++;
            }
        }
    }
    }
for(int i=0;i<k-1;i++){
        for(int j=i+1;j<k;j++){
            if(output[i]>output[j]){
                char aux=output[i];
            output[i]=output[j];
            output[j]= aux;
        }
    }
}
    for(int i=0;i<k;i++){
        printf("%c ",output[i]+'A');
    }
}

int main() {
    
    FILE *f=fopen("input.txt","r");
    int N;
    char a;
    fscanf(f,"%d",&N);
    AdjMatrix=fillAdjMatrix(f, N);
    printAdjMatrix(N);
    printf("Numele care trebuie sa il cautam este : ");
    scanf("%c",&a);
    secondBestFriend(AdjMatrix, a, N);
    return 0;
}
