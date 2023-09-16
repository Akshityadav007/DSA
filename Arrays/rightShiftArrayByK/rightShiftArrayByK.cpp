#include<iostream>
using namespace std;

void shift(vector<int> &nums){
    /*
        Two Solutions:
        1. TC = O(n) ; SC = O(n)
        2. TC = O(n) ; SC = O(k)
        3. TC = O(n) ; SC = O(1)
        */

        int n = nums.size();

        // Solution 1 [Love Babbar's]
        // vector<int> ans(n);
        // for(int i = 0;i < n;i++){
        //     ans[(i + k) % n] = nums[i];
        // }
        // nums = ans;

        // Solution 2  [Took help from Striver]
        // k = k % n;
        // if(k == 0)
        // return;

        // vector<int> v(k);
        // int j = 0;
        // for(int i = n - k;i < n;i++){
        // v[j] = nums[i];
        // j++;
        // }

        // for(int i = n - k - 1;i >= 0;i--){ 
        //     nums[i + k] = nums[i];
        // }

        // for(int i = 0;i < k;i++)
        // nums[i] = v[i];
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    shift(v);
    return 0;
}