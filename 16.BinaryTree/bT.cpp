#include<iostream>
using namespace std;

/*
    -> It is a non - linear data structure.
    -> There is one root node having branches in heirarchy.
    -> Last nodes in a branch are called leaf nodes.

    -> Binary tree can have at most two children in a node.
    
    # MCQ questions are asked from this topic.
    # There are upto 10 - 12 mathematical formulae which come in MCQs.


    # Terminologies
        - Root Node
        - Parent Node
        - Child Node
        - Leaf Node = Node with 0 child

        - Ancestor = All Nodes before child node are the ancestor Nodes.
        - Descendend = All Nodes below the current node.
        - Sibling = Nodes having common parent.
        - Level = starts from 0 i.e. root is at level 0.
        - Neighbour = Nodes at same level.

        - Sub - tree = A section of the tree. E.g. : Left sub - tree, Right sub - tree, etc.



    # Implementation:
        - Use recursion

*/

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        // default constructor
        Node(){
            data = 0;
            this -> left = NULL;
            this -> right = NULL;
        }

        // parameterized constructor
        Node(int val){
            data = val;
            this -> left = NULL;
            this -> right = NULL;
        }
};

int main(){


    return 0;
}