/**
 * @author Doroteea Sandor
 * @group 30243
 *
 * You are required to implement correctly and efficiently the management operations of an order
statistics tree (chapter 14.1 from the book1
).You have to use a balanced, augmented Binary Search Tree. Each node in the tree holds, besides
the necessary information, also the size field (i.e. the size of the sub-tree rooted at the node).
 *
 *COMPLEXITY:
 *
 * ->build tree function:
 * The complexity of the build tree function is O(n) because we have to build a tree of n elements
 * so we have to take each one of the elements , make it a node and place it in the tree.
 *
 * ->select function:
 * Because each recursive call goes down one level =>
 * the total time for OSselect is at worst proportional to the height of the tree.
 * => its height is O(logn), where n is the number of nodes. So the complexity of the select function is O(logn)
 *
 *->delete function:
 * In my opinion, because OSdelete has the same principle with OSselect : it finds the node with the same method,
 *and then it deletes it and returns the new one.
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

ofstream g("attrCompOut.csv");
ofstream o("operations.csv");

typedef struct Node{
    int key;
    int size;
    struct Node *left,*right;
} NodeT;

NodeT *root;

int A=0,C=0; //assign and comparisons

NodeT* createNode( int key, int first, int last)//create new node
{
    NodeT* node =(NodeT*)malloc(sizeof(NodeT));
    A+=4;
    node->key = key;//set the key
    node->size=last-first+1;//set its size
    node->left=NULL;
    node->right=NULL;
    return node;

}
NodeT *BUILD_TREE(int array[],int first,int last){//fct to build the tree
    C++;
if(first > last){ //if there isn't another node to insert
    return NULL;
}
else{
    A++;
    int middle=(first+last)/2; //we find the middle of the
    NodeT* newNode=createNode(array[middle],first,last);
    newNode->left=BUILD_TREE(array,first,middle-1);
    newNode->right=BUILD_TREE(array,middle+1,last);
    return newNode;
}
}

NodeT *OSselect(NodeT *node,int i){ //we select the i-th smallest element
    int r=1; // r represents the rank of the node
    C++;
    if(node->left!=NULL){
        A++;
       r=node->left->size+1; //r becomes the number of nodes before our node in the inorder traversal
    }
    C+=2;
    if(i==r){//the node is actually the i-th smallest element
        return node; //so we return it
    }
    else if(i<r){// the i-th smallest element is in the left subtree of the node
        return OSselect(node->left,i);
    }
    else{ //the i-th smallest element is in the right subtree of the node
        return OSselect(node->right,i-r); //since r is the nr nodes in front of our node before the node's right subtree
        //=> we need to find the i-r-th smallest elem
    }
}

NodeT *OSdelete(NodeT *node,int i){
    int r=1;// r represents the rank of the node
    C++;
    if(node->left!=NULL) {
        A++;
        r=node->left->size+1;//r becomes the number of nodes before our node in the inorder traversal
    }
    C++;
    if(i==r){ //the node is actually the i-th smallest element
    C+=2; //because we check both the right and the left child
    if(node->left==NULL && node->right==NULL){ //the node we need to delete it is a leaf
        A++;
        node->size--;//the size is decremented with 1 because of the deleted node
        return NULL; //we return null because we have no node to replace it
    }
    C++;
    if(node->right==NULL){//the node we need to delete only has a left child
         A++;
        node->size--;
        return node->left; // the node is replaced with his left child

    }
    C++;
     if(node->left==NULL){//the node we need to delete only has the right child
         A++;
         node->size--;
         return node->right; // the node is replaced with his right child

     }
     //3rd case : the node has two kids (siblings rivalry:))
     NodeT *nextNode=OSselect(node->right,1); //we find successor aka the smallest elem in the right subtree
     A+=3;
     node->key=nextNode->key; //we take its key to replace it
     node->size--; //decrease its size
     node->right=OSdelete(node->right,1); //delete the successor
}
else if(i<r){// the i-th smallest element to delete is in the left subtree of the node
        C++; A++;
        node->size--;
        node->left=OSdelete(node->left,i);} //so we search there to delete it
else{ // the i-th smallest element to delete is in the right subtree of the node
    A++;
    node->size--;
    node->right=OSdelete(node->right,i-r); //since there are r elem before the node in the left subtree => we need to find the i-r-th in the right one to delete
}
return node; //if we couldn't find the elem to delete we just return the root
}

void PrettyPrint(NodeT *root, int level)
{
    int i;
    if(root!=NULL)
    {
        PrettyPrint(root->right, level+1);
        for(i=0; i<level; i++)
            printf(" ");
        printf("%d\n", root->key);
        PrettyPrint(root->left, level+1);
    }
}

void printInorder(NodeT* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

void demo(int n){
A=0;
C=0;
n=11;
int array[11]={1,2,3,4,5,6,7,8,9,10,11};
root=BUILD_TREE(array,0,10);
cout<<"Our tree inorder traversal:"<<endl;
printInorder(root);
cout<<endl;
NodeT*found;
int tryy=3;
while(tryy){
    int e=rand()%n;
    found=OSselect(root,e);
    cout<<"->We found : "<<found->key<<endl;
    root=OSdelete(root,e);
    cout<<"And we deleted the element we previously found:"<<endl;
    printInorder(root);
    cout<<endl;
    tryy--;
    n--;
}
}

void fillArray(int v[], int n){
    for (int i = 0; i <n ; i++){
        v[i] = i +1 ;
    }
}

int main() {
   int n;
   NodeT *found;
   //demo(n);
   int nr_teste=5;
   g<<"k,attributions,comparisons:"<<endl;
   o<<"k,operations"<<endl;
   while(nr_teste){
    for(int n=100;n<10000;n+=100){
        A=0; C=0;
        int v[n];
        fillArray(v,n);
        root=BUILD_TREE(v,0,n);
        for(int i=n;i>1;i--){
            int j=0;
            while(j==0){
                j=rand()%i;
            }
            OSselect(root,j);
            OSdelete(root,j);
        }
        g<<n<<","<<A<<","<<C<<endl;
        o<<n<<","<<A+C<<endl;
    }
    nr_teste--;
   }
 return 0;
}
