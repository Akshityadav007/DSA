#include<iostream>
using namespace std;

/*
    -> In normal queue push is from rear side and pop was from front.

    -> But in deq or doubly ended queue, both operations, push and pop are possible from both sides.
    -> Syntax:
        - deque<int> deque_name;
    
    # Note : Normal deque is useless, so we have added circular nature (circular doubly ended queue).
*/

class deque{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        deque(int val){
            arr = new int[val];
            this -> size = val;
            front = -1;
            rear = -1;
        }

        void push_front(int val){
            // overflow
            if((front == 0 && rear == size - 1) || (rear == front - 1)){
                cout << "Overflow" << endl;
            }
            // empty queue
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[front] = val;
            }
            // circular
            else if(front == 0 && rear != size - 1){
                front = size - 1;
                arr[front] = val;
            }
            else{
                front--;
                arr[front] = val;
            }
        }

        void push_back(int val){     // same as normal queue
            // overflow
            if((front == 0 && rear == size - 1) || (rear == front - 1)){
                cout << "Overflow" << endl;
            }
            // empty case
            else if(front == -1 && rear == -1){
                rear++;
                front++;
                arr[rear] = val;
            }
            // circular nature
            else if(rear == size - 1 && front != 0){
                rear = 0;
                arr[rear] = val;
            }
            // normal flow
            else{
                rear++;
                arr[rear] = val;
            }
        }

        
        void pop_back(){
            // underflow
            if(front == -1 && rear == -1){
                cout << "Underflow!" << endl;
            }
            // single element
            else if(front == rear){
                arr[rear] = -1;
                front = -1;
                rear = -1;
            }
            // circular nature
            else if(rear == 0){
                arr[rear] = -1;
                rear = size - 1;
            }
            else{
                arr[rear] = -1;
                rear--;
            }
        }

        void pop_front(){           // same as normal queue
             // underflow
            if(front == -1 && rear == -1){
                cout << "Underflow" << endl;
            }
            // empty case - single element
            else if(front == rear){
                arr[front] = -1;
                front = -1;
                rear= -1;
            }
            // circular nature
            else if(front == size - 1){
                arr[front] = -1;
                front = 0;
            }
            // normal flow
            else{
                arr[front] = -1;
                front++;
            }
        }
};


int main(){

    return 0;
}