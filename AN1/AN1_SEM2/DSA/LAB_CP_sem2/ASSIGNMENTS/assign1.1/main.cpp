#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
}nodeT;

nodeT *first,*last;

void initialization (){
    first=NULL;
    last=NULL;
}

void AF(int data){
    if(first==NULL){
        first=(nodeT*)malloc(sizeof(nodeT));first->data=data;
        first->next=last;
        last=first;
    }
    else
    {
        nodeT *newNode=(nodeT*)malloc(sizeof(nodeT));
        newNode->data=data;
        newNode->next=first;
        first=newNode;
    }
}

void AL(int data){
    if(last==NULL){
        last=(nodeT*)malloc(sizeof(nodeT));
        last->data=data;
        last->next=NULL;
        first=last;
    }
    else{
        nodeT *newNode=(nodeT*)malloc(sizeof(nodeT));
        newNode->data=data;
        newNode->next=NULL;
        last->next=newNode;
        last=newNode;
    }
}

void DF(){
    if(first!=NULL){
        nodeT *currentNode=first->next;
        free(first);
        first=currentNode;}
    return ;
}

void DL(){
    nodeT *currentNode=first;
    if(first != NULL){
        while(currentNode->next!= last){
            currentNode=currentNode->next;
        }
        free(last);
        last=currentNode;
        last->next=NULL;
    }
}

void DOOM_THE_LIST(){
    nodeT *currentNode=first;
    while(currentNode!=NULL)
    {
        currentNode=currentNode->next;
        free(first);
        first=currentNode;
    }
    last=NULL;
}

void DE(int data){
    nodeT *currentNode = first;
    nodeT *previousNode = first;
    while(currentNode != NULL)
    {
        if(currentNode->data == data)
        {
            if(currentNode == first)
            {
                first = currentNode->next;
                free(currentNode);
                currentNode = first;
                previousNode = first;
            }
            else if(currentNode == last)
            {
                free(currentNode);
                last = previousNode;
                last->next = NULL;
                currentNode = NULL;
            }
            else
            {
                previousNode->next = currentNode->next;
                free(currentNode);
                currentNode = previousNode->next;
            }
        }
        else
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

void PRINTall(FILE *g){
    nodeT *currentNode = first;
    while(currentNode != NULL){
        fprintf(g,"%d ",currentNode->data);
        currentNode=currentNode->next;
    }
    fprintf(g,"\n");
}

void PRINT_F(FILE *g,int x){
    nodeT *currentNode=first;
    int contor=0;
    while(contor!=x && currentNode!=NULL){
        fprintf(g,"%d ",currentNode->data);
        currentNode=currentNode->next;
        contor++;
    }
    fprintf(g,"\n");
}

void PRINT_L(FILE *g,int x){
    nodeT *currentNode=first;
    int nrElements=0;
    while(currentNode!=NULL){
        nrElements++;
        currentNode=currentNode->next;
    }
    if(x>=nrElements){
        PRINTall(g);
    }
    else
    {
        currentNode=first;
        for(int i=1;i<=nrElements;i++){
            if(i>nrElements-x){
                fprintf(g,"%d ",currentNode->data);
            }
            currentNode=currentNode->next;
        }
    }
    fprintf(g,"\n");
}

int main(){
    FILE *f=fopen("input.txt","r");
    FILE *g=fopen("output.txt","w");
    initialization();
    char *strbuf=(char*)malloc(sizeof(char)*100);
    while(fgets(strbuf,100,f)){
        char *theCommand=(char*)malloc(sizeof(char)*100);
        int data;
        char *p=strtok(strbuf," \n");
        strcpy(theCommand,p);
        puts(theCommand);
        if(strstr(theCommand,"AF")){
            p=strtok(NULL," \n");
            data=atoi(p);
            AF(data);
        }
        if(strstr(theCommand,"AL")){
            p=strtok(NULL," \n");
            data=atoi(p);
            AL(data);
        }
        if(strstr(theCommand,"DF")){
            DF();
        }
        if(strstr(theCommand,"DL")){
            DL();
        }
        if(strcmp(theCommand,"PRINTall")==0){
            PRINTall(g);
        }

        if(strstr(theCommand,"DE")){
            p=strtok(NULL," \n");
            data=atoi(p);
            DE(data);
        }
        if(strstr(theCommand,"PRINT_F")){
            p=strtok(NULL," \n");
            data=atoi(p);
            PRINT_F(g,data);
        }
        if(strstr(theCommand,"PRINT_L")){
            p=strtok(NULL," \n");
            data=atoi(p);
            PRINT_L(g,data);
        }
        if(strstr(theCommand,"DOOM_THE_LIST")){
            DOOM_THE_LIST();
        }
        //  PRINTall(g);
    }
    printf("orice");
    return 0;
}




















