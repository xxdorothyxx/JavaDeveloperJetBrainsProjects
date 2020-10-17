#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 50
#define SEN_LEN 900
typedef struct{
    char *name;
    char *type;
    int power;
}hero;
typedef struct{
    char *name;
    char *type;
    int powerNecessary;
    int experience;
}quest;
void initializeHeroes(hero *h){
    h->name=(char*)malloc(sizeof(char)*NAME);
    h->type=(char*)malloc(sizeof(char)*100);
}
void initializeQuests(quest *q){
    q->name=(char*)malloc(sizeof(char)*NAME);
    q->type=(char*)malloc(sizeof(char)*100);
}
hero *readHeroes(FILE *f,int *n){
    int i=0;
    hero *h=(hero*)malloc(sizeof(hero)*100);
    char *s=(char*)malloc(sizeof(char)*SEN_LEN);
    char *p;
    while(fgets(s,SEN_LEN,f)){
        initializeHeroes(&h[i]);
        p=strtok(s,",");
        strcpy(h[i].name,p);
        puts(p);
        printf(",");
        p=strtok(NULL,",");
        strcpy(h[i].type,p);
        puts(p);
        printf(",");
        p=strtok(NULL,",");
        int x;
        sscanf(p, "%d", &x);
        printf("%d",x);
        h[i].power=x;
        printf("\n");
        i++;
    }
    *n=i;
    return h;
}
quest *readQuests(FILE *g,int *m){
    int i=0;
    quest *q=(quest*)malloc(sizeof(quest)*100);
    char *s=(char*)malloc(sizeof(char)*SEN_LEN);
    char *p;
    while(fgets(s,SEN_LEN,g)){
        initializeQuests(&q[i]);
        p=strtok(s,",");
        strcpy(q[i].name,p);
        puts(p);
        printf(",");
        p=strtok(NULL,",");
        strcpy(q[i].type,p);
        puts(p);
        printf(",");
        p=strtok(NULL,",");
        int x;
        sscanf(p, "%d", &x);
        printf("%d",x);
        q[i].powerNecessary=x;
        printf(",");
        p=strtok(NULL,",");
        sscanf(p, "%d", &x);
        printf("%d",x);
        q[i].experience=x;
        printf("\n");
        i++;
    }
    *m=i;
    return q;
}
void sortHeroes(hero *h,int n){
    int i,j;
    hero a;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(h[i].power<h[j].power){
                a=h[i];
                h[i]=h[j];
                h[j]=a;
            }
        }
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(h[i].type,h[j].type)<0){
                a=h[i];
                h[i]=h[j];
                h[j]=a;
            }
        }
    }
}
int enougHeroes(hero *h,quest *q,int x,int n,int m){
    int i,j=0;
    for(i=0;i<n ;i++){
        if(h[i].type[0]==q[x].type[j] ){
            if(h[i].type[0]!=h[i+1].type[0]){
                i=-1;}
            if(i==-1 && q[x].type[j]==q[x].type[j+1]){
                return 0;}
            j++;
        }
    }
    return 1;
}
int theMission(hero *h,quest *q,int x,int n,int m,int *s1){
    int i,j=0;
    int s=0;
    if(enougHeroes(h, q, x, n, m)==0)
        return 0;
    for(i=0;i<n;i++){
        if(h[i].type[0]==q[x].type[j]){
            printf("%s,",h[i].name);
            s=s+h[i].power;
            if(h[i].type[0]!=h[i+1].type[0]|| q[x].type[j]!=q[x].type[j+1])
                i=-1;
            j++;
        }
    }
    *s1=s;
    return 1;
}
void printMission(hero *h,quest *q,int n,int m){
    int j;
    int ss;
    int argus=0;
    for(j=0;j<m;j++){
        int i=theMission(h,q,j,n,m,&ss);
        if(i==0){
            printf("There aren't enough heroes of a type to complete the mission \n");}
        if(ss<q[j].powerNecessary && i==1 ){
            printf("There isn't enough power to complete the mission: ");
        }
        if(i==1){
            printf("\nSUCCES with %d vs. %d and gained %d XP \n",ss,q[j].powerNecessary,q[j].experience);argus=argus+q[j].experience;
        }

    }
    if(argus<100)
        printf("Our heroes couldn't enter Argus with just %d.Poor them",argus);
    else
        printf("Our heroes could enter Argus with %d.Congrats!!!!!!!",argus);
}
int main(void) {
    int n,m;
    FILE *f=fopen("heroes.txt","r");
    hero *h=readHeroes(f,&n);
    FILE *g=fopen("quests.txt","r");
    quest *q=readQuests(g,&m);
    sortHeroes(h,n);
    for(int i=0;i<n;i++){
        puts(h[i].type);
        printf("%d ",h[i].power);
        puts(h[i].name);

    }
    printMission(h,q,n,m);
    return 0;
}
