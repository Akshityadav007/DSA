#include<iostream>
#include<vector>
using namespace std;

/*

    A nearly sorted array is an array in which, element at 'i' in sorted array is found at i - 1,i,i + 1.
    
    -> So we'll simply keep checking mid - 1 and mid + 1 positions too while checking for mid.
    -> Also since we already have checked for mid - 1 and mid + 1 positions, while updating low/high we'll update it by +/- 2 instead of +/- 1. (actually this improves the code, had we used earlier version too, would have worked)
    -> We need to handled out of bound condtions also (index = -1,-2 or index = n, n + 1)

*/

int searchInNearlySortedArray(vector<int>& v,int target){
    int n = v.size();
    int low = 0,high = n - 1;
    int mid = low + (high - low) / 2;

    while(low <=high){
        // check for mid
        if(v[mid] == target)
            return mid;

        // check for mid - 1
        else  if(mid > 0 && v[mid - 1] == target)
            return mid - 1;

        // check for mid + 1
        else if(mid < (n - 1) && v[mid + 1] == target)
            return mid + 1;

        else if(v[mid] < target)
            low = mid + 2;
        else
            high = mid - 2;
            
        // update mid
        mid = low + (high - low) / 2;
    }
    return -1;

}

int main(){
    // sorted array = [10,20,30,40,50,60,70,80]
    // nearly sorted array ↓
    vector<int> v;
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);
    v.push_back(70);
    v.push_back(60);
    v.push_back(80);

    cout << "The array: " << endl;
    for(int i = 0;i < v.size();i++)
        cout << v[i] << " ";
    cout << endl;

    int target;
    cout << "Enter target: " << endl;
    cin >> target;

    int ans = searchInNearlySortedArray(v,target);
    if(ans >= 0)
        cout << target << " found at index " << ans << endl;
    else
        cout << target << " not found in the array!" << endl;
    return 0;
}