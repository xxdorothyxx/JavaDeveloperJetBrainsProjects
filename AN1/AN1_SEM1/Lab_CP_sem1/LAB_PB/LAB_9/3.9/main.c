#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//mi-a dat bine cand l.am verificat
void swapString(char *x,char *y){
    char *aux=(char*)malloc(100*sizeof(char));
    strcpy(aux,x);
    strcpy(x,y);
    strcpy(y,aux);
}
void swapYear(int a,int b){
    int aux;
    aux=a;
    a=b;
    b=aux;
}
char  **kingsAlpha(int n,char **name){
    char **king=(char**)malloc(100*sizeof(char*));
    int i,j;
    for(i=0;i<n;i++){
        king[i]=(char*)malloc(100*sizeof(char));
    }
    for(i=0;i<n;i++){
        strcpy(king[i],name[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(king[i],king[j])>0){
            swapString(king[i],king[j]);
            }
        }
    }
    return king;
}
int main() {
    int n;
    printf("Introduce cati regi au domnit:\n");
    scanf("%d",&n);
    char **name=(char**)malloc(100*sizeof(char*));
    int *firstYear=(int*)malloc(100*sizeof(int));
    int *lastYear=(int*)malloc(100*sizeof(int));
    int i,j;
    for(i=0;i<n;i++) {
        name[i] = (char *) malloc(100 * sizeof(char *));
    }
    for(i=0;i<n;i++){
        printf("Introduceti numele regelui, primul si ultimul an de domnie:\n");
        getchar();
        gets(name[i]);
        printf("|");
        scanf("%d",&firstYear[i]);
        printf("|");
        scanf("%d",&lastYear[i]);
    }
    printf("Numele regilor in ordinea in care au fost introdusi:\n");
    for(i=0;i<n;i++){
        puts(name[i]);
    }
    printf("Numele regilor in ordinea alfabetica:\n");
    char **king=(char**)malloc(100*sizeof(char*));
    for(i=0;i<n;i++){
        king[i]=(char*)malloc(100*sizeof(char));
    }
    king=kingsAlpha(n,name);
    for(i=0;i<n;i++){
        puts(king[i]);
        printf(" a domnit %d ani\n ",lastYear[i]-firstYear[i]);
    }
    printf("\nRegii in ordinea in care au urcat la tron:\n");
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(firstYear[i]>firstYear[j]){
                swapString(name[i],name[j]);
                swapYear(firstYear[i],firstYear[j]);
                swapYear(lastYear[i],lastYear[j]);
            }
        }
    }
    for(i=0;i<n;i++){
        printf("Intre %d si %d a domnit ",firstYear[i],lastYear[i]);
        puts(name[i]);
    }
    return 0;
}