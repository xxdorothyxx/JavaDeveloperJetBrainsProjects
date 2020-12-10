/**
 * @author Doroteea Sandor
 * @group 30423
 *
 * You are required to implement correctly and efficiently an O(nlogk) method for merging k
sorted sequences, where n is the total number of elements. (Hint: use a heap, see seminar no. 2
notes).
 *
 * COMPLEXITY:
 * The complexity of the this algorithm is O(n*logk) is logk for the heapify process
 * and this happens n times for building the heap since there are n elements in total
 * so everytime an element is inserted in the lists we make heapify min and take the
 * root from the heap as it is the smallest value and it needs to be inserted to the
 * final linked list so that the final list is sorted in an ascending order.
 *
 * GRAPHS :
 * ->n vary : we can see from the graphs that the operations form a linear function
 * ->k vary : we can see from the graph that the operations form a log function
 */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

ifstream f("in.txt");
ofstream g("Kout.csv");

int operations=0;

typedef struct node{
    int key;
    struct node *next;
} NodeT;

typedef struct{ //structure for a list with first and last node
    NodeT* first;
    NodeT* last;
} List;

List *l; //the final list

void printList(List* list){ //function to print a list
    NodeT *currentNode=list->first;
    while (currentNode != NULL) {
        cout<<currentNode->key<<" ";
        currentNode = currentNode->next;
    }
    cout<<endl;
}

void insert_last(List *list, int givenKey) //function to add an element toa list
{
    NodeT* currentNode= (NodeT*)malloc(sizeof(NodeT));
    currentNode->key = givenKey;
    currentNode->next = NULL;
    operations++;
    if (list->first == NULL){ //if the list is empty we create the first node
        operations+=2;
        list->first = currentNode;
        list->last =currentNode;
    }
    else //if the list is not than we just insert another node at the end of the list
    {
        operations+=2;
        list->last->next = currentNode;
        list->last=currentNode;
    }
}

void heapifyMin(List* list[], int i, int size)
{
    int smallest = i; // Initialize smallest as root
    int l = 2 * i + 1;
      int r = 2 * i + 2;
      operations++;
      if (l < size && list[l]->first->key < list[smallest]->first->key) { //if the left child is smaller we reset it to be the smallest
          smallest = l;
      }
      operations++;
      if (r < size && list[r]->first->key < list[smallest]->first->key){ //if the right child is smaller we reset it to be the smallest
          smallest=r;
      }
      if(smallest!=i){
          NodeT *aux=list[i]->first;
          list[i]->first=list[smallest]->first;
          list[smallest]->first=aux;
          operations+=3;
          heapifyMin(list, smallest, size);
      }
  }

List* initList(List *l){ //function to initialize list
    l = (List*) malloc(sizeof(List));
    //l->x=0;
    l->first =NULL;
    l->last =NULL;
    return l;
}

void builtBottomUp(List **a, int size){
    for(int i = size / 2; i >= 0; i--)
        heapifyMin(a, i, size);
}

void sortArray(int *arr, int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
         std :: swap(arr[min_idx], arr[i]);
    }
}
void fillRandomArray(int *array,int n){
    for(int i=0;i<n;i++){
        array[i]=rand()%1000;
    }
    sortArray(array,n);
}

List* createList (int size){ //function to create a list from an array
    int* v = (int*)malloc( sizeof(int)*size);
    List* list= initList(list);
    fillRandomArray(v, size);
    for (int i=0; i < size; i++){
        insert_last(list, v[i]);
    }
    return list;
}

void makeLists(List* list[], int size, int k){ //function to create K lists
    for( int i=0; i<k; i++){
        list[i] = createList(size);
    }
}

List* kWayMerge(List* list[], int k)
{
    l=initList(l);
    builtBottomUp(list, k); //create a min heap
    while(k){
        operations++;
        NodeT *aux=list[0]->first; //we set the aux as the first node the first list from the k lists
        insert_last(l, aux->key); //we insert the node in our final list
        operations++;
        list[0]->first=list[0]->first->next; //we move to the next elem of the first list
        operations++;
        if(list[0]->first == NULL){ //if we reach the end of the first list
            operations++;
            list[0]=list[k - 1]; // we make all the list at a moment to be the first
            k--;
        }
        heapifyMin(list, 0, k);
    }
}

void demo(){ //small demo on a small sized input
    int k=4;
    int n=20;
    List* list[k];
    int size=n/k;
    makeLists(list, size, k);
    cout<<"The lists are: "<<endl;
    for(int i=0; i<k; i++){
        printList(list[i]);
    }
    kWayMerge(list, k);
    printList(l);
}

void graphicVaryN(){
    int size,n,j,k1=5,k2=10,k3=100;
    List *list1[k1],*list2[k2],*list3[k3];
    int v1[10000],v2[10000],v3[10000];
    //g<<"index,operatinosK=5,operationsK=10,operationsK=100"<<endl;
    for(n=100;n<=10000;n+=100){
        operations=0;
        size=n/k1;
        for(j=0;j<k1;j++){
            makeLists(list1,size,k1);
            kWayMerge(list1,k1);
            //printList(l);
        }
        v1[n/100]=operations/5;
    }
    for(n=100;n<=10000;n+=100){
        operations=0;
        size=n/k2;
        for(j=0;j<k2;j++){
            makeLists(list2,size,k2);
            kWayMerge(list2,k2);
            //printList(l);
        }
        v2[n/100]=operations/10;
    }
    for(n=100;n<=10000;n+=100){
        operations=0;
        size=n/k3;
        for(j=0;j<k3;j++){
            makeLists(list3,size,k3);
            kWayMerge(list3,k3);
            //printList(l);
        }
        v3[n/100]=operations/100;
    }
    for(n=1;n<=100;n++){
        g<<n*100<<","<<v1[n]<<","<<v2[n]<<","<<v3[n]<<endl;
    }
}

void graphicVaryK(){
    int n=10000,size;
    //g<<"k,operationsVaryK"<<endl;
    for(int k=10;k<=500;k+=10){
        operations=0;
        size=n/k;
        List *list[k];
        makeLists(list,size,k);
        kWayMerge(list,k);
        g<<k<<","<<operations<<endl;
    }
}

int main()
{
    demo();
    int nr_tests=5;
    //g<<"index,operatinosK=5,operationsK=10,operationsK=100"<<endl;
    g<<"k,operationsVaryK"<<endl;
    while (nr_tests){
        //graphicVaryN();
        graphicVaryK();
        nr_tests--;
    }
    return 0;
}