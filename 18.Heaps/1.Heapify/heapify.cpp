#include<iostream>
using namespace std;

/*
    -> Heapify a given index.
*/

class Heap{
    public:
        int *arr;
        int size;
        int capacity;

        Heap(int capacity){
            this -> arr = new int[capacity];
            this -> capacity = capacity;
            this -> size = 0;                       // size = current no of element in heap
        }

        // max heap
        void insert(int val){
            if(size == capacity){
                cout << "Heap overflow" << endl;
                return;
            }

            ++size;
            int index = size;
            arr[index] = val;


            // take the val to its rightful position - heapify
            while(index > 1){
                int parentIndex = index / 2;
                // max heap
                if(arr[index] > arr[parentIndex]){
                    swap(arr[index], arr[parentIndex]);
                    index = parentIndex;
                }
                else
                    break;
            }
        }  

        int deleteHeap(){
            int answer = arr[1];

            // repalcement
            arr[1] = arr[size];

            // last element to be deleted from original position
            size--;

            int index = 1;
            while(index < size){
                int leftIndex = 2 * index;
                int rightIndex = 2 * index + 1;

                // find out the largest
                int indexOfLargest = index;
                // check left child
                if(leftIndex <= size && arr[indexOfLargest] < arr[leftIndex]){
                    indexOfLargest = leftIndex;
                }
                if(rightIndex <= size && arr[indexOfLargest] < arr[rightIndex]){
                    indexOfLargest = rightIndex;
                }

                // no change
                if(index == indexOfLargest)
                    break;
                else{
                    swap(arr[index], arr[indexOfLargest]);
                    index = indexOfLargest;
                }
            }
            return answer;
        }

        void printHeap(){
            for(int i = 1;i <= size; i++)
                cout << arr[i] << " ";
        }
};


void heapify(int *arr, int n, int index){
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestIndex = index;
 
    // get max of these 3
    if(leftIndex <= n && arr[leftIndex] > arr[largestIndex])
        largestIndex = leftIndex;
    if(rightIndex <= n && arr[rightIndex] > arr[largestIndex])
        largestIndex = rightIndex;
    

    // after these 2 conditions, largestIndex will be pointing towards largest element among 3
    if(index != largestIndex){
        swap(arr[index], arr[largestIndex]);
        // recursive call
        index = largestIndex;
        heapify(arr, n ,index);
    }
}

int main(){

    return 0;
}