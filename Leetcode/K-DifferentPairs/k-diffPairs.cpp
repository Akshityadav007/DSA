#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*

    Given an array with numbers. You need to find unique pairs with a difference of 'k'.


*/


// method 1) 2 pair - 2 pointer approach

int findPairs1(vector<int>& nums, int k) {

        int n = nums.size();
        // Method 1. sorting
        // vector<int> v = nums;           // this is shallow copy i.e. just referencing
        vector<int> v;
        copy(nums.begin(),nums.end(),back_inserter(v));     // this is non referecing copying
        sort(v.begin(),v.end());

        // I did the above because I didn't want to change the question vector/ user input

        // need to use set to contain unique pairs
        set< pair<int,int> > ans;
        
        // two ptr approach
        int p1 = 0,p2 = 1;      

        // for single element array
        if(n == 1)
        return 0;

        while(p2 < n){
            int diff = abs(v[p1] - v[p2]);
            if(diff == k){
                ans.insert({v[p1],v[p2]});
                p1++;p2++;
            }
            else if(diff > k){
                p1++;
            }
            else{
                p2++;
            }
            if(p1 == p2)
                p2++;
        }
        return ans.size();
    }


// method 2) Using binary search - same T.C. same S.C.

        /*
            -> We can say, abs(nums[i] - nums[j]) = k , 
                also => nums[i] + k = nums[j]
                where i < j;

            -> The idea is to search for a number which 'k' more than the element at which we are standing
            -> E.g. if we are at 'i' then we need to find a number x, which is equal to v[i] + k
                i.e. v[i] + k = v[j] or v[i] + k = v[mid]
        */

int binarySearch(vector<int>& v,int low, int target){
    int n = v.size();
    int high = n - 1;
    int mid = low + (high - low) / 2;

    while(low <= high){
        if(v[mid] == target){
            return mid;
        }
        else if(v[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        // update mid
        mid = low + (high - low) / 2;
    }
    return -1;
}

int findPairs2(vector<int>& nums, int k){
    int n = nums.size();
        // for single element
        if(n == 1)
        return 0;

        // to store ans for unique numbers
        set< pair<int,int> > ans;
        // first just sort the array to apply binary sort
        sort(nums.begin(),nums.end());

        // let's do it
        for(int i = 0;i < n;i++){

            // for every element, v[i] we need to find another element which is equal to v[i] + k
            // we need to alot search space too
            int low = i + 1;
            int target = nums[i] + k;

            if(binarySearch(nums,low,target)!= -1){
                ans.insert({nums[i],target});
            }
        }
        return ans.size();

}

int main(){
    // just implement it

    return 0;
}