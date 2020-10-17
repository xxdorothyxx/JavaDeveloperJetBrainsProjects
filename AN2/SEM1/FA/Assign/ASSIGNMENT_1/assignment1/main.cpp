/**
 * @author Doroteea Sandor
 * @group 30423
 *
 * Problem's specificatons : You are required to implement correctly and efficiently 3 direct sorting methods
 * (Bubble Sort, Insertion Sort – using either linear or binary insertion and Selection Sort)
 *
 * Interpretarea personală despre complexitate (timp și spațiu) :
 */
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

ifstream f("in.txt");
ofstream g("bubble_out.csv");

void swapping(int a,int b){
    int aux=a;
    a=b;
    b=aux;
}
void selectSort(int *v,int n){
    int i,j,A1=0,C1=0;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            C1++;
            if(v[i]>v[j]){
                A1+=3;
                swapping(v[i],v[j]);
            }
        }
    }
    //cout<<"The array sorted with Select Sort method is :"<<endl;
    for(i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    g<<A1<<","<<C1<<endl;
}
void bubbleSort(int *v, int n){
    int len = n,flag=1,A2=0,C2=0;
    while(flag && len){
        flag = 0;
        for (int j=0; j < (len -1); j++){
            C2++;
            if (v[j+1] < v[j]){
                std::swap(v[j], v[j + 1]);
                A2+=3;
                flag = 1;
            }
        }
        len--;
    }
    //cout<<"The array sorted with Bubble Sort method is :"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<",";
    }
    cout<<endl;
    g<<A2<<","<<C2<<endl;
}

int main() {
    int n,i,*v,nr_teste;
    time_t secondsFromEpoch=time(NULL);
    srand(secondsFromEpoch);
    f>>nr_teste;
    v=(int*)malloc(sizeof(int)*n);
    g<<"k,assignments_bubble,comparisons_bubble"<<endl;
    while(nr_teste) {
        for (int n = 100; n < 10000; n += 100) {
            for (int i = 0; i < n; i++) {
                v[i] = rand() % INT_MAX;
            }
            g << n << ",";
            //selectSort(v, n);
            bubbleSort(v,n);
        }
        nr_teste--;
    }
    return 0;
}
