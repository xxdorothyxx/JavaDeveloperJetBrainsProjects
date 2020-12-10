/**
 * @author Doroteea Sandor
 * @group 30423
 *
 * You are required to implement correctly and efficiently the ​insert a​ nd ​search ​operations in a hash table using​ open
 * addressing​ and ​quadratic probing​. You may find relevant information and pseudo-code in your course notes, or in the
 * book, in section ​11.4 Open addressing​.
 *
 * COMPLEXITY:
 *
 * The search and INSERT function have the complexity O(1) for the best and average case
 * and the complexity O(n) for the worst case.
 *
 * The worst case happens when all the values would end up in the same cell.
 * Best case is when we assign each key to a unique cell from the first try.
 * For the average case however is better to use quadric probing than lineas as is it easier to find the value.
 * However it is the same for best case as we get the right one from the first try and fot the worst we still have to
 * go through them all.
 *
 */

#include <iostream>
#include <fstream>
#include <ctime>

#define c1 3
#define c2 7

using namespace std;

ifstream f("in.txt");
ofstream g("out.csv");

typedef struct{
    int id;
    char name[30];
} Entry;

int N=9973; //the size of the hash table
int accessedCells=0;


int h(int k,int i,int N){ //hash function
    return (k%N+c1*i+c2*i*i) % N;
}

void initialize(Entry hashTable[],int N){ //function to init the hashTable
    for(int i=0; i < N; i++){
        hashTable[i].id=-1; //init all the id with -1
    }


}

int insertHash(Entry hashTable[],int k,int N,char name[30]){ //function to insert values into hashTable
    int i=0,j;
    do{
        j=h(k, i, N); //we init j w. the value of the hash function
        if(hashTable[j].id==-1){ //is the cell is empty
            hashTable[j].id=k;//we assign the id
            strcpy(hashTable[j].name,name);
            return j; //and return the position where we inserted the value
        }
        else{
            i++; //otherwise we increase i to obtain a new result after the hash fct hoping that it'll be an empty cell
        }
    }while(i != N); //as long as there are empty cells in the hash table
    cout<<"hash table overflow";
    return -1;
}

int searchHash(Entry hashTable[],int k,int N){ //function to search values in the hash Table
    int i=0,j;
    do{
        accessedCells++; //increment the number of the accessed cells
        j=h(k, i, N); //hash function to obtain the id for the value
        if(hashTable[j].id==k){  //we check if the id corresp to the value we search
            return j; //if yes we return the pos where we found it
        }
        else{
            i++; //we increment to obtain another id
        }
    }while(hashTable[j].id!=-1 && i != N); //as long as the cell is not empty and we didn't go through all the cells
    return -1; //if we didn't find the value we return -1
}

void demo(Entry hashTable[]){ //demo on small input
    int n=20;
    initialize(hashTable,n);
    int i,found=0;
    int arrayToInsert[10]={1,2,3,5,7,50,23,35,37,78};
    char nameToInsert[10][30]={"a","b","c","d","e","f","lll","h","i","j"};
    int arrayToFind[4]={7,78,31,51};
    for(i=0;i<10;i++){
        insertHash(hashTable,arrayToInsert[i], n,nameToInsert[i]);
    }
    for(i=0;i<4;i++){
        int poz=searchHash(hashTable,arrayToFind[i],n);
        if(poz!=-1){
            cout<<hashTable[poz].name<<endl;
            found++;
        }
        else{
            cout<<"not found"<<endl;
        }
    }
    cout<<"We found "<<found<<" element(s)";
}

void fillRandomArray(int a[],int size,int up){
    for(int i=0;i<size;i++){
        a[i]=rand();
    }
}

int main() {
    Entry hashTable[N];
    demo(hashTable);
//    time_t secondsFromEpoch=time(NULL);
//    srand(secondsFromEpoch);
//    int nr_teste;
//    double avEffortFound=0,maxEffortFound=0,avEffortNotFound=0,maxEffortNotFound=0;
//    g<<"alpha,avEffortFound,maxEffortFound,avEffortNotFound,maxEffortNotFound"<<endl;
//    double alpha[5]={0.8, 0.85, 0.9, 0.95, 0.99};
//    for(int a=0;a<5;a++){
//        avEffortFound=0;
//        avEffortNotFound=0;
//        for(nr_teste=0;nr_teste<5;nr_teste++) {
//            int n = alpha[a] * N;
//            initialize(hashTable, N);
//            int array[n + 1500];
//            fillRandomArray(array, n + 1500, 50000);
//            for (int i = 0; i < n; i++) { //we insert n values into the hash table
//                insertHash(hashTable, array[i], N,"HarryPotter");
//            }
//            for (int i = n; i < n + 1500; i++) { //we know that these 1500 values will not be in the hash table because we didn't insert them
//                accessedCells = 0;
//                searchHash(hashTable, array[i], N);
//                if (accessedCells > maxEffortNotFound) { //if we access more cells to find a value than the last maximum of searched cells
//                    maxEffortNotFound = accessedCells; //we set it as max
//                }
//                avEffortNotFound += accessedCells;
//            }
//            for (int j = 0; j < 1500; j++) { //we know that these 1500 values are found because we introduced them into the hash
//                int k = rand() % n;
//                accessedCells = 0;
//                searchHash(hashTable, array[k], N); //
//                if (accessedCells > maxEffortFound) {
//                    maxEffortFound = accessedCells;
//                }
//                avEffortFound += accessedCells;
//            }
//        }
//        avEffortFound/=5;
//        avEffortNotFound/=5;
//        g<<alpha[a]<<","<<avEffortFound/1500<<","<<maxEffortFound<<","<<avEffortNotFound/1500<<","<<maxEffortNotFound<<endl;
//    }
    return 0;
}
