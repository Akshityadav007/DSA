#include<iostream>
using namespace std;

/*
    -> Insertion can be done at three points: 
        - In front (at head)
        - At tail
        - At a given point

    # Note : Love created a 'tail' pointer to store the tail node just like we store 'head' node, but I haven't done it.
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


// make sure to pass by reference
void insertAtBegining(Node *&head, int data){
    // create the required Node
    Node *newNode = new Node(data);

    // assign the new node in the LL (handle empty list)
    if(head)
        newNode -> next = head;

    // update head
    head = newNode;
}

// (handle empty list)
void insertAtTail(Node *&head, int data){
    // create new node
    Node *newNode = new Node(data);

    // handle empty list
    if(head == NULL){
        head = newNode;
        return;
    }

    // traverse till the end
    Node *curr = head;
    while(curr -> next)
        curr = curr -> next;
    
    // insert the node
    curr -> next = newNode;
}


void printLL(Node *&head){
    Node *curr = head;
    while(curr != NULL){
        cout << curr -> data << " -> ";
        curr = curr -> next;
    }
    cout << endl;
}

int main(){

    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);

    printLL(head);

    insertAtBegining(head, 5);
    printLL(head);

    insertAtTail(head, 50);
    printLL(head);

    return 0;
}