/*
 * @author Doroteea Sandor
 * @group 30423
 *
 * Problem's specificatons : You are required to implement correctly and efficiently 3 direct sorting methods
 * (Bubble Sort, Insertion Sort – using either linear or binary insertion and Selection Sort) & discuss
 *
 *  STABILITY : An algorithm it is said to be stable in case
 *  it preserves the relative order of input with equals values in the output.
 *  ->select sort : not stable because when swapping it's possible to change the order of same valued elements
 *  ->bubble sort : stable because we swap two consecutive element if and only if the one ahead has a bigger value
 *  ->binInsert sort : stable because the order is not affected since we move all the element to make space for the needed one
 *
 * COMPLEXITY :
 * ->select sort :
 * Time complexity in all cases is O(N^2) because we have to go through all steps of
 * the nested (for) in average,best or worst case,
 * swaps having place of O(n) times no matter the case
 * ->bubble sort :
 * Bubble sort in average and worst case is O(n^2) since we have to go through all iterations
 * however in the best case the complexity is O(n) because we don't need any swap
 * the flag is 0 so there won't be any next repetition
 * ->bin insertion sort : for worst case we have the compexity of O(nlogn) because we use bin search
 *instead of simple insertion sort( w. O(N^2) complexity) we have to go through all of the
 * inner loop steps however in the best case we have O(n) time complexity
 *
 * EFFICENCY:
 * ->average case : We can see from the complexity and from the graphs for operations
 * that for the average case the most efficient algorithms are selection sort and the
 * bin insertion sort.
 *->best case : It's obvious that the most efficient is bubble sort since in the best case
 * its time complexity is only O(n) wich is much lower the the others.
 * ->worst case : The most efficient one is select sort as seen in the graphs
 * */
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

ifstream f("in.txt");
ofstream g("all_out.csv");

void bestCase(int *v,int n){
    int i,j;
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++){
            if(v[i]>v[j]){
                int aux = v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}

//FUNCTION FOR SELECTION SORT

void selectSort(int *v,int n){
    int i,j ,A1=0,C1=0,minIndex;
    for( i=0;i<n-1;i++){
        minIndex=i;
        //we find the min element with the index bigger than minIndex and then we set minIndex to it
        for( j=i+1;j<n;++j){
            if(v[j]<v[minIndex]){
                minIndex=j;
            }
            C1++; //the comparisons increment
        }
        if(i!=minIndex){
        std :: swap(v[i],v[minIndex]);
           A1+=3; }// we increment the nr. on assignments by 3 because there are 3 such operations needed when we swap the integers
    } // this will repeat until the second last one to be compared with the last one and having all the below elements already sorted
//cout<<"The array sorted with Select Sort method is :"<<endl;
    for(i=0;i<n;i++){ //here we can display the array sorted if we want to
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // here we disply the nr of assignments,comparisons and operation in an output file all_out.csv
    g<<A1<<","<<C1<<","<<A1+C1<<","; // for correctness swap g with cout to see the o/p on the console
}

void bubbleSort(int *v, int n){
    int len = n,flag=1,A2=0,C2=0;
    while(flag && len){ // as long as the the flag is set on 1 and we didn't go through all n iterations
        flag = 0; // we set the flag on 0 at the beginning of each repetition
        for (int j=0; j < (len -1); j++){
            C2++;
            if (v[j+1] < v[j]){ // we check if the neighbour with the bigger index is actually grater than the one with the lesser index
                std::swap(v[j], v[j + 1]);
                A2+=3;
                flag = 1; // we set the flag on 1 because we found at least one pair to swap so it means that the array isn't sorted
            }
        }
        len--; // we decrement the length because the array after len till the end is sorted
    }
    //cout<<"The array sorted with Bubble Sort method is :"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<",";
    }
    cout<<endl;
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
    C3=0;
    int position, element, A3=0;
    for (int i = 1; i < n; ++i){
        int j = i - 1; // the array with index j belongs to the sorted part
        A3++;
        element = array[i];
        // here we search w. bin sort where in the sorted part of the array to insert the elem.
        position = binarySearch(array, element, 0, j);
        // once we find it we create a place for it by moving the rest to their neighbour's place
        while ( j >= position)
        {
            A3++; // increment the assignments
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = element; // we finally set the element at the right place
        A3++; //// increment the assignments
    }
    //std::cout<<"The array sorted with Insert Sort method is :"<<std::endl;
    for(int i=0;i<n;i++){
        std::cout<<array[i]<<",";
    }
    std :: cout<<endl;
    g<<A3<<","<<C3<<","<<A3+C3<<std :: endl ;
}

void correctnessOfSelectSort(){
    int *array = (int*)malloc(sizeof(int)*100); //reading from file in.txt a small-sized array to test-
    for(int k=0;k<5;k++){        // - if the algorithms are correct. The output will appear
        f>>array[k];                                      // - on the console
        cout<<array[k]<<" ";
    }
    selectSort(array,5);
 }

void correctnessOfBubbleSort(){
    int *array = (int*)malloc(sizeof(int)*100); //reading from file in.txt a small-sized array to test-
    for(int k=0;k<5;k++){        // - if the algorithms are correct. The output will appear
        f>>array[k];                                      // - on the console
    }
    bubbleSort(array,5);            //call the bubble sort fct to sort our array
}

void correctnessOfBinaryInsertSort(){
    int *array = (int*)malloc(sizeof(int)*100); //reading from file in.txt a small-sized array to test-
    for(int k=0;k<5;k++){        // - if the algorithms are correct. The output will appear
        f>>array[k];                                      // - on the console
    }
    binaryInsertionSort(array,5); //call the bin insert sort fct to sort our array
}

void worstCase(int *v1,int n){ // here we sort the array in reverse order
    int i,j;
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++){
            if(v1[i]<v1[j]){
                std :: swap(v1[i],v1[j]);
            }
        }
    }
}

