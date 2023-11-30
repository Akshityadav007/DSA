#include<iostream>
#include<queue>
using namespace std;

/*
    # Level order traversal (BFS - breadth first traversal)
        - Traversal by level.
    
            Level 0                       10
            Level 1                20           30
            Level 2            40     70      50   60

    -> We'll use queue to maintain state.
        -> Push the root (now proceed traversal using queue)
            - 1) Fetch the root from queue
            - 2) Push the left root in queue
            - 3) Push the right in queue
        -> We need to print it line by line, above code will only print it in one line.
            - So, we'll make sure to add 'NULL' after one level completes and change the line of printing.
            - Also we'll move the loop till size of queue is greater than 1, i.e. it has nodes and NULL both.
            - At the last it will have only NULL in it.
            - If a level completes, in this case it is sure that all children of the current level would have been pushed in the queue.
        -> We can use another condition too for breaking the loop,
            - we can use !q.empty(), but in this case we need to then check if queue is not empty while pushing NULL in the queue in loop.

    -> S.C. = O(m) , where 'm' is the maximum number of nodes at a level in tree.
    
    # DFS - Depth first traversal
        - In this we go in depth first i.e. from root to leaf first
*/

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        // parameterized constructor
        Node(int val){
            this -> data = val;
            this -> left = NULL;
            this -> right = NULL;
        }

};

Node *createTree(){
    cout << "Enter the value of node: " << endl;
    int data;
    cin >> data;

    // if we don't want to make tree further, we assume input to be -1 (base case)
    if(data == -1)
        return NULL;

    // Step 1: create node
    Node *root = new Node(data);

    // Step 2 : create left subtree
    root -> left = createTree();             // recursive call

    // Step 3 : create right subtree
    root -> right = createTree();            // recursive call

    return root;
}


void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);               // initial work
    q.push(NULL);

    // start traversal
    while(q.size() > 1){
        Node *front = q.front();
        q.pop();

        // Level change
        if(front == NULL){
            cout << endl;
            q.push(NULL);
        }
        // Valid node case
        else{
            cout << front -> data << " ";

            if(front -> left != NULL)
                q.push(front -> left);
            
            if(front -> right != NULL)
                q.push(front -> right);
        }
    }
}


int main(){

    Node *root = createTree();

    levelOrderTraversal(root);

    return 0;
}
