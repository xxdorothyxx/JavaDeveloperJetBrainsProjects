#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct costumer{
char *name;
int money;
int seconds;
struct costumer *next;
}nodeCostumer;

typedef struct time
{
    int data;
    struct time *next;
}nodeTime;

nodeTime *firstSecond,*lastSecond;
nodeCostumer *firstCostumer,*lastCostumer;

void initialization (){
    firstSecond=NULL;
    lastSecond=NULL;
    firstCostumer=NULL;
    lastCostumer=NULL;
}

void AddSeconds(int data){
  if(firstSecond==NULL){
    firstSecond=(nodeTime*)malloc(sizeof(nodeTime));
    firstSecond->data=data;
    firstSecond->next=NULL;
    lastSecond=firstSecond;
  }
  else
  {
    nodeTime *newNode=(nodeTime*)malloc(sizeof(nodeTime));
    lastSecond->next=newNode;
    newNode->next=NULL;
    newNode->data=data;
    lastSecond=newNode;
  }
}

void storeSeconds(char *strbuf){
  char *p;
  p=strtok(strbuf," ");
  while(p){
    AddSeconds(atoi(p));
    p=strtok(NULL," ");
  }
}

void addCostumer(char *name,int money,int seconds){
  if(firstCostumer==NULL){
    firstCostumer = (nodeCostumer*)malloc(sizeof(nodeCostumer));
        firstCostumer->name = name;
        firstCostumer->money = money;
        firstCostumer->seconds = seconds;
        firstCostumer->next = NULL;
        lastCostumer = firstCostumer;
  }
  else
  {
    nodeCostumer *newNode=(nodeCostumer*)malloc(sizeof(nodeCostumer));
    lastCostumer->next=newNode;
    newNode->name=name;
    newNode->money=money;
    newNode->seconds=seconds;
    newNode->next=NULL;
    lastCostumer=newNode;
  }
}

void storeCostumers(char *strbuf){
  addCostumer(strtok(strbuf," "),atoi(strtok(NULL," ")),atoi(strtok(NULL," \n")));
}
void computeVerzisorii(FILE *g)
{
    
    nodeTime *currentSecond=firstSecond;
    nodeCostumer *currentCostumer=firstCostumer;
    int time,verzisorii;
    while(currentSecond)
    {
        verzisorii=0;
        fprintf(g,"After %d seconds: ",currentSecond->data);
        currentCostumer=firstCostumer;
        time=0;
        while(time+firstCostumer->seconds< currentSecond->data && currentCostumer != NULL)
        //!! currentCostumer != NULL!!
        {
            verzisorii=verzisorii+currentCostumer->money;
            time=time+currentCostumer->seconds;
            currentCostumer=currentCostumer->next;
        }
        fprintf(g,"%d\n",verzisorii);
        currentSecond=currentSecond->next;
    }
}
int main(){
    FILE *f=fopen("input.txt","r");
    FILE *g=fopen("output.txt","w");
    initialization();
    char *strbuf=(char*)malloc(sizeof(char)*100);
    fgets(strbuf,100,f);
    storeSeconds(strbuf);
    while(fgets(strbuf,100,f)){
    storeCostumers(strbuf);
    }
   computeVerzisorii(g);
    return 0;
}




















