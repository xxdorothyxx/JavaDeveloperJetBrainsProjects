
/*
* @author Doroteea Sandor
* @group 30423
*
* Problem's specificatons : You are required to implement c​orrectly and e​fficiently quick sort and quick select.
 * You are also required to analyze the complexity of Q​uicksort a​nd Heapsort (Implemented in Assignment No. 2)
 * comparatively.
 * QUICK SORT VS HEAP SORT :
 *
 *->complexity  & efficency:
 * So between quick sort and heap sort. Both of them have the O(n*logn)complexity for average case
 * but it's way better to use quick sort because it's quicker;). Quick sort does basically almost no useless swap
 * but heapsort does the swap everytime so that's why it's more efficient to use quicksort than heapsort except
 * for the worst case.
 *
 * QUICK SORT :
 *
 * ->best case : the best case for the quick sort is when the input array is already sorted(so that
 * we don't do any useless swaps) and when the pivot is in the middle of the array so that for the first step
 * we have n operations for the big array, then we have n/2 operations for the first half of the array and again n/2
 * op for the 2nd half.Then we have n/4 for every half of half and so on =>COMPLEXITY of best case is O(n*log n)
 *
 * ->worst case : the worst case for the quick sort is when the input array is already sorted so the the pivot will
 * be the last element and also the biggest/smallest one. So the first step will have n operations and then we move
 * the delim line .Next we have n-1 op and so on until we only have 1 operation. Doin' the math =>COMPLEXITY of
 * worst case is O(n*n)
 *
*/

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

ifstream f("in.txt");
ofstream g("averageeOut.csv");

int operationsQuickSort;
int operationsHeapSort;

int partition (int *array, int left, int right)
{
    operationsQuickSort++; //assign
    int pivot = array[right]; // we choose the pivot to be the last element of the array as to be compare every other element with the pivot
    int i = (left - 1); // we set i as a delimitation line : before the delimitation line all the elements
    // are smaller than the pivot
    int j=left; // we set j with the first elem of the (part of) array we want to sort
    while(j <= right - 1){//we to go through all the element of the array we want to sort
        operationsQuickSort++; //comparison
        if (array[j] < pivot){ //we check to see if the current element is smaller that out pivot
            i++; //if we find and element smaller than the pivot  we increment out "delimitation line"
            std :: swap(array[i], array[j]); //and we swap hence the current element that is smaller
            // than the pivot to be below the delimitation line
            operationsQuickSort+=3; //assign
        }
        j++; // we move on to the next element of the array
    }
    std :: swap(array[right], array[i + 1]); //we swap the pivot with the next elem after the delimitatuion line
    operationsQuickSort+=3;//assign
    return (i + 1); // we return the index of the element after the delimitation line
}

void quickSort(int *array, int left, int right)
{
    if (left < right) {
        int pi  = partition(array, left, right); // where the delimitation line is set between the "sorted" part of the array and the rest
        quickSort(array, left, pi - 1); // we sort the array below the delim line with the pivot=last elem below the delim line
        quickSort(array, pi + 1, right); //we sort the array above the delim line with the pivot=last elem of the array
    }
}

