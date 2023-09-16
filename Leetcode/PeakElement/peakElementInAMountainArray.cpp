#include<iostream>
using namespace std;

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