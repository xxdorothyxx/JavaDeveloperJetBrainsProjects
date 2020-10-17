#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

typedef struct node{
    char id;
    struct node *left, *right;

}NodeT;


NodeT *createBinaryTree(){
    char *c=malloc(sizeof(char));
    scanf("%s",c);
    if(strcmp(c,"*")==0){
        return NULL;
    }
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->id=c[0];
    p->left=createBinaryTree();
    p->right=createBinaryTree();
    return p;
}

void preorderr(NodeT *currentRoot,int level){
    if(currentRoot != NULL){
        for(int i=0;i<level;i++){
            printf(" ");
        }
        printf("%c",currentRoot->id);
        preorderr(currentRoot->left,level+1);
        preorderr(currentRoot->right,level+1);
    }
}
void inorderr(NodeT *currentRoot, int level) {
    if(currentRoot!=NULL){
    inorderr(currentRoot->left,level+1);
        for(int i=0;i<level;i++) {
            printf(" ");
        }
    printf("%c",currentRoot->id);
    inorderr(currentRoot->right,level+1);
    }
}
void postorderr(NodeT *currentRoot,int level){
    if(currentRoot!=NULL){
     postorderr(currentRoot->left,level+1);
     postorderr(currentRoot->right,level+1);
     for(int i=0;i<level;i++){
         printf(" ");
     }
     printf("%c",currentRoot->id);
    }
}
int main() {
    NodeT *root=createBinaryTree();
    printf("Root id: %c\n",root->id);
    //preorderr(root,0);
    //inorderr(root,0);
    postorderr(root,0);
    return 0;
}
