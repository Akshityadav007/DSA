#include<iostream>
using namespace std;

// Homework : Design a n - arry tree / generic tree.

class Node{
    public:
        int data;
        int children_count;
        Node **children;

        Node(int val){
            this -> data = val;
            this -> children_count = 0;
            this -> children = NULL;
        }
};

Node *createTree(){
    int data, count;
    cout << "Enter the data: " << endl;
    cin >> data;
    cout << "Enter children count for " << data << " node: " << endl;
    cin >> count;

    Node *root = new Node(data);
    root -> children_count = count;
    root -> children = new Node*[count];            // array to store links to children
    for(int i = 0;i < count; i++)
        root -> children[i] = createTree();
    return root;
}

int main(){


    return 0;
}