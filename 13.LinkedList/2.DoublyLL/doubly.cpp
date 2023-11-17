#include<iostream>
using namespace std;

/*
    -> Only one difference from singly linked list, this has previous node too.
*/

class Node{

    public:
        int data;                   
        Node *next;                
        Node *prev;                          // pointer to store address of previous 'Node'

        // default constructor
        Node(){
            this -> next = NULL;
            this -> prev = NULL;
        }

        // parameterized constructor
        Node(int val){
            this -> data = val;
            this -> next = NULL;
            this -> prev = NULL;
        }

};


int lengthLL(Node *&head){
    Node *temp = head;
    int size = 0;
    while(temp){
        size++;
        temp = temp -> next;
    }

    return size;
}

void printLL(Node *&head){
    Node *temp = head;
    while(temp){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
}

int main(){
    Node *head = new Node(10);



    return 0;
}