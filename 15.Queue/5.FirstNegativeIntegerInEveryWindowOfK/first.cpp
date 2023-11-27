#include<iostream>
#include<queue>
using namespace std;


// Problem || Coding Ninjas : Moderate
/*
    -> You have been given an array of integers 'ARR' of size 'N'.
    -> Your are also provided with a positive integer 'K'.
    -> Your task is to find the first negative element in every window[contiguous subarray] of length 'K'.
    -> If there is no negative element in a window, then print 0 for that window.
*/

// Solution
/*
    # Method 1 : Brute force
     -> Check for every window.
     -> T.C. : O(n * k)
    
    # Method 2 : Use 'queue'
    -> Take a doubly ended queue
    -> Store index of -ve element in 'k'

    -> Keep pushing the elements in 'answer vector'.
    -> As we move further in the window, remove the index out of window range from the queue

*/
vector<int> firstNegative(vector<int> arr, int n, int k) {
	vector<int> ans;
	queue<int> q;

	// process first 'k' elements i.e. first window
	for(int i = 0;i < k;i++){
		if(arr[i] < 0)
			q.push(i);
	}

	for(int i = k; i < n; i++){
		if(q.empty())
			ans.push_back(0);
		else
			ans.push_back(arr[q.front()]);
		

		// remove index out of range of window from queue
		if(!q.empty() && (i - q.front()) >= k)
			q.pop();
		
		// insert
		if(arr[i] < 0)
			q.push(i);
		
	}

	// last window
	
	if(q.empty())
		ans.push_back(0);
	else
		ans.push_back(arr[q.front()]);

	return ans;

}


int main(){


    return 0;
}