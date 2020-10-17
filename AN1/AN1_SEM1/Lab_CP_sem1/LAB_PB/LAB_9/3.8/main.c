#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//All good dar daca ii mai pot face ceva sa "arate" mai bine poti sa imi zici
char **readTheStrings(int n) {
    int i;
    char **a;
    a = (char **) malloc(100 * sizeof(char *));
    for (i = 0; i < n; i++) {
        a[i] = (char *) malloc(100 * sizeof(char));
    }
    getchar();
    for(i=0;i<n;i++){
        gets(a[i]);
    }
    return a;
}
int *readYear(int n){
   int i, *s;
    s=(int*)malloc(100*sizeof(int));
    for(i=0;i<n;i++) {
        scanf("%d", &s[i]);
    }
    return s;
}
void swapString(char *x,char *y){
    char *aux;
    aux=(char*)malloc(100*sizeof(char));
    strcpy(aux,x);
    strcpy(x,y);
    strcpy(y,aux);
}
    char **subpunctA(int n,char **author){
    int i,j;
    char **au=(char**)malloc(sizeof(char*));
    for(i=0;i<n;i++){
        au[i]=(char*)malloc(100*sizeof(char));
    }
    for(i=0;i<n;i++){
        strcpy(au[i],author[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(au[i],au[j])>0){
                swapString(au[i],au[j]);
            }
        }
    }
    return au;
}
//Subpunctul B)
void subpunctB(int n,int *year,char **author,char **title){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n;j++){
            if(year[i]>year[j]){
                int aux=year[i];
                year[i]=year[j];
                year[j]=aux;
                swapString(author[i],author[j]);
                swapString(title[i],title[j]);
            }
        }
    }
}
int main() {
   int n,i;
   printf("Numarul de carti este:\n");
   scanf("%d",&n);
   char **author,**title;
   int *year;
   printf("INTRODUCE ATHORS:\n" );
   author=readTheStrings(n);
   printf("INTRODUCE TITLES:\n ");
   title=readTheStrings(n);
   printf("INTRODUCE YEARS OF PUBLICATION:\n ");
   year=readYear(n);
   //A)
   printf("AUTHORS ALPHABETICALLY:\n");
   char **A;
   A=(char**)malloc(100*sizeof(char*));
   for(i=0;i<n;i++){
       A[i]=(char*)malloc(sizeof(char));
   }
   A=subpunctA(n,author);
   for(i=0;i<n;i++){
       printf("\n");
       puts(A[i]);
   }
    //B)
    printf("AUTOR SI TITLU IN CRONOLOGIA ANULUI PUBLICARII:\n");
    subpunctB(n,year,author,title);
    for(i=0;i<n;i++) {
        printf("\nAN: %d", year[i]);
        printf("|  AUTOR: ");
        puts(author[i]);
        printf("|  TITLE: ");
        puts(title[i]);
    }
    return 0;
}