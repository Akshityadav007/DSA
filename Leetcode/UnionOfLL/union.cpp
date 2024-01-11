#include<iostream>
#include<map>
using namespace std;

// Problem || GFG
/*
    -> Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked lists. 
    -> This union list should include all the distinct elements only and it should be sorted in ascending order.
*/
struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// Solution
/*
    # Method 1 : Use hashmap
        -> Use ordered map to store the values as key and node as value.
*/

 struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        map<int, Node*> m;
        
        // insert first list in map
        Node *curr = head1;
        while(curr != NULL){
            m[curr -> data] = curr;
            curr = curr -> next;
        }
        
        // insert second list in map
        curr = head2;
        while(curr != NULL){
            m[curr -> data] = curr;
            curr = curr -> next;
        }
        
        Node *head = NULL;
        curr = NULL;
        for(auto i : m){
            if(head == NULL){
                head = i.second;
                curr = head;
            }
            else{
                curr -> next = i.second;
                curr = curr -> next;
            }
        }
        curr -> next = NULL;                        // last node should be pointed to NULL
        
        return head;
    }

int main(){


    return 0;
}