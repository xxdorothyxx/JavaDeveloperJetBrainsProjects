/**
 * @author Sandor Doroteea
 * @group 30423
 *
 * Specificațiile problemei :You are required to implement correctly and efficiently the base operations for disjoint set
(chapter 21.1 from book ) and the Kruskal’s algorithm (searching for the minimum spanning 1
tree - chapter 23.2) using disjoint sets
 *
 * COMPLEXITY:
 *->makeset : Initializing with make set operation. One makeset takes O(1) time while n makesets take O(n) time
 *
 *->find set : one find has complexity O(1) because we use
 * path compression so we directly return the repres. without considering the recursion.
 *
 * ->union by rank : one link takes O(mlogn)
 * */

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
ofstream g("out.csv");
ofstream h("op.csv");

typedef struct Node{
    int key;
    int rank;
    struct Node *parent;
}NodeT;

typedef struct edge{
    NodeT *src,*dest; //delim the edge
    int weight; //the weight
}Edge;

int A=0,C=0; //assign & comp

NodeT *MAKE_SET(int key){ //here we create a new set
    NodeT *x=(NodeT*)malloc(sizeof(NodeT));
    A+=3;
    x->parent=x;
    x->rank=0;
    x->key=key;
    return x;
}

void LINK(NodeT *x,NodeT *y){
    C++;
    if(x->rank>y->rank){ //if node x has a rank greater than node y
        A++;
        y->parent=x; //node's y parent becomes node x
    }
    else{
        A++;
        x->parent=y; //node's x parent becomes y
        C++;
        if(x->rank == y->rank){ //if their rank is equal
            A++;
            y->rank=y->rank+1; //we increase the node y's rank
        }
    }
}

NodeT* FIND_SET(NodeT *x){ //it returns the representat
    //of the set x belongs to
    C++;
    if(x!=x->parent){//if we didn't reach the representant of the set
        A++;
        x->parent=FIND_SET(x->parent);//we modify the parent of the node each time we didn't find the rep
    }
    return x->parent;
}

void UNION(NodeT *x,NodeT *y){ // unites the two sets of the nodes x and y
    if(FIND_SET(x)!= FIND_SET(y))
        LINK(FIND_SET(x), FIND_SET(y));
}

void demoDisjointSets(){
    int arrayDemo[10]={0,1,2,3,4,5,6,7,8,9};
    NodeT **arrayNodes=(NodeT**)malloc(sizeof(NodeT)*10);
    //we create 10 sets
    for(int i=0;i<10;i++){
        arrayNodes[i]=MAKE_SET(arrayDemo[i]);
        cout<<"node "<<arrayNodes[i]->key<<" belongs to set "<<FIND_SET(arrayNodes[i])->key<<endl;
    }
    //we make 5 unions
    UNION(arrayNodes[0],arrayNodes[5]);
    UNION(arrayNodes[1],arrayNodes[6]);
    UNION(arrayNodes[2],arrayNodes[7]);
    UNION(arrayNodes[3],arrayNodes[8]);
    UNION(arrayNodes[4],arrayNodes[9]);
    //let's check if the parents successfully adopted
    cout<<endl<<"After the union:"<<endl;
    for(int i=0;i<5;i++){
        cout<<arrayNodes[i]->key<<" belongs to set "<<FIND_SET(arrayNodes[i])->key<<endl;
    }
}
Edge *MST;
int nrEdgesMST;

void MSTKruskal(Edge e[],int nrEdges){
    nrEdgesMST=0;
    int i;
    for( i=0;i<nrEdges-1;i++){ //ordering the edges based on their weights
        for( int j=i+1;j<nrEdges;j++){
            if(e[i].weight>e[j].weight){
                Edge temp=e[i];
                e[i]=e[j];
                e[j]=temp;
            }
        }
    }
    MST=(Edge*)malloc(sizeof(Edge)*nrEdges);
    int k=0;//with j we keep indexing the minimum spanning tree
    for(i=0;i<nrEdges;i++){//we go through the edges starting from the smallest one
        if(FIND_SET(e[i].src)!=FIND_SET(e[i].dest)){//we check to see if it'll make a cycle
            MST[nrEdgesMST++]=e[i];//we add it to the min spanning tree
            k++;
            UNION(e[i].src,e[i].dest);
        }
    }
}

void demoKruskal(){
int nrNodes=5;
int nrEdges=7;
int arrayDemo[5]={0,1,2,3,4};
NodeT *arrayNodes[5];
Edge arrayEdges[7];
for(int i=0;i<5;i++){
    arrayNodes[i]=MAKE_SET(arrayDemo[i]);
}
//we add edges to the array of edges
arrayEdges[0].src=arrayNodes[0];
arrayEdges[0].dest=arrayNodes[1];
arrayEdges[0].weight=5;

arrayEdges[1].src=arrayNodes[1];
arrayEdges[1].dest=arrayNodes[2];
arrayEdges[1].weight=9;

arrayEdges[2].src=arrayNodes[2];
arrayEdges[2].dest=arrayNodes[3];
arrayEdges[2].weight=2;

arrayEdges[3].src=arrayNodes[3];
arrayEdges[3].dest=arrayNodes[4];
arrayEdges[3].weight=6;

arrayEdges[4].src=arrayNodes[0];
arrayEdges[4].dest=arrayNodes[3];
arrayEdges[4].weight=8;

arrayEdges[5].src=arrayNodes[1];
arrayEdges[5].dest=arrayNodes[4];
arrayEdges[5].weight=4;

arrayEdges[6].src=arrayNodes[2];
arrayEdges[6].dest=arrayNodes[4];
arrayEdges[6].weight=1;

MSTKruskal(arrayEdges,nrEdges);
cout<<"The has :"<<endl;
for(int i=0; i < nrEdgesMST; i++){
    cout<<"edge "<<MST[i].src->key<<" - "<<MST[i].dest->key<<" of weight : "<<MST[i].weight<<endl;
}
}
int main() {
   //demoDisjointSets();
     demoKruskal();
//    time_t secondsFromEpoch=time(NULL);
//    srand(secondsFromEpoch);
//   g<<"n,attr,comp"<<endl;
//   h<<"n,operations"<<endl;
//   for(int n=100;n<=10000;n+=100){
//    A=0;C=0; //we set the assign and comparisons on 0 for every n
//    int nrNodes=n;
//    int nrEdges=4*n;
//    Edge* arrayEdges=(Edge*)malloc(sizeof(Edge)*nrEdges);
//    NodeT**arrayNodes=(NodeT**)malloc(sizeof(NodeT*)*(nrNodes+1));
//    int i;
//    for(i=0;i<nrNodes;i++){
//        arrayNodes[i]=MAKE_SET(i);
//    }
//    for(i=0;i<nrEdges;i++){
//        arrayEdges[i].src=arrayNodes[(rand()%n)];
//        arrayEdges[i].dest=arrayNodes[(rand()%n)];
//        arrayEdges[i].weight=rand()%(4*n);
//    }
//       MSTKruskal(arrayEdges,nrEdges);
//    cout<<nrEdgesMST<<endl;
//    g<<n<<","<<A<<","<<C<<endl;
//    h<<n<<","<<A+C<<endl;
//  }
    return 0;
}
