/**
 * @author Doroteea Sandor
 * @group 30423
 *
 * You are required to implement correctly and efficiently the ​insert a​ nd ​search ​operations in a hash table using​ open
 * addressing​ and ​quadratic probing​. You may find relevant information and pseudo-code in your course notes, or in the
 * book, in section ​11.4 Open addressing​.
 *
 * Interpretarea personală despre complexitate (timp și spațiu), despre cazurile de testare (favorabil,
 * mediu-statistic si nefavorabil) ex: Metoda X are complexitatea Y in cazul Z pentru ca ..
 */

#include <iostream>
#include <fstream>
#include <ctime>

#define c1 3
#define c2 7

using namespace std;

ifstream f("in.txt");
ofstream g("out.csv");

/*typedef struct{
    int id;
    char name[30];
} Entry;*/ //going to figure how to use this

int N=9973; //the size of the hash table
int accessedCells=0;

int h(int k,int i,int N){
    return (k%N+c1*i+c2*i*i) % N;
}

void initialize(int hashTable[],int N){
    for(int i=0; i < N; i++){
        hashTable[i]=-1;
    }
}

int insertHash(int hashTable[],int k,int N){
    int i=0,j;
    do{
        j=h(k, i, N);
        if(hashTable[j]==-1){
            hashTable[j]=k;
            return j;
        }
        else{
            i++;
        }
    }while(i != N);
    cout<<"hash table overflow";
    return -1;
}

int searchHash(int hashTable[],int k,int N){
    int i=0,j;
    do{
        accessedCells++;
        j=h(k, i, N);
        if(hashTable[j]==k){
            return j;
        }
        else{
            i++;
        }
    }while(hashTable[j]!=-1 && i != N);
    return -1;
}

void demo(int hashTable[]){
    int n=20;
    initialize(hashTable,n);
    int i,found=0;
    int arrayToInsert[10]={1,2,3,5,7,50,20,35,37,78};
    int arrayToFind[4]={1,2,4,6};
    for(i=0;i<10;i++){
        insertHash(hashTable, arrayToInsert[i], n);
    }
    for(i=0;i<4;i++){
        if(searchHash(hashTable,arrayToFind[i],n)!=-1){
            found++;
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
    int hashTable[N];
    //demo(hashTable);
    time_t secondsFromEpoch=time(NULL);
    srand(secondsFromEpoch);
    int nr_teste;
    double avEffortFound=0,maxEffortFound=0,avEffortNotFound=0,maxEffortNotFound=0;
    g<<"alpha,avEffortFound,maxEffortFound,avEffortNotFound,maxEffortNotFound"<<endl;
    double alpha[5]={0.8, 0.85, 0.9, 0.95, 0.99};
    for(int a=0;a<5;a++){
         avEffortFound=0;
         avEffortNotFound=0;
       for(nr_teste=0;nr_teste<5;nr_teste++) {
           int n = alpha[a] * N;
           initialize(hashTable, N);
           int array[n + 1500];
           fillRandomArray(array, n + 1500, 50000);
           for (int i = 0; i < n; i++) {
               insertHash(hashTable, array[i], N);
           }
           for (int i = n; i < n + 1500; i++) {
               accessedCells = 0;
               searchHash(hashTable, array[i], N);
               if (accessedCells > maxEffortNotFound) {
                   maxEffortNotFound = accessedCells;
               }
               avEffortNotFound += accessedCells;
           }
           for (int j = 0; j < 1500; j++) {
               int k = rand() % n;
               accessedCells = 0;
               searchHash(hashTable, array[k], N);
               if (accessedCells > maxEffortFound) {
                   maxEffortFound = accessedCells;
               }
               avEffortFound += accessedCells;
           }
       }
            avEffortFound/=5;
            avEffortNotFound/=5;
            g<<alpha[a]<<","<<avEffortFound/1500<<","<<maxEffortFound<<","<<avEffortNotFound/1500<<","<<maxEffortNotFound<<endl;
    }
return 0;
}
