#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct nodee{

    struct nodee *left,*right;
    int key;
}NodeT;

NodeT *createNode(int key){
    NodeT *node=(NodeT*)malloc(sizeof(NodeT));
    node->left=NULL;
    node->right=NULL;
    node->key=key;
    return node;
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
NodeT *rotateLeft(NodeT *node){
    NodeT *y = node->right;
    NodeT *z = y->left;
    y->left = node;
    node->right =z;
    return y;
}

NodeT *rotateRight(NodeT *node){
   NodeT *y = node->left;
    NodeT *z = y->right;
    y->right = node;
    node->left =z;
    return y;

}

int findTheBalance(NodeT *root){
    int balance;
    balance=heightOfTheTree(root->left)-heightOfTheTree(root->right);
    return balance;
}

NodeT *AVLfindBalance(NodeT *root) {
    int balance = findTheBalance(root);
    if (balance > 1 && root->left != NULL) {
        if (findTheBalance(root->left) == 1) {
            root = rotateRight(root);
            return root;
        }
        if (findTheBalance(root->left) == -1) {
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
            return root;
        }
    }
    printf("thi is %d\n", balance);
    if (balance < -1 && root->right != NULL) {
        if (findTheBalance(root->right) == -1) {
            root = rotateLeft(root);
            return root;
        }
        if (findTheBalance(root->right) == 1) {
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
            return root;
        }
    }
}
NodeT *insert(NodeT *node,int key) {
        if (node == NULL){
           node = createNode(key);
           return node;
        }
        if (key < node->key)
            node->left  = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;
        int balance = findTheBalance(node);
        if (balance > 1 ){
            if(key < node->left->key) {
                return rotateRight(node);
            }
            if(key > node->left->key){
                node->left =  rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        if (balance < -1 ){
            if(key > node->right->key){
                return rotateLeft(node);
            }
            if (key < node->right->key)
            {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }
        return node;
    }

void prettyPrint(NodeT *currentRoot,int level){
    if(currentRoot != NULL){

        for(int i=0;i<level;i++){
            printf(" ");
        }
        printf(" %d",currentRoot->key);
        prettyPrint(currentRoot->left,level+1);
        prettyPrint(currentRoot->right,level+1);

    }
}
NodeT *root=NULL;
int main() {
    int nrOfTheElements;
    printf("The number of nodes is: ");
    scanf("%d",&nrOfTheElements);
    for(int i=0;i<nrOfTheElements;i++){
        printf("\nInsert new node : ");
        int x;
        scanf("%d",&x);
        root=insert(root,x);
    }
    prettyPrint(root,0);
    return 0;
}