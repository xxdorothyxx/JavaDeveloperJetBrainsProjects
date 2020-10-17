#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char *name;
    char *country;
    int artifacts;
    int distance;
}explorer;


void initializeExplorers(explorer *e){
    e->name=(char*)malloc(sizeof(char)*50);
    e->country=(char*)malloc(sizeof(char)*50);
}

explorer *readExplorers(FILE *f,int *n){
    int i=0;
    int nr;
    fscanf(f,"%d\n",&nr);
    explorer *e=(explorer*)malloc(sizeof(explorer)*nr);
    char *s=(char*)malloc(sizeof(char)*900);
    char *p=(char*)malloc(sizeof(char)*50);
    while(fgets(s,900,f)){
        initializeExplorers(&e[i]);
        p=strtok(s,",");
        strcpy(e[i].name,p);
        p=strtok(NULL,",");
        strcpy(e[i].country,p);
        p=strtok(NULL,",");
        e[i].artifacts=atoi(p);
        p=strtok(NULL,",");
        e[i].distance=atoi(p);
        i++;
    }
    *n=nr;
    return e;
}

void sortExplorers(explorer *e,int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(e[i].artifacts<e[j].artifacts){
                explorer aux=e[i];
                e[i]=e[j];
                e[j]=aux;
            }
        }
    }
}

void printMexplorers(explorer *e,FILE *g,int m,int n){
    int i;
    if(m>n)
        m=n;
    for(i=0;i<m;i++){
        fputs(e[i].name,g);
        fprintf(g,",");
        fputs(e[i].country,g);
        fprintf(g,",");
        fprintf(g,"%d",e[i].artifacts);
        fprintf(g,",");
        fprintf(g,"%d",e[i].distance);
        fprintf(g,"\n");
    }
}

typedef struct{
    char *country;
    int age;
}holyGrail;

void initializeGrail(holyGrail h){
    h.country=(char*)malloc(sizeof(char)*50);
}

holyGrail readHolyGrail(FILE *a){
    holyGrail h;
    initializeGrail(h);
    char *s=(char*)malloc(sizeof(char)*900);
    fgets(s,900,a);
    strcpy(h.country,strtok(s,","));
    h.age=atoi(strtok(NULL,","));
    return h;
}

void sortByDistance(explorer *e,int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(e[i].distance>e[j].distance){
                explorer aux=e[i];
                e[i]=e[j];
                e[j]=aux;
            }
        }
    }
}

void printByDistance(FILE *b,explorer *e,int n){
    int i;
    for(i=0;i<n;i++){
        fputs(e[i].name,b);
        fprintf(b,",");
        fputs(e[i].country,b);
        fprintf(b,",");
        fprintf(b,"%d",e[i].artifacts);
        fprintf(b,",");
        fprintf(b,"%d",e[i].distance);
        fprintf(b,"\n");
    }
}

int main(void) {
    FILE *f=fopen("explorers.dat","r");
    int n;
    explorer *e=readExplorers(f,&n);
    sortExplorers(e,n);
    FILE *g=fopen("discoveriesExplorers.dat","w");
    int m;
    scanf("%d",&m);
    printMexplorers(e,g,m,n);
    FILE *a=fopen("holyGrail.dat","r");
    holyGrail h=readHolyGrail(a);
    FILE *b=fopen("grailExplorers.dat","w");
    sortByDistance(e,n);
    printByDistance(b,e,n);
    return 0;
}