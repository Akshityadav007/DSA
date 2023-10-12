#include<iostream>
using namespace std;

/*

   -> Simple approach is to treat the array values as indexes
   -> basically "we are marking the values of visited index as negative to mark them visited"
   -> at last the only index/es with positive value/s is/are missing element/s in the array

*/

// THIS CODE DOESN'T CONTAIN "SORT + SWAP" METHOD - if you want you can implement it!

vector<int> missing(vector<int> v){

    // ans vector
    vector<int> ans;

    for(int i = 0;i < v.size();i++){
        int index = abs(v[i]);
        if(v[index - 1] > 0){
            v[index - 1] *= (-1);
        }
    }

    // let's take out all positive index elements
    for(int i = 0;i <v.size();i++){
        if(v[i] > 0){
            ans.push_back(i + 1);
        }
    }
    return ans;
}

int main(){
    vector<int> v;
    cout << "Enter the size of array: " << endl;
    int n;
    cin >> n;
    cout << "Enter the array: " << endl;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    cout << "Missing Elements are: " << endl;
    vector<int> ans = missing(v);
    for(int i = 0;i < ans.size();i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}