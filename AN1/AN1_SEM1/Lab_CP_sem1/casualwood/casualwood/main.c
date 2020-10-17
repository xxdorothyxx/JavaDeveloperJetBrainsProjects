#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *movies;
    char *name;
} actors;

void initializeActors(actors *a)
{
    a->name=(char*)malloc(sizeof(char*)*100);
    a->movies=(char*)malloc(sizeof(char*)*100);
}

int sameActor(int l,actors *a,char *p)
{
    int i,j;
    for(i=0; i<l-1; i++)
    {
        if(strcmp(a[i].name,p)==0)
            return i;
    }
    return 1;
}

actors *readMovies(int *n)
{
    FILE *f;
    f=fopen("movies.txt","r");

    actors *a=(actors*)malloc(sizeof(actors*)*100);
    char *strbuf=(char*)malloc(sizeof(char*)*100);
    char *p=(char*)malloc(sizeof(char*)*100);
    int i=0,j;

    while(fgets(strbuf,100,f)!=NULL)
    {
        puts(strbuf);
        char *movie=strtok(strbuf,",");

        p=strtok(NULL,",");
        while(p!=NULL)
        {
            if(i==0||sameActor(i,a,p)==1)
            {
                initializeActors(&a[i]);
                strcpy(a[i].movies,movie);
                strcpy(a[i].name,p);
                i++;
            }
            else
            {
                j=sameActor(i,a,p);
                strcat(a[j].movies,movie);
                a[j].movies[strlen(a[j].movies)]=NULL;
            }
            p=strtok(NULL,",");
        }
    }
    *n=i;
    fclose(f);
    return a;
}

void printFriends(actors *a,int n,char *actor)
{
    int i,j;
    char *p=(char*)malloc(sizeof(char*)*100);

    for(i=0; i<n; i++)
    {
        if(strcmp(a[i].name,actor)==0)
        {
            for(j=0; j<n; j++)
            {
                if(strstr(a[i].movies,a[j].movies)!=NULL&&i!=j)
                {
                    printf("\n%s",a[j].name);
                }
            }

        }
    }
}

void nrOfFriends(actors *a,int n,int *friends)
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(strstr(a[i].movies,a[j].movies)!=NULL)
            {
                friends[i]++;
                friends[j]++;
            }
        }
    }
}

int main()
{
    int n=0,i;
    actors *a=readMovies(&n);
    char *actor=(char*)malloc(sizeof(char*)*100);
    printf("give the name of the actor:");
    gets(actor);
    printFriends(a,n,actor);
    int *friends=(int*)malloc(sizeof(int*)*100);
    for(i=0; i<n; i++)
    {
        friends[i]=0;
    }
    nrOfFriends(a,n,friends);
    for(i=0; i<n; i++)
    {
        printf("\n%s %d",a[i].name,friends[i]);
    }
    return 0;
}
