#include<iostream>
using namespace std;

/*
    # Deletion can be from three positions:
    -> From head
    -> From tail
    -> At a position

    # Always make sure to isolate the list node before deletion.
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

int lengthLL(Node *&head){
    int size = 0;
    Node *curr = head;
    while(curr){
        size++;
        curr = curr -> next;
    }
    return size;
}

void printLL(Node *&head){
    Node *curr = head;
    while(curr != NULL){
        cout << curr -> data << " -> ";
        curr = curr -> next;
    }
    cout << endl;
}



void deleteNode(Node *&head, int position){
    // empty list
    if(head == NULL){
        cout << "Invalid deletion, list is empty!" << endl;
        return;
    }
    // invalid position
    if(position < 1){
        cout << "Invalid deletion!" << endl;
        return;
    }

    int size = lengthLL(head);

    // single element list
    if(size == 1){
        Node *temp = head;
        delete temp;
        head = NULL;

        return;
    }

    
    // delete head
    if(position == 1){
        Node *temp = head;
        head = head -> next;
        temp -> next = NULL;

        delete temp;
        return;
    }

    // delete tail
    if(position >= size){
        // get to tail
        Node *prev = NULL;
        Node *curr = head;
        while(curr -> next){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = NULL;

        delete curr;
        return;
    }

    // delete in b/w
    else {
        // get to that position
        Node *prev = NULL;
        Node *curr = head;
        while(position > 1){
            position--;
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        
        delete curr;
    }
}


int main(){
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = new Node(50);

    printLL(head);

    deleteNode(head, 3);

    printLL(head);

    return 0;
}