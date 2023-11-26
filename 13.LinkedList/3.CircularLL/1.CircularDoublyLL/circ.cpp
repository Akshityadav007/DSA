#include<iostream>
using namespace std;

/*
    -> This is a list which is circular in traversal having 'prev' including.

    -- INSERTION --
    -> Insertion can happen in 3 ways:
        - At head
        - In b/w
        - At tail
*/

class Node{

    public:
        int data;                   // data of the current node
        Node *next;                 // pointer to store address of next 'Node'
        Node *prev;                 // pointer to store address of previous 'Node'

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
    if(head == NULL)
        return 0;
    int size = 0;
    Node *iterator = head;
    while(iterator -> next != head){
        ++size;
        iterator = iterator -> next;
    }
    ++size;
    return size;
}

void printLL(Node *&head){
    Node *temp = head;
    if(head == NULL){
        cout << "List is NULL" << endl;
        return;
    }
    do{
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    while(temp != head && temp != NULL);            // handle single element case also
}


void insert(Node *&head, int position, int data){
    // first create a node to be inserted
    Node *newNode = new Node(data);

    // handle invalid insertion
    if(position < 1){
        cout << "Invalid position" << endl;
        return;
    }

    // empty list ?
    if(head == NULL){
        head = newNode;
        head -> next = head;
        head -> prev = head;
        return;
    }

    // single element list
    if(head -> next == NULL){
        head -> next = head;
        head -> prev = head;
    }

    // insertion at head
    if(position == 1){
        // get to the last node first
        Node *tail = head -> prev;
        
        tail -> next = newNode;
        newNode -> next = head;
        newNode -> prev = tail;
        head -> prev = newNode;
        head = newNode;

        return;
    }

    // insertion at tail
    int length = lengthLL(head);

    if(position >= length + 1){
        // get to the last node first
        Node *tail = head -> prev;
        
        tail -> next = newNode;
        newNode -> next = head;
        newNode -> prev = tail;
        head -> prev = newNode;
        return;
    }

    // insert in b/w
    // get to previous node of that position
    Node *curr = head;
    while(position > 2){                                
        position--;
        curr = curr -> next;    
    }

    newNode -> next = curr -> next;
    curr -> next -> prev = newNode;
    curr -> next = newNode;
    newNode -> prev = curr;
}


void deleteNodeAtPosition(Node *&head, int position) {
    // Handle invalid position
    
    // Get the length of the circular linked list
    int length = lengthLL(head);
    if (position < 1 || position > length) {
        cout << "Invalid position" << endl;
        return;
    }

    // Handle empty list
    if (head == NULL) {
        cout << "List is empty. Deletion failed." << endl;
        return;
    }


    // Handle deletion at head
    if (position == 1) {
        
        // get to the tail
        Node *tail = head -> prev;
       

        // if there is Only one node in the list
        if (head == head -> next) {
            delete head;
            head = NULL;
        } 
        else 
        {
            tail -> next = head -> next;
            head -> next -> prev = tail;
            delete head;
            head = tail -> next;
        }
    } 
    else 
    {   
        // Handle deletion in the middle or at the end
        Node* curr = head;
        Node* prevNode = NULL;

        for (int i = 1; i < position; ++i) {
            prevNode = curr;
            curr = curr -> next;
        }

        prevNode -> next = curr -> next;
        if(curr -> next != NULL){
            curr -> next -> prev = prevNode;
        }
        delete curr;
    }
}


int main(){
    Node *head = new Node(10);
    insert(head, 2, 20);
    insert(head, 3, 30);
    insert(head, 4, 40);
    insert(head, 5, 50);
    insert(head, 6, 60);

    printLL(head);


    return 0;
}