#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Problem || Leetcode : 632
/*
    -> You have k lists of sorted integers in non-decreasing order. 
    -> Find the smallest range that includes at least one number from each of the k lists.
    -> We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
*/


// Solution
/*
    -> Solve this similarly like merge k sorted arrays/lists.
    -> Create a min heap for first 'k' elements, along with keeping a track of maximum element.

    -> Insert the top element of queue and move to next element of array, update the maximum element.

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

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<Info*, vector<Info*>, compare> pq;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        // process first 'k' elements
        for(int i = 0;i < nums.size(); i++){
            int element = nums[i][0];
            Info *temp = new Info(element, i, 0);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }

        // first range
        int ansStart = mini;
        int ansEnd = maxi;

        while(!pq.empty()){
            Info *topNode = pq.top();
            int topCol = topNode -> colIndex;
            int topRow = topNode -> rowIndex;

            pq.pop();

            mini = topNode -> data;

            if((maxi - mini) < (ansEnd - ansStart)){
                // update ans
                ansStart = mini;
                ansEnd = maxi;
            }

            // insert
            if(topCol + 1 < nums[topRow].size()){
                int newElement = nums[topRow][topCol + 1];
                maxi = max(maxi, newElement);
                Info *newInfo = new Info(newElement, topRow, topCol +1);
                pq.push(newInfo);
            }
            else
                break;                              // if any one of the rows get finished, we can't get the range for common values, hence break
        }

        
        vector<int> ans;        // to store answer
        ans.push_back(ansStart);
        ans.push_back(ansEnd);

        return ans;
    }
};

int main(){

    return 0;
}