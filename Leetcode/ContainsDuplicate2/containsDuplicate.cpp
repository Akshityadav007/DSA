#include<iostream>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    int k = 2;

    cout << containsNearbyDuplicate(v,k) << endl;

    return 0;
}