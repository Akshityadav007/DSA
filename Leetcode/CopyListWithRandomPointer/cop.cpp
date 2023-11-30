#include<iostream>
#include<map>
using namespace std;

// Problem || Leetcode : 138
/*
    -> A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
    -> Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. 
    -> Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. 
    -> None of the pointers in the new list should point to nodes in the original list.

    -> For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
    -> Return the head of the copied linked list.

    -> The linked list is represented in the input/output as a list of n nodes. 
    -> Each node is represented as a pair of [val, random_index] where:
        - val: an integer representing Node.val
        - random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
        - Your code will only be given the head of the original linked list.
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Solution
/*
    -> First make a map which has key of the given list and value of the new node which we make.
    -> Map the lists.
    -> Next map the random nodes and the next of the new node.
    -> The random of key will give another key (node) which will hava a value in the map (of the new node), we need to map the value of current key to the value of this key which we got.
*/


Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        
        // use hashmap to store the random node
        map <Node*, Node*> nodeMap;

        // first make the list
        Node *newList;
        Node *originalList = head;

        // map the lists
        while(originalList != NULL){
            Node *newNode = new Node(originalList -> val);
            nodeMap[originalList] = newNode;
            
            originalList = originalList -> next;
        }

        originalList = head;
        newList = nodeMap[originalList];            // keep head of new list

        // build the list
        while(originalList != NULL){
            nodeMap[originalList] -> next = nodeMap[originalList -> next];                      // map the next of new list
            nodeMap[originalList] -> random = nodeMap[originalList -> random];                  // map the random node of list

            originalList = originalList -> next;
        }
        
        return newList;
    }

int main(){


    return 0;
}