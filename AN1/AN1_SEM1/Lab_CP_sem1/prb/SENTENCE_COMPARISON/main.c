#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NR_LETTERS 26
#define SENTENCE_LEN 200
//l-am facut cu file dar ultimele doua exemple dau diferit la b) si nush dc
typedef struct{
    char letter;
    int occurence;
}LO;
void initializeLetters(LO *l){
    int i;
    for(i=0;i<NR_LETTERS;i++){
        l[i].occurence=0;
        l[i].letter=i+'a';
    }
}
char **readSentences(int n,FILE *f){
    char **s=(char **)malloc(sizeof(char*)*n);
    int i;
    for(i=0;i<n;i++){
        s[i]=(char*)malloc(sizeof(char)*SENTENCE_LEN);
    }
    for(i=0;i<n;i++){
      if(i==0)
        fgetc(f);
      fgets(s[i],SENTENCE_LEN,f);
    }
    return s;
}
void letterOccurence (LO *l,char **s,int n){
    initializeLetters(l);
    for(int i=0; i<n; i++)
    {
        int j=0;
        while (s[i][j]!=NULL)
        {
            l[s[i][j]-'a'].occurence++;
            j++;
        }
    }
}
void sortByOcc(LO *l,char **s,int n){
    letterOccurence(l,s,n);
    int i,j;
    for(i=0;i<NR_LETTERS;i++){
        for(j=i;j<NR_LETTERS-1;j++) {
            if(l[i].occurence<l[j].occurence){
                LO aux=l[i];
                l[i]=l[j];
                l[j]=aux;
            }
        }
    }
}
void printLetterAndOcc(LO *l,int n,FILE *g){
    int i;
    for(i=0;i<NR_LETTERS;i++){
        if(l[i].occurence){
            fprintf(g,"%c = %d\n",l[i].letter,l[i].occurence);
        }
    }
}

int *rowCount(int x,char **s){
    int *r=(int*)malloc(sizeof(int)*NR_LETTERS);
    int j=0;
    for(int i=0;i<NR_LETTERS;i++){
        r[i]=0;
    }
    while(s[x][j]!=NULL){
        r[s[x][j]-'a']++;
        j++;
    }
    return r;
}
int *array(){
    int *a=(int*)malloc(sizeof(int)*NR_LETTERS);
    for(int i=0;i<NR_LETTERS;i++){
        a[i]=0;
    }
    return a;
}
int *clashOfTitans(int n,int m,char **s){
    int i;
    int *r=rowCount(m, s);
    int *a=array();
    int *v;
    for(i=0;i<n;i++){
        v=rowCount(i, s);
        for(int k=0;k<NR_LETTERS;k++){
            if(r[k]==v[k])
                a[i]++;
            else
                a[i]--;
        }

    }
    return a;
}
void printTheSupremeTitan(int n,int m,char **s,FILE *g){
    int *a=clashOfTitans(n, m, s);
    for(int i=0;i<n;i++){
        fprintf(g,"%d VS %d = %d\n",i,m,a[i]);
    }
}
int main() {

    int n;
    FILE *f=fopen("in.txt","r");
    fscanf(f,"%d",&n);
    LO *l=(LO*)malloc(sizeof(LO)*NR_LETTERS);
    char **s=readSentences(n,f);
    letterOccurence(l,s,n);
    sortByOcc(l,s,n);
    FILE *g=fopen("out.txt","w");
    printLetterAndOcc(l,n,g);
    //b)
    printf("SUB B\n");
    int m;
    scanf("%d",&m);
    printTheSupremeTitan(n, m, s, g);
    return 0;
}
