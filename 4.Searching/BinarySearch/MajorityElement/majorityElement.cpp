#include<iostream>
using namespace std;

// Problem : Easy || Leetcode : 169

/*
    -> Given an array nums of size n, return the majority element.
    -> The majority element is the element that appears more than ⌊n / 2⌋ times. 
    -> You may assume that the majority element always exists in the array.
*/

// Solution
/*
    # Method 1
    -> Sort the array.
    -> Get first and last occurrences for each element.
    -> Get the total count of occurrences of the element.
    -> Return the element whose total occurrence > n / 2.

    # Method 2
    -> Sort the array.
    -> If an element occures more than n / 2 times, then we can be sure that on sorting it will be always be present at index = n / 2.
    -> Hence return v[n / 2];
*/

int firstOccurrence(vector<int> &v,int target){
    int low = 0,high = v.size() - 1;
    // store ans
    int ans = -1;
    while(low <= high){
        int mid = low + ((high - low) >> 1);
        if(v[mid] == target){
            ans = mid;
            high = mid - 1;
        }
        else if(v[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int lastOccurrence(vector<int> &v,int target){
    int low = 0,high = v.size() - 1;
    // store ans
    int ans = -1;
    while(low <= high){
        int mid = low + ((high - low) >> 1);
        if(v[mid] == target){
            ans = mid;
            low = mid + 1;
        }
        else if(v[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int majorityElement1(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    
    // count total occurrences - last occurrence - first occurrence
    for(int i = 0;i < nums.size();i++){
        if((lastOccurrence(nums,nums[i]) - firstOccurrence(nums,nums[i]) + 1) > n / 2)
            return nums[i];
    }
    return -1;
}

int majorityElement2(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    return nums[n / 2];
}

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);

    cout << majorityElement1(v) << endl;
    cout << majorityElement2(v) << endl;

    return 0;
}