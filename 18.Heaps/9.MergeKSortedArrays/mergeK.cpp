#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Problem || Coding Ninjas
/*
    -> You have been given 'k' different arrays/lists, which are sorted individually (in ascending order).
    -> You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.
*/


// Solution
/*
    # Method 1 : Brute force
        -> Have 'k' pointers using another array or map.

    # Method 2 : Optimised
        -> Use priority queue (min-heap) to store first element of all 'k' arrays.
        -> Remove the top of min heap and insert it to the 'ans' array.
        -> Pop heap and insert element from the same array from where element was deleted in heap.
        -> We need to know the index of the elements to know from which array was which was popped.

        #Note : Love babbar told about constant sized 'k' array, but here we have taken variable size 'k' arrays.
*/
class Info{
    public:
        int data;
        int rowIndex;
        int colIndex;

        Info(int val, int row, int col){
            this -> data = val;
            this -> rowIndex = row;
            this -> colIndex = col;
        }
};

class compare{
    public:
        bool operator()(Info *a, Info *b){
            return a -> data > b -> data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue<Info*, vector<Info*>, compare> pq;               // min heap

    // Step 1 : process first 'k' elements i.e. first element of each row
    for(int row = 0; row < k; row++){
        int element = kArrays[row][0];
        Info *temp = new Info(element, row, 0);
        pq.push(temp);
    }

    while(!pq.empty()){
        Info *temp = pq.top();
        pq.pop();

        int topData = temp -> data;
        int topRow = temp -> rowIndex;
        int topCol = temp -> colIndex;

        // store in an vector
        ans.push_back(topData);

        // next element for the same row, from where we popped needs to be inserted
        if(topCol + 1 < kArrays[topRow].size()){
            // this means there are more elements in row
            Info *newInfo = new Info(kArrays[topRow][topCol + 1], topRow, topCol + 1);
            pq.push(newInfo);
        }
    }
    
    return ans;   
}


int main(){


    return 0;
}