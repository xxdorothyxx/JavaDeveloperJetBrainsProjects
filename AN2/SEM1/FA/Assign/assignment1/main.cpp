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
ofstream g("all_out.csv");
ofstream q("best_out.css");


void selectSort(int *v,int n){
    int i,j ,A1=0,C1=0,minIndex;
    for( i=0;i<n-1;i++){
        minIndex=i;
        for( j=i+1;j<n;++j){
            if(v[j]<v[minIndex]){
                minIndex=j;
            }
            C1++;
        }
        int aux =v[i];
        v[i]=v[minIndex];
        v[minIndex]=aux;
        A1+=3;
    }

   // cout<<"The array sorted with Select Sort method is :
    /*for (int pls = 0; pls < n; pls++) {
        cout << v[pls] << " "; //printing the ordered array to check th corectness of the algorithm
    }
    cout<< std::endl;
*/
    g << A1 << "," << C1 << ","<<A1+C1<<","; // printing the number of assignments and comparisons obtainted through the sorting function
}

void bubbleSort(int *v, int n){
    int len = n,flag=1,A2=0,C2=0;
    while(flag && len){
        flag = 0;
        for (int j=0; j < (len -1); j++){
            C2++;
            if (v[j+1] < v[j]){
               int aux = v[j];
               v[j] = v[j + 1];
               v[j+1] = v[j];
                A2+=3;
                flag = 1;
            }
        }
        len--;
    }
    //cout<<"The array sorted with Bubble Sort method is :"<<endl;
    /*for(int i=0;i<n;i++){
        cout<<v[i]<<",";
    }
    cout<<endl;*/
    g<<A2<<","<<C2<<","<<A2+C2<<",";
}
int C3=0;
int binarySearch(int *array, int element, int lft, int high)
{
    int middle = (lft + high)/2;
    if (high <= lft){
        C3++;
        if (element > array[lft])
            return (lft + 1);
        return lft;
    }
    C3++;
    if(array[middle]==element)
        return middle+1;
    C3++;
    if(element > array[middle]){
        return binarySearch(array, element, middle+1, high);

    }
    return binarySearch(array, element, lft, middle-1);
}

void binaryInsertionSort(int *array, int n)
{
    int position, element, A3=0;
    for (int i = 1; i < n; ++i){
        int j = i - 1;
        A3++;
        element = array[i];
        // find location where selected sould be inseretd
        position = binarySearch(array, element, 0, j);
        // Move all elements after location to create space
        while ( j >= position)
        {
            A3++;
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = element;
        A3++;
    }
    //std::cout<<"The array sorted with Insert Sort method is :"<<std::endl;
   for(int i=0;i<n;i++){
        std::cout<<array[i]<<",";
    }
    cout<<endl;
    g<<A3<<","<<C3<<","<<A3+C3<<endl ;
}
void corectnessOfSelectSort(){
    int *array = (int*)malloc(sizeof(int)*100); //reading from file in.txt a small-sized array to test-
    for(int k=0;k<5;k++){        // - if the algorithms are correct. The output will appear
        f>>array[k];                                      // - on the console
        cout<<array[k]<<" ";
    }
    selectSort(array,5);        //call the selection sort fct to sort our array
}

void corectnessOfBubbleSort(){
    int *array = (int*)malloc(sizeof(int)*100); //reading from file in.txt a small-sized array to test-
    for(int k=0;k<5;k++){        // - if the algorithms are correct. The output will appear
        f>>array[k];                                      // - on the console
    }
    bubbleSort(array,5);            //call the bubble sort fct to sort our array
}

void corectnessOfBinaryInsertSort(){
    int *array = (int*)malloc(sizeof(int)*100); //reading from file in.txt a small-sized array to test-
    for(int k=0;k<5;k++){        // - if the algorithms are correct. The output will appear
        f>>array[k];                                      // - on the console
    }
    binaryInsertionSort(array,5); //call the bin insert sort fct to sort our array
}

void averageCase(int *v1,int *v2,int *v3,int nr_teste,int n) {
    while(nr_teste) {
        for (int n = 100; n < 10000; n += 100) {
            for (int i = 0; i < n; i++) {
                v1[i] = rand() % INT_MAX;
                v2[i] = v1[i];
                v3[i] = v1[i];
            }
            g << n << ",";
            selectSort(v1, n);
            bubbleSort(v2, n);
            binaryInsertionSort(v3, n);
        }
        nr_teste--;
    }
    }


void bestCase(int *v1,int *v2,int *v3,int nr_teste,int n) {
    while(nr_teste) {
        for (int n = 100; n < 10000; n += 100) {
            for (int i = 0; i < n; i++) {
                v1[i] = rand() % INT_MAX;
                v2[i] = v1[i];
                v3[i] = v1[i];
            }
            for(int k1=0;k1<n-1;k1++){
                for(int k2=k1+1;k2 < n-1;k2++){
                    if(v1[k1]<v1[k2]){

                        int aux = v1[k1];
                        v1[k1]=v1[k2];
                        v1[k2]=v1[k1];

                        /*v2[k1] = v1[k1];
                        v2[k2] = v1[k2];
                        v3[k1] = v1[k1];
                        v3[k2] = v1[k2];*/
                    }
                }
            }
            g << n << ",";
            selectSort(v1, n);
            bubbleSort(v1, n);
            binaryInsertionSort(v1, n);
        }
        nr_teste--;
    }
}

int main() {
    int n,i,*v1,*v2,*v3,nr_teste;
    time_t secondsFromEpoch=time(NULL);
    srand(secondsFromEpoch);
    nr_teste=5;
    //corectnessOfSelectSort();  //to check the correctness of the SelectSort method on a small-sized array from in.txt
    //corectnessOfBubbleSort();  //to check the correctness of the Bubble Sort method on a small-sized array from in.txt
    //corectnessOfBinaryInsertSort(); //to check the correctness of the BinInsertSort method on a small-sized array from in.txt

    v1=(int*)malloc(sizeof(int)*n);
    v2=(int*)malloc(sizeof(int)*n);
    v3=(int*)malloc(sizeof(int)*n);
    g<<"k,assignments_select,comparisons_select,operations_select,assignments_bubble,comparisons_bubble,operations_bubble,assignments_binInsertion,comparisons_binInsertion,operations_binInsertion"<<endl;
    //averageCase(v1,v2,v3,nr_teste,n);
    bestCase(v1,v2,v3,nr_teste,n);
    return 0;
}
