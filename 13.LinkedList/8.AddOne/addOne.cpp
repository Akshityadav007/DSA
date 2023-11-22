#include<iostream>
using namespace std;

// Problem || Leetcode premium
/*
    -> Given a linked list filled with one digit non negative numbers.
    -> Consider the elements of the linked list to be a number.
    -> Add 1 to the number.
*/


// Soltion
/*
    -> Reverse the linked list.
    -> Add 1 to the linked list from starting.
    -> Reverse the linked list again.
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

// to print the linked list
void printLL(Node *&head){
    Node *curr = head;
    while(curr != NULL){
        cout << curr -> data << " -> ";
        curr = curr -> next;
    }
    cout << endl;
}



Node *reverseList(Node *&head){
    if(head == NULL)
        return head;
    
    Node *curr = head;
    Node *prev = NULL;

    while(curr){
        Node *temp = curr;
        curr = curr -> next;
        temp -> next = prev;
        prev = temp;
    }
    return prev;
}

void addOne(Node *&head){
    if(head == NULL)
        return;
    
    // Step 1) Reverse
    head = reverseList(head);

    // Step 2) start adding 1
    Node *curr = head;          // to traverse the array
    int carry = 1;              // take carry as '1' from starting
    while(curr -> next){
        int sum = (curr -> data) + carry;
        carry = sum / 10;
        sum = sum % 10;

        curr -> data = sum;
        curr = curr -> next;
        if(carry == 0)
            break;
    }

    // for the last element
    int sum = (curr -> data) + carry;
    carry = sum / 10;
    sum = sum % 10;
    curr -> data = sum;

    // if carry is left still , E.g. In case of 999
    if(carry > 0){
        Node *newNode = new Node(carry);
        curr -> next = newNode;
    }

    // Step 3) Reverse
    head = reverseList(head);
}


int main(){

    Node *head = new Node(0);
    Node *second = new Node(0);
    Node *third = new Node(0);
    Node *fourth = new Node(0);
    Node *five = new Node(0);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = five;

    printLL(head);
    addOne(head);
    printLL(head);

    return 0;
}