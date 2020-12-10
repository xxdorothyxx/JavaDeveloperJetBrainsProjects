/*Citire/scriere fișiere
Pași:
 Declară un sir v de lungime MAX_SIZE (o constantă definită de tine)
 Citește n de la tastatură
 Deschide fișierul input.txt, citește n numere din el și salvează-le în v
 Salvează cele n numere în fișierul output.txt în ordine inversă
*/
#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 31

int main() {
    FILE *f=fopen("in.txt","r+");
    FILE *g=fopen("out.txt","w");

    int n,i;
    fscanf(f,"%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        fscanf(f,"%d",&a[i]);
    }
    for(i=n-1;i>=0;i--){
        fprintf(g,"%d ",a[i]);
    }
    return 0;
}

