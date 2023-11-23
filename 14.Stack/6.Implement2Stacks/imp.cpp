#include<iostream>
using namespace std;

// Problem
/*
    -> Implement 2 stacks using single array.
*/

//Solution
/*
    # Method 1 : 
        -> Divide the array into two equal parts (n / 2).
        -> But in this there is memory wastage.
    
    # Method 2 :
        -> Divide the array into both ends, there will be no constraint of size.
        -> Stack1 starts from 0, and stack2 starts from 'n', where 'n' is the size of the array.
        -> Memory is utilized efficiently.
*/

class stack{
    public:
        int *arr;

        int top1;
        int top2;

        int size;

    
        stack(int size){
            arr = new int[size];
            this -> size = size;
            this -> top1  = -1;
            this -> top2 = size;
        }

        void push1(int data){
            if(top1 == top2 - 1){
                cout << "Stack overflow!" << endl;
            }
            else{
                top1++;
                arr[top1] = data;
            }
        }

        void push2(int data){
            if(top1 == top2 - 1){
                cout << "Stack overflow!" << endl;
            }
            else{
                top2--;
                arr[top2] = data;
            }
        }

        void pop1(){
            if(top1 == -1)
                cout << "Stack underflow!" << endl;
            else{
                arr[top1] =  0;
                top1--;
            }

        }

        void pop2(){
            if(top2 == size)
                cout << "Stack underflow!" << endl;
            else{
                arr[top2] =  0;
                top2++;
            }

        }

        bool isEmpty1(){
            if(top1 == -1)
                return true;
            else
                return false;
        }

        bool isEmpty2(){
            if(top2 == size)
                return true;
            else
                return false;
        }

        int getTop1(){
            if(top1 == -1){
                cout << "Stack is empty!" << endl;
            }
            else
                return arr[top1];
        }

        int getTop2(){
            if(top2 == size){
                cout << "Stack is empty!" << endl;
            }
            else
                return arr[top2];
        }

        int getSize1(){
            return top1 + 1;
        }

        int getSize2(){
            return (size - top2);
        }
};



int main(){

    stack s(10);
    s.push1(10);
    s.push2(20);

    // cout << s.getSize1() << endl;
    // cout << s.getSize2() << endl;

  

    return 0;
}