#include<iostream>
using namespace std;

// Problem || Leetcode : 641
/*
    -> Design your implementation of the circular double-ended queue (deque).
    -> Implement the MyCircularDeque class:
       - MyCircularDeque(int k) Initializes the deque with a maximum size of k.
       - boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
       - boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
       - boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
       - boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
       - int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
       - int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
       - boolean isEmpty() Returns true if the deque is empty, or false otherwise.
       - boolean isFull() Returns true if the deque is full, or false otherwise.
*/


// Solution
/*
    -> Self explainatory
*/

class MyCircularDeque {
public:
    int *arr;
    int size;
    int front;
    int rear;

    MyCircularDeque(int k) {
        arr = new int[k];
        this -> size = k;
        front = -1;
        rear = -1;
    }
    
    bool insertFront(int value) {
        // overflow condition
        if((front == 0 && rear == size - 1) || (rear == front - 1))
            return false;
        
        // 1) empty queue
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = value;
            return true;
        }
        // 2) circular nature
        else if(front == 0 && rear != size - 1){
            front = size - 1;
            arr[front] = value;
            return true;            // insertion successful
        }
        // 2) normal case
        else{
            front--;
            arr[front] = value;
            return true;            // insertion successful
        }

        return false;
    }
    
    bool insertLast(int value) {
         // overflow condition
        if((front == 0 && rear == size - 1) || (rear == front - 1))
            return false;
        
        // 1) empty queue
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = value;
            return true;
            
        }
        // 2) Circular nature
        else if((front != 0 && rear == size - 1)){
            rear = 0;
            arr[rear] = value;  
            return true;            // insertion successful
        }
        // 3) normal case
        else{
            rear++;
            arr[rear] = value;
            return true;            // insertion successful
        }

        return false;
    }
    
    bool deleteFront() {
        // 1) empty list
        if(front == -1 && rear == -1){
            return false;
        }
        // 2) single element
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
            return true;
        }
        // 3) circular nature
        else if(front == size - 1){
            arr[front] = -1;
            front = 0;
            return true;
        }
        // 4) normal
        else{
            arr[front] = -1;
            front++;
            return true;
        }

        return false;
    }
    
    bool deleteLast() {
        // 1) empty list
        if(front == -1 && rear == -1){
            return false;
        }
        // 2) single element
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
            return true;
        }
        // 3) circular nature
        else if(rear == 0){
            arr[rear] = -1;
            rear = size - 1;
            return true;
        }
        // 4) normal
        else{
            arr[rear] = -1;
            rear--;
            return true;
        }

        return false;
    }
    
    int getFront() {
        if(front == -1 && rear == -1)
            return -1;   
        else
            return arr[front];    
    }
    
    int getRear() {
        if(front == -1 && rear == -1)
            return -1;   
        else
            return arr[rear];
    }
    
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
    
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear == front - 1));
    }
};

int main(){


    return 0;
}