#include <iostream>
#include <fstream>

using namespace std;

ifstream f("in.txt");

void maxHeapify(int *array,int i,int n){
int l=2*i-1;
int r=2*i+2;
int greatestAlive = i;
    if (l < n && array[l] > array[i])
        greatestAlive = l;
    if (r < n && array[r] > array[greatestAlive])
        greatestAlive = r;
    if (greatestAlive != i)
    {
        std :: swap(array[i], array[greatestAlive]);
        maxHeapify(array, greatestAlive, n);
    }

}
void buildHeap(int *array,int n){
    int start_index = n;
    for(int i=start_index/2;i>=0;i--){
        maxHeapify(array,i,n);
    }

}
void printHeap(int arr[], int n)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main() {
    int n;
    f>>n;
    int *array = (int*)malloc(sizeof(int)*n);
    int i;
    for(i=0;i<n;i++){
        f>>array[i];
    }
    buildHeap(array,n);
    printHeap(array,n);
return 0;
}
