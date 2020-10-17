#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char id;
    struct node *left,*right;
}NodeT;

typedef struct list{
    char data;
    struct list *previous,*next;
}NodeL;

NodeL *first=NULL,*last=NULL;

NodeT *createBinTree(){
    char *c=malloc(sizeof(char));
    scanf("%s",c);
    if(strcmp(c,"*")==0)
        return NULL;
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->id=c[0];
    p->left=createBinTree();
    p->right=createBinTree();
    return p;
}

void prettyPrint(NodeT *currentRoot,int level){
    if(currentRoot != NULL){
        for(int i=0;i<level;i++){
            printf(" ");
        }
        printf("%c",currentRoot->id);
        prettyPrint(currentRoot->left,level+1);
        prettyPrint(currentRoot->right,level+1);
    }

}
void addLast(char c){

    if(last==NULL){
        last=(NodeL*)malloc(sizeof(NodeL));
        last->data=c;
        last->previous=NULL;
        last->next=NULL;
        first=last;
    }
    else
    {
        NodeL *newNode=(NodeL*)malloc(sizeof(NodeL));
        newNode->data=c;
        newNode->next=NULL;
        newNode->previous=last;
        last->next=newNode;
        last=newNode;
    }
}
void getListFromTree(NodeT *currentNode){
    if(currentNode==NULL)
        addLast('*');
    else {
        addLast(currentNode->id);
        getListFromTree(currentNode->left);
        getListFromTree(currentNode->right);
    }
}

void traverseList(){
    NodeL *currentNode=first;
    printf("\n");
    while(currentNode!=NULL){
        printf("%c ",currentNode->data);
        currentNode=currentNode->next;
    }
    printf("\n");
}
NodeL *theNode;

NodeT *getTreeFromList(){
    if(theNode->data=='*'){
        theNode=theNode->next;
        return NULL;

    }
    else {
        NodeT *p;
        p = (NodeT *) malloc(sizeof(NodeT));
        p->id = theNode->data;
        theNode=theNode->next;
        p->left = getTreeFromList();
        p->right= getTreeFromList();
        return p;
    }
}
int main() {
    NodeT *root=createBinTree();
    //prettyPrint(root,0);
    getListFromTree(root);
    printf("From tree to list :");
    traverseList();
    theNode=first;
    root=getTreeFromList();
    printf("From list to tree :\n");
    prettyPrint(root,0);
    return 0;
}