//
//  main.c
//  L6.mandatory.1
//
//  Created by Sandor Doroteea on 5/21/20.
//  Copyright © 2020 Doroteea Sandor. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define B 10

int f(char *key ){
int sum, len;
sum = 0;
len = strlen(key) ;
for (int i = 0; i < len; i++)
sum += key[ i ];
return  (sum % B) ;
}

typedef struct cell {
char key[60];
struct cell *next;
} NodeT;

NodeT *BucketTable[B] ;


void initializeTable(){
    for (int i = 0; i < B; i++)
        BucketTable[i] = NULL;
}

NodeT* createCell(char *name,NodeT *p){
    if(p){
    strcpy(p->key,name);
    p->next=NULL;
    }
    return p;
}

NodeT* findName(char *name){
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    int h=f(p->key);
    p=BucketTable[h];
    while (p != NULL){
    if (strcmp(name, p->key) == 0)
    {
        return p;}
    p = p->next;
    }
    return NULL;
}

void insertName(char *name){
    NodeT *p = (NodeT *) malloc(sizeof(NodeT));
    p = createCell(name,p);
    int h = f(name);
    printf("\n%s is %d\n",name,h);
    if (BucketTable[h] == NULL) {
        //empty slot in HT
        BucketTable[h] = p;
        p->next = NULL;
    } else {//non-empty
        NodeT *ptr = findName(name);
        while (ptr->next != NULL && strcmp(ptr->key, p->key) != 0) {
            ptr = ptr->next;
        }
        ptr->next = p;
        p->next = NULL;
    }
}

void deleteName(char *name){
    //NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    //p=createCell(name, p);
    printf("heeeei");
    NodeT *previousName=BucketTable[f(name)];
    NodeT *currentName=BucketTable[f(name)];
    while(currentName){
    previousName->next = currentName->next;
    free(currentName);
    currentName = previousName->next;
    }
}
void showNode(NodeT *p){
    printf("%s/n",p->key);
    p=p->next;
}
void listHT() {
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    for (int i = 0; i < B; i++)
    if (BucketTable[ i ] != NULL) {
    printf("Bucket for hash value %d:\n", i);
    p =BucketTable[ i ];
    while (p != NULL)
    {
            showNode(p);
    p = p->next; }
        
}
}
int main() {
    FILE *f = fopen("input.txt", "r");
    initializeTable();
    char *instruction = (char *) malloc(sizeof(char) * 25);
    while (fgets(instruction, 25, f)) {
        if (instruction[0] == 'i') {
            insertName(instruction+1);
        } else if (instruction[0] == 'd') {
            deleteName(instruction+1);
        } else if (instruction[0] == 'l') {
            listHT();
        }

    }
    return 0;
}
