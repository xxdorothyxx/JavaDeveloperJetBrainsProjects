#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 50
#define SEN_LEN 900
//pana la req 3 ii ok si req3 ramane pe alta data
typedef struct{
    char *name;
    char **actor;
    int numberOfActors;
    int nrAllMov;
}movie;
void initializeMovies(movie *m){
    m->name=(char*)malloc(sizeof(char)*NAME);
    m->actor=(char**)malloc(sizeof(char*)*SEN_LEN);
    for(int j=0;j<100;j++)
        m->actor[j]=(char*)malloc(sizeof(char)*NAME);
    m->numberOfActors=0;
}
movie *readMovies(FILE *f){
    int i=0;
    movie *m=(movie*)malloc(sizeof(movie)*100);
    char *s=(char*)malloc(sizeof(char)*SEN_LEN);
    char *p;
    while(fgets(s,SEN_LEN,f)){
        initializeMovies(&m[i]);
        p=strtok(s,",");
        int j=0;
        strcpy(m[i].name,p);
        puts(p);
        printf(",");
        p=strtok(NULL,",");
        while(p){
            strcpy(m[i].actor[j++],p);
            puts(p);
            printf(",");
            m[i].numberOfActors++;
            p=strtok(NULL,",");
        }
        printf("\n");
        i++;
    }
    m[0].nrAllMov=i;
    return m;
}
void friendsFromOneMovie(int x,movie *m,char *a){
    int j;
    for(j=0;j<m[x].numberOfActors;j++){
        if(strcmp(m[x].actor[j],a)!=0)
            puts(m[x].actor[j]);
    }
}

void findFriends(char *a,movie *m){
    int i,j,x;
    for(i=0;i<m[0].nrAllMov;i++){
        for(j=0;j<m[i].numberOfActors;j++){
            if(strcmp(m[i].actor[j],a)==0){
                x=i;
                friendsFromOneMovie(x,m,a);
            }
        }
    }
}

}
int main(void) {
    FILE *f=fopen("in.txt","r");
    movie *m=readMovies(f);
    char *a=(char*)malloc(sizeof(char)*NAME);
    gets(a);
    printf("The friends of this person are:\n");
    findFriends(a, m);
    return 0;
}
