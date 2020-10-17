#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*typedef struct {
    int day;
    int month;
    int year;
}date;*/
typedef struct{
    //date d;
    char *date;
    char *first_name;
    char *last_name;
    int id;
    char *action;
}entry;

void initializeEntry(entry *e){
    e->date=(char*)malloc(sizeof(char)*50);
    e->first_name=(char*)malloc(sizeof(char)*50);
    e->last_name=(char*)malloc(sizeof(char)*50);
    e->action=(char*)malloc(sizeof(char)*50);
}
entry *readEntry(FILE *f,int *n){
    entry *e=(entry*)malloc(sizeof(entry)*100);
    char *s=(char*)malloc(sizeof(char)*900);
    int i=0;
    while(fgets(s,900,f)){
        printf("%d\n",i);
        initializeEntry(&e[i]);
        strcpy(e[i].date,strtok(s,","));
        puts(e[i].date);
        strcpy(e[i].first_name,strtok(NULL,","));
        puts(e[i].first_name);
        strcpy(e[i].last_name,strtok(NULL,","));
        puts(e[i].last_name);
        e[i].id=atoi(strtok(NULL,","));
        printf("%d",e[i].id);
        strcpy(e[i].action,strtok(NULL,","));
        puts(e[i].action);
        i++;
    }
    *n=i;
    return e;
}
int main() {
    FILE *f=fopen("in.txt","r");
    int n;
    entry *e=readEntry(f,&n);
    return 0;
}