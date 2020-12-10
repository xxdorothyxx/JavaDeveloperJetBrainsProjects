#include <stdio.h>
#include <stdlib.h>
#include <stringh>
typedef struct{
   char *actor;
   char *movies;
} act;
void initializeActor(act *a){
    a->actor=(char*)malloc(sizeof(char)*100);
    a->movies=(char *)malloc(sizeof(char)*100);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}