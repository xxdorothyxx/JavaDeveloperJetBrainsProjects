/**
* @author Doroteea Sandor
* @group 30423
*
* You are required to implement correctly and efficiently linear time transformations between
three different representations for a multi-way tree.

 DATA STRUCTURES USED :
 ->for the 1st representation or the parent array we use an array of integers.However we'll have a 0 as the elem with index 0 but it'll not affect
 the representations since our array actually starts from the index of 1.
 ->for the 2nd representation also known as the multi-way one we use  an array of structures which is defined by :
 an integer key for its data, an integer nrKids to store the number the kids the node has and an array of the same struct to store all the children of the node.
 ->for the 3rd representation also known as the binary one we use a structure which is defined by : an integer key to store the info, an integer nrKids
 to count how many kids the node has and two pointers of the same struct which represent the first kid of the previous representation and the brother
 of the first kid.

 ADDITIONAL MEMORY :
 ->For MULTY-WAY : I have an array of NodeR2 structures
 because I implemented as a tree of N nodes .
 I also have a pointer of NodeR2 struct which is my root for the 2nd representation;
 in the transformation function I also have 2 such pointers structures where I try to make clear what that elem of array represents : the child/the parent
 to make the code more readable and easier to understand.
 ->For BINARY: I have a root of NodeR3 struct pointer to store the root of the 3rd representation.
 And also i have a newNode of type NodeR3 pointer  to make the
 transformation from R2 to R3 easier.

 COMPLEXITY in my /opinion/:
For 1st Transformation: It's O(n) since I go with a for to all elements of the input array (N times where N is the size of the input).
For 2nd Transformation: It's O(n) because it I reach every node and decide if it is a brother ,a child or root I belive:)
*
*/

#include <iostream>

using namespace std;

typedef struct NodeR2{ //struct for r2(multi-way representation)
    int key;
    int nrKids;
    struct NodeR2 *kids[5]; // we suppose we have max 5 kids
}NodeR2;

NodeR2 *r2[10];
NodeR2 *rootR2=NULL;

typedef struct NodeR3{ //struct for r3(binary representation)
    int key;
    struct NodeR3 *firstKid,*brother;
}NodeR3;

NodeR3 *rootR3=NULL;

void initR2(int n){ //init the 2nd representation
    for(int j=1; j<n; j++){
        r2[j]=(NodeR2*)malloc(sizeof(NodeR2));
        r2[j]->key = j;
        r2[j]->nrKids=0;
        for(int i=1;i<5;i++){ //init all the children with null
            r2[j]->kids[i]=NULL;
        }
    }
}

NodeR2* T1(int r1[], int n){ //Transformation 1 : r1->r2
    initR2(n);
    for(int i=1; i <n; i++){
        if(r1[i] != -1){ //if the parent isn't the root
            NodeR2 *child=r2[i]; //it is a child of another parent
            NodeR2 *parent = r2[r1[i]]; //we find its parent
            parent->kids[parent->nrKids] = child; //and we add it to its kids
            parent->nrKids++; //and then increment its number of kids
        }
        else rootR2=r2[i]; //otherwise it is a root
    }
    return rootR2; //we return the root
}

void prettyPrintR2( NodeR2 *root, int level){ //print the 2nd representation
    if(root!=NULL){ //if it is not null
        int l=level;
        while(l){ //print the spaces of the level
            cout<<" ";
            l--;
        }
        cout<<root->key<<endl; //print its key
        for(int i=0;i<root->nrKids; i++) { //go print its kids
            prettyPrintR2(root->kids[i], level+1);
        }
    }
}

NodeR3* T2(NodeR2* root) { //Transformation 2 : r2->r3
    if (root != NULL) { //if the node exists(original node)
        NodeR3 *newNode = (NodeR3 *) malloc(sizeof(NodeR3));
        newNode->key = root->key;
        if (root->nrKids == 0) { //if it doesn't have kids
            newNode->firstKid = NULL; //first kid is NULL
        } else { //if it has kids
            newNode->firstKid = T2(root->kids[0]); //we get the 1st kid
            NodeR3 *nextNode = newNode->firstKid; //we denote next node as the node's first kid
            for (int i = 1; i <= root->nrKids ; i++) { //go through all of the next node's kids
                nextNode->brother = T2(root->kids[i]); // next node's brother become the original's i-th kid
                nextNode = nextNode->brother; //the next node become its brother
                //until we make all the root's(original node) kids as a list of the first kid/brothers of the fist kid
            }
        }
        return newNode;
    }
    return NULL;
}

void prettyPrintR3(NodeR3* root, int level){ //print the 3rd representation
    if(root != NULL){ //if the node exists
        int l=level;
        while(l){ //printing the spaces of the level
            cout<<" ";
            l--;
        }
        cout<<root->key<<endl; //print the key of the node
        prettyPrintR3(root->firstKid, level + 1); //we go recursively to the first kid of the root on the next level(from the root)
        prettyPrintR3(root->brother, level); //and print its brothers(which are on the same level as the first kid)
    }
}

void demo(int r1[]) {
    cout<<"The parent array is:"<<endl;
    for(int i=1;i<10;i++){
        cout<<r1[i]<<" ";
    }
    rootR2=T1(r1,10);
    cout<<endl<<"The second representation: "<<endl;
    prettyPrintR2(rootR2,0);
    rootR3 = T2(rootR2);
    cout << "The third representation: " << endl;
    prettyPrintR3(rootR3, 0);
}

int validInput(int r1[]){
    int ok=-1;
    for(int i=1;i<10;i++) {
        if (r1[i] == -1 && ok == -1) {
            ok = 1;
        }
    }
        if(ok==-1 || ok>1){
            cout<<"The input is invalid.Please check to have only one root";
            return 0;
    }
    return 1;
}

int main() {
    int r1[10]={0,2,7,5,2,7,7,-1,5,2}; //we have a 0 at the beginning because our array starts at 1
    // index:     1 2 3 4 5 6  7 8 9
    if(validInput(r1)==1){
        demo(r1);
    }

    return 0;
}
