#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <search.h>

typedef struct nodee{

    struct nodee *left,*right;
    char key;
}NodeT;

NodeT *createNode(char key){
    NodeT *node=(NodeT*)malloc(sizeof(NodeT));
    node->left=NULL;
    node->right=NULL;
    node->key=key;
    return node;
}

NodeT *insert(NodeT *root,char key){
    NodeT *node=createNode(key);
    if(root==NULL){
        return node;
    }
    NodeT *aux = root;
    for(;;){
        if(key<aux->key) {
            if (aux->left == NULL) {
                aux->left = node;
                return node;
            } else {
                aux = aux->left;
            }
        }
        else if(key>aux->key){
            if(aux->right==NULL){
                aux->right=node;
                return node;
            }
            else{
                aux=aux->right;
            }
        }
        else {
            printf("Key %c already in the tree!",key);
            free(node);
            return NULL;
        }
    }
}

void preorderr(NodeT *currentRoot,int level){
    if(currentRoot != NULL){

        printf("\n");
        for(int i=0;i<level;i++){
            printf(" ");
        }
        printf(" %c",currentRoot->key);
        preorderr(currentRoot->left,level+1);
        preorderr(currentRoot->right,level+1);
    }
}

void postorderr(NodeT *currentRoot,int level){
    if(currentRoot != NULL){
        postorderr(currentRoot->left,level+1);
        postorderr(currentRoot->right,level+1);
        printf("\n");
        for(int i=0;i<level;i++){
            printf(" ");
        }
        printf(" %c",currentRoot->key);
    }
}
void inorderr(NodeT *currentRoot,int level){
    if(currentRoot != NULL){
        inorderr(currentRoot->left,level+1);
        printf("\n");
        for(int i=0;i<level;i++){
            printf(" ");
        }
        printf(" %c",currentRoot->key);

        inorderr(currentRoot->right,level+1);
    }
}
bool find(NodeT *root,char key){
    if(root == NULL){
        return false;
    }
    else{
        if(root->key == key){
            return true;
        }
        else{
            if(key < root->key){
                return find(root->left,key);
            }
            else{
                return find(root->right,key);
            }
        }
    }
}

void findWithPrint(NodeT *root,char key){
    if(find(root,key)){
        printf("Key %c found in tree\n",key);
    } else{
        printf("key %c NOT found in tree\n",key);
    }
}

NodeT *getSuccessor(NodeT *root){
    NodeT *current=root->right;
    while(current != NULL && current->left != NULL){
        current = current->left;
    }
    return current;
}

NodeT *delete(NodeT *root,char key){
    if(root==NULL){
        return root;
    }
    if(key < root->key){
        root->left=delete(root->left,key);
    }
    else if(key > root->key){
        root->right=delete(root->right,key);
    }
    else{
        if(root->left == NULL){
            NodeT *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            NodeT * temp = root->left;
            free(root);
            return temp;
        }
        NodeT *temp = getSuccessor(root);
        root->key = temp->key;
        root->right=delete(root->right,temp->key);
    }
    return root;
}
// when deleting a node with 2 childern : can replace with: \^O^/
// precedesor = rightmost node in left subtree
//succesor = leftmost node in the right subtree

NodeT *getMin(NodeT *current){
        while(current != NULL && current->left != NULL){
            current = current->left;
        }
        return current;
}

NodeT *getMax(NodeT *current){
    while(current != NULL && current->right != NULL){
        current = current->right;
    }
    return current;
}

void yourKingCommands(FILE *f,NodeT *root,char *a){
    while(fgets(a,5,f)){
        if(a[0]=='i'){
            insert(root,a[1]);
        }
        if(a[0]=='d'){
            delete(root,a[1]);
        }
        if(a[0]=='f'){
            findWithPrint(root,a[1]);
        }
        if(a[0]=='t'){
            if(a[1]=='p'){
                preorderr(root,0);
            }
            if(a[1]=='P'){
                postorderr(root,0);
            }
            if(a[1]=='i'){
                inorderr(root,0);
            }
        }
        if(a[0]=='g'){
            if(a[1]=='m'){
                NodeT *t1=getMin(root);
                printf("\nThe minimum is: %c",t1->key);
            }
            if(a[1]=='M')
            {
                NodeT *t2=getMax(root);
                printf("\nThe maximum is : %c",t2->key);
            }
        }
    }
}
int main() {
    FILE *f;
    int ok=0;
    f=fopen("input.txt","r");
    char *a=(char*)malloc(sizeof(char)*5);
    fscanf(f,"%s",a);
    NodeT *root=createNode(a[1]);
    yourKingCommands(f,root,a);
    return 0;
}