void printArray(int arr[], int size){ // print an array
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void makeQuickSort(int *v1,int n){
    //operationsQuickSort=0;
    quickSort(v1,0,n-1);
    printArray(v1,n);
    g<<operationsQuickSort<<",";
}

void heapify(int *array,int n,int i){
    int l=2*i+1;  //left child of array[i] has the index 2*i+1
    int r=2*i+2;   //right child of array[i] has the index 2*i+2 (next one in the array after the left child)
    int greatestAlive = i; // we set the largest element on the parent's index
    operationsHeapSort+=2; // we increment the number of operations with 2 because we'll make 2 comparisons with its 2 children below
    if (l < n && array[l] > array[i]) // we check to see if the current index is smaller than the biggest one
        greatestAlive = l;// if yes then we set the largest element as the left child
    if (r < n && array[r] > array[greatestAlive])
        greatestAlive = r;// if yes then we set the largest element as the right child
    if (greatestAlive != i){
        std :: swap(array[i], array[greatestAlive]);// we swap the child and the parent if one child is bigger than the largest element now set as a parent
        operationsHeapSort+=3; // we increment the number of operations with 3 because we make 3 assignments
        heapify(array, n, greatestAlive); // we call the function recursively for the largest found element to make sure that the greatestAlive is larger than its descentants
    }
}

void heapSort(int *array, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) //we apply heapify to make the array a maxHeap
        heapify(array, n, i);
    for (int i=n-1; i>0; i--) // we want to apply heapify for the array except fot its last element which we'll switch with
        //the first one(and also the max of the array) so that the last element will be the bigest of the array and so
        //on for the the decremented-sized array until we remain with a array with one element
    {
        operationsHeapSort+=3;
        std :: swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void makeHeapSort(int *v2,int n){
    operationsHeapSort=0;
    heapSort(v2,n);
    printArray(v2,n);
    g<<operationsHeapSort<<endl;
}

int quickSelect(int *array, int left, int right, int i){
    if(left == right){ //if there is only one elem left that is our hunted:) one
        return array[left];
    }
    int q=partition(array, left, right); //we set q as the index of the first elem after the delimitation line
    int k= q - left + 1;
    if(i==k){ //if the elem is the pivot
        return array[q];
    }
    else if(i<k){ //if it is lesser than the pivot
        return quickSelect(array, left, q - 1, i);
    }
    else{ //if it is greater than the pivot
        return quickSelect(array, q + 1, right, i - k);
    }
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

void worstCase(int *array,int n){//worst case for quick sort is when the array is already sorted(increasing/decreasing)
    // and the pivot will be the last elem which will be the biggest or the smallest
  sortArray(array,n);
  makeQuickSort(array,n);
  g<<endl;
}

void moveMiddleToPivot(int a[], int left, int right)
{ //funtion to always make the pivot as the middle element
    if(left<right){
        int mid=(left+right)/2;
        moveMiddleToPivot(a, left, mid-1);
        moveMiddleToPivot(a, mid+1, right);
        int aux=a[mid];
        a[mid]=a[right];
        a[right]=aux;
    }
}

void bestCase(int *v4, int n){
    sortArray(v4, n);
    moveMiddleToPivot(v4,0,n-1);
    makeQuickSort(v4,n);
    g<<endl;
}

void correctnessOfQuickSelect(){
    int size,i;
    f>>size;
    int *array = (int*)malloc(sizeof(int)*size);
    for(i=0;i<size;i++){
        f>>array[i];
    }
    int element=quickSelect(array,0,size-1,2);
    cout<<element;
}

void correctnessOfQuickSort(){
    int size,i;
    f>>size;
    int *array = (int*)malloc(sizeof(int)*size);
    for(i=0;i<size;i++){
        f>>array[i];
    }
    quickSort(array,0,size-1);
    for(i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}

int main() {
    //correctnessOfQuickSort(); //on a small sized input from the in.txt file
    correctnessOfQuickSelect(); // on a small sized input from the in.txt file
    /*int *v1,*v2,nr_teste,*v3,*v4;
    time_t secondsFromEpoch=time(NULL);
    srand(secondsFromEpoch);
    nr_teste=5;
    g<<"k,operations_quickSort,operationsHeapSort"<<endl;
    //g<<"k,worstQuickSort"<<endl;
    //g<<"k,bestQuickSort"<<endl;
    while(nr_teste) {
        for (int n = 100; n < 10000; n += 100) {
            operationsQuickSort=0;
            v1=(int*)malloc(sizeof(int)*n);
            v2=(int*)malloc(sizeof(int)*n);
            v3=(int*)malloc(sizeof(int)*n);
            v4=(int*)malloc(sizeof(int)*n);
            for (int i = 0; i < n; i++) {
                v1[i] = rand() ;
                v2[i] = v1[i];
                v3[i]=v1[i];
                v4[i]=v1[i];
               }
            g << n << ",";
            makeQuickSort(v1,n); //averageCase
            makeHeapSort(v2,n); //averageCase

            //worstCase(v3,n); //worstCase
            //bestCase(v4,n); //bestCase

        }
        nr_teste--;
    }*/
    return 0;
}
