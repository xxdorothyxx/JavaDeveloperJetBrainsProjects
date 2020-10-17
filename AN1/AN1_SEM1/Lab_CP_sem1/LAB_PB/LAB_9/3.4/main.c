#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// all good
void deleteSubstring(int i, int n, char*s){
    char *aux;
    aux=(char*)malloc(100*sizeof(char));
    strcpy(aux,s+i+n);
    strcpy(s+i,aux);
}
int main() {
    char *s;
    int i,n;
    s=(char*)malloc(100*sizeof(char));
    printf("Pozitia de la care se sterge subsirul este: \n");
    scanf("%d",&i);
    printf("Subsirul care se va sterge are un nr de carac egal cu:\n ");
    scanf("%d",&n);
    printf("Sirul dat este:\n");
    getchar();
    gets(s);
    deleteSubstring(i,n,s);
    puts(s);
    return 0;
}