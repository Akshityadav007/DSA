#include<iostream>
using namespace std;

// Problem || GFG
/*
    -> Given a Binary Search Tree of size N, find the Median of its Node values.
    -> Median of the BST is:
        - If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2
        - If number of nodes are odd : then median = (N+1)/2th node.
*/

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// Solution
/*
    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(Height of the Tree).

    -> Hence, first get the height of the tree.
    -> Then get the median, simple!
*/

void getNodes(struct Node *&root, int &n){
    // base case
    if(root == NULL)
        return;
    
    getNodes(root -> left, n);
    n++;
    getNodes(root -> right, n);
}

// function overloading
// odd
void getMedian(struct Node *&root, pair<float, float> &p, int &med, int n, int &lastElement){
       // base case
    if(root == NULL)
        return;
    
    getMedian(root -> left, p, med, n, lastElement);                      // left
    med--;                                                                // root
    if(med == 0){
        if(n & 1)
            // odd
            p.first = root -> data;
        else{
            // even
            p.first = lastElement;
            p.second = root -> data;
        }
        return;
    }
    lastElement = root -> data;
    getMedian(root -> right, p, med, n, lastElement);                     // right
}

float findMedian(struct Node *root)
{
    // step 1 : get total no. of nodes
    int n = 0;
    getNodes(root, n);
    
    // step 2 : get median node
    float ans = 0;
    int med = (n / 2) + 1;
    pair<float, float> p;
    int lastElement = root -> data;
    
    getMedian(root, p, med, n, lastElement);
    if(n & 1)
        ans = p.first;
    else
        ans = (p.first + p.second) / 2;
   
    
    return ans;
}

int main(){

    return 0;
}