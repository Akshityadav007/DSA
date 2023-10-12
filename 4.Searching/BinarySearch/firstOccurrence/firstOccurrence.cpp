#include<iostream>
using namespace std;

// love babbar's code < looks better and reliable >
int binarySearch2(vector<int> &v,int n,int target){
    int low = 0,high = n - 1;
    int ans = -1;

    int mid = low + (high - low) / 2;
    while(low <= high){
        if(v[mid] == target){
            ans = mid;
            high = mid - 1;
        }
        else if(v[mid] > target){
            high = mid - 1;
        }
        else if(v[mid] < target){
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return ans;
}


// my code
int binarySearch(vector<int> &v,int n,int target){
    int low = 0,high = n - 1;
    // there is a flaw in the below line < find - out >
    int mid = (low + high) / 2;
    while(low <= high){
        if(v[mid] == target){
            if(mid!= 0 && v[mid - 1] == target){
                high = mid - 1;
            }
            else{
                return mid;
            }
        }
        else if(v[mid] > target){
            high = mid - 1;
        }
        else if(v[mid] < target){
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter the sorted array size:" << endl;
    cin >> n;
    vector<int> v;
    cout << "Enter the elements(can be duplicate) of sorted array:" << endl;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int target;
    cout << "Enter the target:" << endl;
    cin >> target;
    int res = binarySearch2(v,n,target);
    if(res == -1)
    cout << "Element not found!" << endl;
    else
    cout << "First Occurrence of element found at " << res << endl;
}