#include<iostream>
using namespace std;

/*
    -> This is a list which is circular in traversal.
*/

class Node{

    public:
        int data;                   // data of the current node
        Node *next;                 // pointer to store address of next 'Node'

        // default constructor
        Node(){
            this -> next = NULL;
        }

        // parameterized constructor
        Node(int val){
            this -> data = val;
            this -> next = NULL;
        }

};




int main(){


    return 0;
}