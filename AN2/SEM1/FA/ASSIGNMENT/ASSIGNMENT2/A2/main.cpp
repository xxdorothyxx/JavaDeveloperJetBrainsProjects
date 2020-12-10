/*
 * @author Doroteea Sandor
 * @group 30423
 *
 * Problem's specificatons : You are required to implement c​orrectly and e​fficiently
 * two methods for building a heap, namely the b​ottom­up and the t​op­down strategies. Additionally, you have to implement heapsort.
 *
 * COMPLEXITY :
 *  ->for BOTTOM-UP approach : the complexity is O(n) based on what can be observed from
 *  the graphs & computations of the results of the operations.
 *  ->for TOP-DOWN approach : the complexity is O(n*log(n)) because we heapify n/2 leaves which means that we go through the the heapify
 *  of complexity log(n) (which is the height of the binary tree) for n nodes hence the complexity of this method becomes O(n*log(n))
 *
 * EFFICENCY:
 * ->average case : We can see from the complexity and from the graphs for operations
 * that for the average case the most efficient algorithm is the bottom up approach as it's complexity is
 * ->worst case : The most efficient one by far is the  bottom up approach as seen per graphs
 *
 * ADVANTAGES:
 * ->bottomup : it's the fastest of the two and its time complexity is much lower in both average and worst case
 * */

#include <iostream>
#include <fstream>

using namespace std;

ifstream f("in.txt");
ofstream g("worstOut.csv");

int operationsBottomUp=0; //number of operations for bottom up
int operationsTopDown=0;  //number of operations for top down

void heapify(int *array,int n,int i){
int l=2*i+1;  //left child of array[i] has the index 2*i+1
int r=2*i+2;   //right child of array[i] has the index 2*i+2 (next one in the array after the left child)
int greatestAlive = i; // we set the largest element on the parent's index
operationsBottomUp+=2; // we increment the number of operations with 2 because we'll make 2 comparisons with its 2 children below
    if (l < n && array[l] > array[i]) // we check to see if the current index is smaller than the biggest one
        greatestAlive = l;// if yes then we set the largest element as the left child
    if (r < n && array[r] > array[greatestAlive])
        greatestAlive = r;// if yes then we set the largest element as the right child
    if (greatestAlive != i)
    {
        std :: swap(array[i], array[greatestAlive]);// we swap the child and the parent if one child is bigger than the largest element now set as a parent
        operationsBottomUp+=3; // we increment the number of operations with 3 because we make 3 assignments
        heapify(array, n, greatestAlive); // we call the function recursively for the largest found element to make sure that the greatestAlive is larger than its descentants
    }
}

void HeapTopDown(int *array,int i){

    while(i>0 && array[i/2] < array[i]){ //if the parent is lesser than its child
        operationsTopDown++; //we increment the oprations(comparison)
        std :: swap(array[i],array[i/2]); // we swap them to make sure that the child is greater than its parent
        operationsTopDown += 3; //we increment the op with 3 from the swap
        i=i/2; //we move on to the next parent
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>0; i--)
    {
        std :: swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void buildHeapBottomUp(int arr[], int n)
{
    operationsBottomUp=0; //we initiate the number of operations w. 0 for each array
    int startIdx = (n / 2) - 1; //
    for (int i = startIdx; i >= 0; i--) { //we begin with the parent of the biggest index
        heapify(arr, n, i); //we apply heapify on every parent of the heap
    }
    for(int i=0;i<n;i++){   //we print the heap on the console
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    g<<operationsBottomUp<<","; //we print in the output file the number of the operation made
}

void buildHeapTopDown(int arr[], int n)
{
    operationsTopDown=0; //we initiate the number of operations w. 0 for each array
    for (int i = 2; i <= n; i++) { //we begin from the right child
        HeapTopDown(arr,i);
    }
    for(int i=0;i<n;i++){ // we print the array on the console
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    g<<operationsTopDown<<endl; // we print the number of operations in the output file
}


void printHeap(int arr[], int n) {//function to print a heap
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void correctnessOfHeapSort(int *array,int size){ //we test here the correctness of the heap sort on a small sized input from a file in.txt and print the sorted array on the console
    cout<<"Array sorted with heap sort is :"<<endl;
    heapSort(array,size); //call heap sort function
    printHeap(array,size);
}

void correctnessOfBottomUp(int *array,int size){ // we test here the correctness of the bottom up on a small sized input from a file in.txt and print the sorted array on the console
    cout<<"Array representation of Bottom Up heap is:"<<endl;
    buildHeapBottomUp(array,size); //call buid bottom up function
}

void correctnessofTopDown(int *array,int size){ // we test here the correctness of the top down on a small sized input from a file in.txt and print the sorted array on the console
    cout<<"Array representation of Top Down heap is:"<<endl;
    buildHeapTopDown(array,size); //call build top down function
}

int main() {
    int size,i;
    f>>size;
    int *array = (int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        f>>array[i];
    }
    //correctnessOfHeapSort(array,size);
    //correctnessOfBottomUp(array,size);
    //correctnessofTopDown(array,size);
    int *v1,*v2,nr_teste,*v3,*v4;
    time_t secondsFromEpoch=time(NULL);
    srand(secondsFromEpoch);
    nr_teste=5;
    g<<"k,operations_bottom,operations_topDown"<<endl;
    while(nr_teste) {
        for (int n = 100; n < 10000; n += 100) {
            v1=(int*)malloc(sizeof(int)*n);
            v2=(int*)malloc(sizeof(int)*n);
            v3=(int*)malloc(sizeof(int)*n); //worstCase input
            v4=(int*)malloc(sizeof(int)*n);//worstCase input
            for (int i = 0; i < n; i++) {
                v1[i] = rand() %INT_MAX;
                v2[i] = v1[i];
                v3[i]=i; // the input for the worst case is an array sorted and with distinct elements so we'll just take the array with elem equal to its index
                v4[i]=i; //we have the same ip sequence for both approaches
            }
            g << n << ",";
            buildHeapBottomUp(v1,n); // average case for Bottom Up
            buildHeapTopDown(v2,n);  // average case for Top down

            //buildHeapBottomUp(v3,n); // worst case for Bottom Up
            //buildHeapTopDown(v4,n); //worst case for Top down

        }
        nr_teste--;
}
return 0;
}
