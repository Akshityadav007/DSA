#include<iostream>
#include<vector>
using namespace std;

void shift(vector<int> &nums,int k){
    /*
        Two Solutions:
        1. TC = O(n) ; SC = O(n)
        2. TC = O(n) ; SC = O(k)
        3. TC = O(n) ; SC = O(1)
        */

        int n = nums.size();

        // Solution 1 [Love Babbar's] - modulus method
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


// reversal method - if you understand it, easiest method
/*

    1) Reverse the whole array
    2) Reverse it from 0 to k - 1
    3) Reverse the remaining array (k to n - 1)

*/

// void reverseArray(vector<int>& v,int start,int end){
//     while(start < end){
//         swap(v[start],v[end]);
//         start++;end--;
//     }
// }

void shiftByReversal(vector<int>& v,int k){
    k = k % v.size();
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin() + k - 1);   
    reverse(v.begin() + k,v.end());
}


int main(){
    int n;
    cout << "Size of array? : " <<endl;
    cin>>n;
    vector<int> v;
    cout << "Enter array elements: " << endl;
    for(int i = 0;i < n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int k;
    cout << "Enter number of times you want to rotate it: " << endl;
    cin >> k;

    shiftByReversal(v,k);
    cout << "After shift: " << endl;
    for(int i = 0;i < n;i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}