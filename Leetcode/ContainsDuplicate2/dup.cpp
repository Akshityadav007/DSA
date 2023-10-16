#include<iostream>
#include<unordered_set>
using namespace std;

// Problem || Leetcode : 219

/*
    -> Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
*/


/*      This gives TLE (concept is correct)
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // siz of the array
        int n = nums.size();
        // traverse the array
        for(int i = 0;i < n;i++){
            int j = i + 1;
            int limit = k;      // to count the traversed limit

            // let's check in the next 'k' elements
            while(j < n && limit > 0){
                if(nums[i] == nums[j])
                    return true;
                j++;
                limit--;
            }
        }
        // whole array is traversed but didn't find any 'k' duplicate
        return false;
    }
    */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // let's get a hash
        unordered_set<int> myHash;
        for(int i = 0;i < nums.size();i++){
            // check if we found this element earlier and inserted in the next step it in hash
            if(myHash.find(nums[i]) != myHash.end()){
                return true;
            }

            // if not present, we insert it to has
            myHash.insert(nums[i]);

            // let's remove the 'k' elements we inserted earlier
            // we do this after having traversed 'k' items in the array.
            // we remove the elements before 'k' positions (starting from the 'ith' element).
            if(i >= k){
                myHash.erase(nums[i - k]);
            }
        }
        return false;
    }

int main(){


    return 0;
}