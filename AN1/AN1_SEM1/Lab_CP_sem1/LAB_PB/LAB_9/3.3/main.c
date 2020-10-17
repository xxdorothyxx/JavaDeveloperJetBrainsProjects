#include <stdio.h>
#include<string.h>
#include<stdlib.h>
// am observat in functia main ca inaintea citirii sirului 2 daca pun getchar() nu imi ia in considerare primul caracter al sirului
void inserare(int i,char *s1 ,char *s2){
    char *aux;
    aux=(char*)malloc(100*sizeof(char));
    strcpy(aux,s1+i);
    strcpy(s1+i,s2);
    strcat(s1,aux);
}
int main() {
        char *s2,*s1;
        int i;
        s1=(char*)malloc(100*sizeof(char));
        s2=(char*)malloc(100*sizeof(char));
        printf("Pozitia de la care inseram al doilea sir este:\n ");
        scanf("%d",&i);
        printf("Primul sir este:\n");
        getchar();
        gets(s1);
        printf("Al doilea sir este:\n");
        //getchar();
        gets(s2);
        inserare(i,s1,s2);
        printf("Sirul final dupa inserare este:\n");
        puts(s1);
    return 0;
}