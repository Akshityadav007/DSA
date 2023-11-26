#include<iostream>
using namespace std;

/*
    -> Queue is a DS which follows FIFO ordering (First In First Out).

    -> Syntax (STL) : 
        queue<int> queue_name;

    -> We can access 'front and back' elements is queue.
    -> In queue, push is from back and pop is from front.
*/

class queue{
    public:
        int *arr;
        int front;
        int rear;
        int size;

        queue(int val){
            arr = new int[val];
            this -> size = val;
            front = -1;
            rear = -1;
        }

        void push(int val){
            // if full
            if(rear == size - 1){
                cout << "Overflow!" << endl;
            }
            // first element insertion
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[rear] = val;
            }
            else{
                rear++;
                arr[rear] = val;
            }
        }

        void pop(){
            // empty queue
            if(rear == -1 && front == -1){
                cout << "Underflow!" << endl;
                return;
            }
            // first element
            else if(front == rear){
                arr[front] = 0;
                front--;
                rear--;
                return;
            }
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
    queue q(5);
    q.push(25);
    q.push(28);
    q.push(30);
    q.push(38);



    // cout << q.getBack() << endl;
    // cout << q.getFront() << endl;
    // cout << q.empty() << endl;
    // cout << q.getSize() << endl;

    return 0;
}