#include<iostream>
#include<map>
using namespace std;

// Problem || Leetcode : 215
/*
    -> Given an integer array nums and an integer k, return the kth largest element in the array.
    -> Note that it is the kth largest element in the sorted order, not the kth distinct element.
    -> Can you solve it without sorting?

*/

// Solution
 int findKthLargest(vector<int>& nums, int k) {
        // ordered hash
        map <int, int> myHash;

        for(auto i : nums){
            // if element is already been mapped (present in myHash)
            if(myHash.find(i) != myHash.end())
                myHash[i]++;
            // if not present in myHash
            else
                myHash[i] = 1;
        }


        // now let's us get our answer
        int ans = nums[0];              // just initialising it to first element of nums
        
        map <int, int> :: iterator it = myHash.end();       // iterator from the end of map
        
        // keep reducing 'k' till it gets to 0
        while(k > 0){
            if( (it -> second) > 0){
                --(it -> second);
                --k;
            }
            else
                --it;
        }

        return it -> first;
    }

int main(){


    return 0;
}