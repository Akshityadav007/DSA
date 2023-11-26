#include<iostream>
using namespace std;

/*
    -> In normal queue, whenever we pop() and element, the front is forwarded. The spaces in back of front is wasted.
    -> E.g.: [-1,-1,-1,2,3,5,0,0,0,0]
                       ^   ^
                    Front  Back
    
    -> Notice the spaces at the back of front are wasted.


    -> So, to solve this we have circular queue.
    -> If space is filled in rear, we will fill elements in circular manner i.e. move to the first index (0) for insertion.
*/


class circularQueue{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        circularQueue(int val){
            arr = new int[val];
            this -> size = val;
            front = -1;
            rear = -1;
        }

        void push(int val){
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

        
        void pop(){
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

        int getSize(){
            return (rear == -1 && front == -1) ? 0 : (rear - front + 1);            // handled empty queue
        }

        bool empty(){
            return (rear == -1 && front == -1);
        }

        int getFront(){
            if(front == -1){
                cout << "No element in queue!" << endl;
                return -1;
            }
            else
                return arr[front];
        }

        int getBack(){
            if(rear == -1){
                cout << "No element in queue!" << endl;
                return -1;
            }
            else
                return arr[rear];
        }
};


int main(){
    circularQueue cq(5);
    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);
    

    return 0;
}