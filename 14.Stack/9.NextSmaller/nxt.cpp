#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Problem || Coding Ninjas : Moderate
// V. Important questions
/*
    -> You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
    -> Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
    -> If for any array element the next smaller element does not exist, you should print -1 for that array element.

    For Example:
    If the given array is [2, 3, 1], we need to retum [1, 1, -1]. 
    Because for 2, 1 is the Next Smaller element. 
    For 3. 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.

*/



// Solution
/*
    # Method : Brute force
        -> For every element, move further in the array and make comparisions.
        -> O(n ^ 2).

    # Method : Use Stack
        -> Take a stack and insert -1 in it (We know for every last element, -1 is the result).
        -> Now traverse the array from end, and make comparisions.
        -> If the current element is smaller than the top element, replace top element with current element.
        -> Otherwise don't move anything in stack, instead take the top element as the smallest element till now.




    # Note : If the question is "Previous smaller element", we'll traverse the array just the reverse of this, i.e. from start. Rest all other things are same.
*/

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, 0);
    stack<int> s;
    s.push(-1);

    for(int i = n - 1; i >= 0; i--){
        
        // find the answer for current element
        while(s.top() >= arr[i]){
            s.pop();                                // there won't be any case of underflow as last element will be -1
        }

        ans[i] = s.top();
        s.push(arr[i]);
    }

    return ans;
}


vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, 0);
    stack<int> s;
    s.push(-1);

    for(int i = 0; i < n; i++){
        
        // find the answer for current element (arr[i])
        while(s.top() >= arr[i]){
            s.pop();                                // there won't be any case of underflow as last element will be -1
        }

        ans[i] = s.top();
        s.push(arr[i]);
    }

    return ans;
}



int main(){


    return 0;
}


/*
    -> Questions based on the same approach:
        1) Previous smaller number
        2) Longest Valid parentheses (Leetcode : 32 || Hard (DP))
        3) Final Prices With a Special Discount in a Shop (Leetcode : 1475 || Easy)

*/