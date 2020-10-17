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
NodeT *interchangeLeftAndRight(NodeT *givenNode){
    NodeT *interchangedNode=(NodeT*)malloc(sizeof(NodeT));
    interchangedNode->left=givenNode->right;
    interchangedNode->right=givenNode->left;
    interchangedNode->id=givenNode->id;
    return interchangedNode;
}
void preorderr(NodeT *currentRoot,int level,char c){
    if(currentRoot != NULL){
        for(int i=0;i<level;i++){
            printf(" ");
        }
        if(currentRoot->id==c) {
            currentRoot=interchangeLeftAndRight(currentRoot);
        }
        printf("%c",currentRoot->id);
        preorderr(currentRoot->left,level+1,c);
        preorderr(currentRoot->right,level+1,c);
    }
}
void inorderr(NodeT *currentRoot, int level,char c) {
    if(currentRoot!=NULL){
        if(currentRoot->id==c) {
            currentRoot=interchangeLeftAndRight(currentRoot);
        }
        inorderr(currentRoot->left,level+1,c);
        for(int i=0;i<level;i++) {
            printf(" ");
        }
        printf("%c",currentRoot->id);
        inorderr(currentRoot->right,level+1,c);
    }
}
void postorderr(NodeT *currentRoot,int level,char c){
    if(currentRoot!=NULL){
        if(currentRoot->id==c) {
            currentRoot=interchangeLeftAndRight(currentRoot);
        }
        postorderr(currentRoot->left,level+1,c);
        postorderr(currentRoot->right,level+1,c);
        for(int i=0;i<level;i++){
            printf(" ");
        }
        printf("%c",currentRoot->id);
    }
}

NodeT *interchangeTree(NodeT *currentNode,char c){
    if(currentNode!=NULL) {
        if (currentNode->id == c) {
            interchangeLeftAndRight(currentNode);
        }
        interchangeTree(currentNode->left, c);
        interchangeTree(currentNode->right, c);
    }
    return currentNode;
}

int heightOfTheTree(NodeT* currentNode){
    if(currentNode==NULL)
        return 0;
    else {
        int Lheight = heightOfTheTree(currentNode->left);
        int Rheight = heightOfTheTree(currentNode->right);
        if(Rheight>Lheight)
            return Rheight+1;
        return Lheight+1;
    }
}
int nr;
int numberOfLeaves(NodeT* currentNode){
    if(currentNode==NULL)
        return 0;
    if (currentNode->left == NULL && currentNode->right == NULL)
            return 1;
    else
        return numberOfLeaves(currentNode->left)+numberOfLeaves((currentNode->right));
}
int main() {
    NodeT *root=createBinaryTree();
    printf("Root id: %c\n",root->id);
    char *c=malloc(sizeof(char));
    printf("Given Node is : \n");
    scanf("%s",c);
    printf("Interchanged in preorder: ");
    preorderr(root,0,c[0]);
    printf("\nInterchanged in inorder: ");
    inorderr(root,0,c[0]);
    printf("\nInterchanged in postorder: ");
    postorderr(root,0,c[0]);
    int x=heightOfTheTree(root);
    printf("\nThe height of the tree is : %d",x);
    int y=numberOfLeaves(root);
    printf("\nThe number of leaves in this binary tree is : %d",y);
    return 0;
}