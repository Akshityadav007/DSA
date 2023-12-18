#include<iostream>
using namespace std;

/*
    -> Heap is a complete binary tree which follows heap properties.
    -> Complete BT is a BT in which all levels are completely except the last level (it may or may not be filled). Here nodes are filled in left to right direction.

    -> Heap property:
        1) Min heap : Parent node will always be smaller than child node.
        2) Max heap : Parent node will always be greater than child node.

    -> Visualization of heap is always like tree, but implementation is using arrays.
    -> In arrays, if child is at 'i', parent will be at 'i / 2.
    -> In arrays, if parent is at 'i', 
        - Left child will be at : 2 * i
        - Right child will be at : 2 * i + 1
        # Note : This is for 1 based indexing.
        # For 0 based indexing,
        - Left child : 2 * i + 1
        - Right child : 2 * i + 2

    -> Heapification - Process when an element goes to claim it's rightful position in a heap.

    -> Deletion - Always root node is deleted in a heap.
                - Swap the root node with the last right most node.
                - Delete the last right most node.
                - Heapify the root node.
    
    # Heap creation = T.C. : O(n)
    # get max/ min = O(1)
    # Delete/insert = O(logn)
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



int main(){
    Heap h(20);

    // insertion
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    cout << "Printing heap: ";
    h.printHeap();
    cout << endl;


    int ans = h.deleteHeap();

    cout << "Answer = " << ans << endl;
    h.printHeap();

    return 0;
}