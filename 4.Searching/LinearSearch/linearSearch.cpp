#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> v,int target){
    for(int i = 0;i < v.size();i++){
        if(v[i] == target)
            return i;
    }
    return -1;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    int target = 5;
    int ans = search(v,target);
    cout << ans << endl;
}