void selectWorst(int *v,int n){ // here we have a fct that makes a reverse sorted array to have as the last element the smallest in the array(aka the first one)
  int  aux=v[0],i;
    for( i=1;i<n;i++){
        v[i-1] = v[i];
    }
    v[n-1]=aux;
}

int main() {
    int n,i,*v1,*v2,*v3,nr_teste;
    time_t secondsFromEpoch=time(NULL);
    srand(secondsFromEpoch);
    nr_teste=5;
    //nr_teste = 1; //for best & worst case
    //correctnessOfSelectSort();
    //correctnessOfBubbleSort();
    //correctnessOfBinaryInsertSort();

    g<<"k,assignments_select,comparisons_select,operations_select,assignments_bubble,comparisons_bubble,operations_bubble,assignments_binInsertion,comparisons_binInsertion,operations_binInsertion"<<endl;
    while(nr_teste) {
        for (int n = 100; n < 10000; n += 100) {
            v1=(int*)malloc(sizeof(int)*n);
            v2=(int*)malloc(sizeof(int)*n);
            v3=(int*)malloc(sizeof(int)*n);
            for (int i = 0; i < n; i++) {
                v1[i] = rand() %INT_MAX;
                v2[i] = v1[i];
                v3[i]=v1[i];
            }
            g << n << ",";

            selectSort(v1, n); //functions for AVERAGE case
            bubbleSort(v2,n);
            binaryInsertionSort(v3,n);

            /*bestCase(v1,n);   //functions for BEST case
            selectSort(v1, n);
            bubbleSort(v1,n);
            binaryInsertionSort(v1,n);*/

            /*bestCase(v1,n); //functions for WORST case
            selectWorst(v1,n);
            selectSort(v1,n);
            worstCase(v2,n);
            bubbleSort(v2,n);
            worstCase(v3,n);
            binaryInsertionSort(v3,n);
             */
        }
        nr_teste--;
    }
    return 0;

}
