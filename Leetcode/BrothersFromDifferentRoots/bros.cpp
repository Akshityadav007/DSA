#include<iostream>
#include<vector>
using namespace std;

// Problem || GFG
/*
    -> Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x.
    -> Your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.
*/
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// Solution
/*
    -> # Method 1 : Make it two sum
        -> Get inorder of both the trees.
        -> Solve it like two sum.
        -> T.C. : O(nlogn)

    -> # Method 2 : Optimized
        -> Get inorder of both the trees.
        -> Start search from starting in first tree and from last in second tree.
        -> Search for target.
            - Add current numbers in both trees.
            - If sum comes larger required, decrease the pointer of second tree.
            - If it comes smaller, increase the pointer of first tree.
            - Otherwise increase and decrease both along with increasing counter.
        -> T.C. : O(n)

*/

// Method 1
void inorder(Node *root, vector<int> &in){
    // base case
    if(root == NULL)
        return;

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

bool binarySearch(vector<int> &v, int target){
    int low = 0;
    int high = v.size() - 1;
    
    while(low <= high){
        int mid = low + ((high - low) >> 1);
        if(v[mid] == target)
            return true;
        else if(v[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int countPairs(Node* root1, Node* root2, int x)
{
    // get pre order of both nodes
    vector<int> pre1;
    vector<int> pre2;
    
    inorder(root1, pre1);
    inorder(root2, pre2);
    
    
    int count = 0;
    for(int i = 0;i < pre1.size(); i++){
        int target = x - pre1[i];
        if(binarySearch(pre2, target))
            count++;
    }
    
    return count;
}


// Method 2
void inorder(Node *root, vector<int> &in){
    // base case
    if(root == NULL)
        return;

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

int countPairs(Node* root1, Node* root2, int x)
{
    // get pre order of both nodes
    vector<int> pre1;
    vector<int> pre2;
    
    inorder(root1, pre1);
    inorder(root2, pre2);
    
    
    int count = 0;
    int i = 0,j = pre2.size() - 1;
    while(i < pre1.size() && j >= 0){
        int sum = pre1[i] + pre2[j];
        if(sum > x)
            j--;
        else if(sum < x)
            i++;
        else{
            count++;
            j--;
            i++;
        }
    }
    
    return count;
}

int main(){

    return 0;
}