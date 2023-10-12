#include<iostream>
using namespace std;

// Find missing element in an array (range [0,n - 1],as 1 element is missing) containing element from range [1,n].

int findMissing(vector<int> &v,int n){
    int low = 0,high = n - 1;
    int mid = low + (high - low) / 2;
    int ans = -1;
    while(low <= high){
        int diff = v[mid] - mid;
        if(diff == 1){
            low = mid + 1;
        }
        else {
            ans = mid;
            high = mid - 1;
        }
        mid = low + (high - low) / 2;
    }

    // if last Element is missing  i.e. array = {1,2,3,4,5,6,7,8} - here '9' is missing
    if(ans == 0)
        ans = n + 1;    // find a logic to remove this hard - coding handling.
    return ans + 1;
}

int main(){
    int n;
    cout << "Enter the sorted array size:" << endl;
    cin >> n;
    vector<int> v;
    cout << "Enter the non duplicate elements of sorted array:" << endl;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int res = findMissing(v,n);
    cout << "Missing Element is: " << res << endl;
}