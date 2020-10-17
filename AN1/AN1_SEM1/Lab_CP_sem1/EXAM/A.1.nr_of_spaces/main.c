#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **citire(FILE *f,int *longest){
    int max=0,i=0,j;
    char **s=(char*)malloc(sizeof(char)*100);
    char *strbuf=(char*)malloc(sizeof(char)*200);
    while(fgets(strbuf,900,f)){
        s[i]=(char*)malloc(sizeof(char)*200);
        if(max>strlen(s))
            max=strlen(s);
        strcpy(s[i++],strbuf);
    }
    *longest=max;
}
void afisare(FILE *g, char **s,int max){
    char **n=(char*)malloc(sizeof(char)*100);
    int i,j;
    char *p;
    for(i=0;i<n;i++){
        n[i]=(char*)malloc(sizeof(char)*max);
        int nr_words=0;
        p=strtok(" ",s[i]);
        for(int j=1;j<strlen(s[i])-1;j++){
            n[i][j]=0;
            if(isalpha(s[j-1]) && s[j]==" "){
                nr_words++;
            }
        p=strtok(",",s[i]);
            while(p){
                
            }

     }

    }
}

int main() {
    FILE *f=fopen("input.txt","r");
    FILE *g=fopen("output.txt","w");
    int longest;
    char **s=citire(f,longest);
    return 0;
}