#include<iostream>
using namespace std;

/*
    -> LIFO order
    -> Syntax:
        - Stack<data_type> stack_name;
        - E.g. : Stack<int> st;

    -> Can be implemented using:
        1) Vector / array
        2) List

    # Note : Anything can be reversed after insertion in stack
*/

class Stack{
    public:
        int *arr;
        int size;
        int top;

        Stack(int size){
            arr = new int[size];
            this -> size = size;
            this -> top  = -1;
        }

        void push(int data){
            if(top == size - 1){
                cout << "Stack overflow!" << endl;
            }
            else{
                top++;
                arr[top] = data;
            }
        }

        void pop(){
            if(top == -1)
                cout << "Stack underflow!" << endl;
            else{
                arr[top] =  0;
                top--;
            }

        }

        bool isEmpty(){
            if(top == -1)
                return true;
            else
                return false;
        }

        int getTop(){
            if(top == -1){
                cout << "Stack is empty!" << endl;
            }
            else
                return arr[top];
        }

        int getSize(){
            return top + 1;
        }

        void print(){
            for(int i = 0;i <= top;i++){
                cout << arr[i] << endl;
            }
        }
};

int main(){
    Stack st(8);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);

    st.print();



    return 0;
}