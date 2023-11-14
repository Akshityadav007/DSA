#include<iostream>
using namespace std;

/*
    -> It is a linear DS.
    -> It is a collection of nodes, each node has two elements (data, address of/pointer to next node).
    -> Unlike arrays,
        - this is a non contiguous DS, hence there is no limit of memory.
        - this is stored in heap.
        - Memory wastage is lesser.
        - Insertion/Shift in O(1) time, provided you are at the location of insertion.
        - no concept of index instead there is concept of address.
    -> Just like vectors/arrays, LL has ability of dynamic increase/decrease it's size at runtime.

    # Note : Question of Linked Lists are easy to solve, only 2-3 edge cases are present in every question.
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

// to get the length of linked list
int lengthLL(Node *head){
    int size = 0;
    Node *curr = head;
    while(curr){
        size++;
        curr = curr -> next;
    }
    return size;
}

// to print the linked list
void printLL(Node *head){
    Node *curr = head;
    while(curr != NULL){
        cout << curr -> data << " -> ";
        curr = curr -> next;
    }
    cout << endl;
}

int main(){

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *five = new Node(50);
    Node *six = new Node(60);
    Node *seven = new Node(70);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = five;
    five -> next = six;
    six -> next = seven;

    printLL(head);

    cout << "The length of linked list is : " << lengthLL(head) << endl;

    return 0;
}