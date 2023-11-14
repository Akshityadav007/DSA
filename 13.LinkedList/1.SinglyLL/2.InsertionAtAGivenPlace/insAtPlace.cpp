#include<iostream>
using namespace std;

// insert at 'nth' position
/*
    -> Edge cases
        1. N < 1 i.e. Invalid
        2. N > length i.e. at tail
        3. N == 1 i.e. at head
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


// to get the length of linked list
int lengthLL(Node *&head){
    int size = 0;
    Node *curr = head;
    while(curr){
        size++;
        curr = curr -> next;
    }
    return size;
}


void insertAtAPosition(Node *&head, int data, int position){
    // Edge cases
    // 1)
    if(position < 1){
        cout << "Invalid position!" << endl;
        return;
    }

    // 2)
    int length = lengthLL(head);
    if(position > length){
        insertAtTail(head, data);
        return;
    }

    // 3)
    if(position == 1){
        insertAtBegining(head, data);
        return;
    }



    // all edge cases handled, now if 'position' is in the middle
    
    // create new node
    Node *newNode = new Node(data);

    // traverse to the position
    Node *prev = NULL;                      // track previous
    Node *curr = head;
    for(int i = 0;i < position - 1;i++){
        prev = curr;
        curr = curr -> next;
    }
    
    prev -> next = newNode;
    newNode -> next = curr;

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

    insertAtAPosition(head, 49, 2);

    printLL(head);

    return 0;
}