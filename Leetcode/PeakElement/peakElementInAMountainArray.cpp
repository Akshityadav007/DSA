#include<iostream>
using namespace std;

// Problem || Leetcode 852
/*
    -> On ploting the array elements it appears like a mountain.
    -> We need to get the peak element of it.

    -> Just divide it in two parts:
        - Part A = Increasing i.e. a[i] < a[i + 1]
        - Part B = The Peak i.e. a[i] > a[i + 1] && a[i] > a[i - 1]
        - Part C = Decreasing i.e. a[i] > a[i + 1]

    -> There is common thing in Part B and Part C (a[i] > a[i + 1])
        - Therefore we can club them together and solve the question.
        - First Half - Part A and Second Half - (Peak + Part C).

*/

int peak(vector<int> &v){
    int n = v.size();
    int low = 0, high = n - 1;
    int ans = -1;
    int mid = low + (high - low) / 2;

    while(low < high){
        if(v[mid] < v[mid + 1]){
            // first half part
            low = mid + 1;  //as we are certain that peak exist after mid
        }
        else{
            // either peak or second half part
            high = mid; // what if peak is present at mid? if we do ' high = mid + 1 ' , peak will be lost.
        }
        // update mid
        mid = low + (high - low) / 2;
    }
    return mid;
}

int main(){
    int n;
    cout << "Enter the mountain array size:" << endl;
    cin >> n;
    vector<int> v;
    cout << "Enter the elements of array:" << endl;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int ans = peak(v);
    cout << "Found peak at " << ans << endl;
    return 0;
}