#include<iostream>
using namespace std;

/*
    # Deletion can happen at 3 points:
        - At head
        - At tail
        - At a given position

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

void printLL(Node *&head){
    Node *temp = head;
    while(temp){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

int lengthLL(Node *&head){
    int size = 0;
    Node *curr = head;
    while(curr){
        size++;
        curr = curr -> next;
    }
    return size;
}

void insert(Node *&head, int position, int data){
    // handle invalid position
    if(position < 1){
        cout << "Invalid insertion!" << endl;
        return;
    }

    // create the node to be inserted
    Node *newNode = new Node(data);

    // LL is empty
    if(head == NULL){
        head = newNode;
        return;
    }

    // insertion at head
    if(position == 1){
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
        return;
    }

    // insertion at tail
    if(position >= lengthLL(head) + 1){
        Node *curr = head;
        while(curr -> next)
            curr = curr -> next;
        
        curr -> next = newNode;
        newNode -> prev = curr;
        return;
    }


    // insertion in b/w
    // get to the position where insertion is to be done
    Node *curr = head;
    while(position > 1){
        position--;
        curr = curr -> next;
    }

    curr -> prev -> next = newNode;
    newNode -> next = curr;
    newNode -> prev = curr -> prev;
    curr -> prev = newNode;

}



void deleteNode(Node *&head, int position){
    // empty list
    if(head == NULL){
        cout << "Invalid deletion, list is empty!" << endl;
        return;
    }
    // invalid position
    if(position < 1){
        cout << "Invalid position!" << endl;
        return;
    }

    // single element list
    if(lengthLL(head) == 1){
        Node *temp = head;
        delete temp;
        head = NULL;

        return;
    }

    // delete from head
    if(position == 1){
        Node *temp = head;
        head = head -> next;
        temp -> next = NULL;
        head -> prev = NULL;

        delete temp;
        return;
    }

    // delete from tail
    if(position >= lengthLL(head)){
        // get to tail
        Node *tail = head;
        while(tail -> next)
            tail = tail -> next;

        tail -> prev -> next = NULL;
        tail -> prev = NULL;

        delete tail;  
        return;     
    }

    
    // delete from b/w
    Node *curr = head;
    while(position > 1){
        position--;
        curr = curr -> next;
    }

    curr -> prev -> next = curr -> next;
    curr -> next -> prev = curr -> prev;

    delete curr;
}


int main(){
    Node *head = new Node(10);
    // insert(head, 2, 20);
    // insert(head, 3, 30);
    // insert(head, 4, 40);
    // insert(head, 5, 50);
    // insert(head, 6, 60);
    // insert(head, 7, 70);
    // insert(head, 8, 80);

    printLL(head);

    deleteNode(head, -1);
    deleteNode(head, 1);
    deleteNode(head, 1);

    printLL(head);

    return 0;
}