#include <iostream>
#include<vector>
using namespace std;

// THIS QUESTION IS NOT PRESENT ON LEETCODE (NORMAL)

vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int n = a.size(),m = b.size(),k = c.size();
    // two pointer approach
    int p1 = 0,p2 = 0;
    // temproray array to store all common elements among a and b
    vector<int> temp;
    // travserse both arrays
        int count = 0;
        cout << (++count) << endl;


    // ISSUE IS IN THE BELOW CODE

    while(p1 < n && p2 < m){
        if(a[p1] == b[p2]){
            cout << (++count) << endl;
          if (temp.empty()) {
              temp.push_back(a[p1]);
              p1++;p2++;
          }
          else{
              if (a[p1] != temp[temp.size() - 1]) {
              temp.push_back(a[p1]);
              p1++;
              p2++;
            }
        }
        }
        else if(a[p1] < b[p2])
        p1++;
        else
        p2++;
    }



    // pointer to array temp
        cout << (++count) << endl;
    int p3 = 0;
    // now compare temp array with c
    // before that declare ans array
    vector<int> ans;
    // we can search the elements of array temp in c using binary search
    for(int i = 0;i < temp.size();i++){
        int target = temp[i];
        int low = 0,high = k - 1;
        int mid = low + (high - low) / 2;
        while(low <= high){
            if(c[mid] == target){
                ans.push_back(target);
                break;
            }
            else if(c[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            // update mid
            mid = low + (high - low) / 2;
        }
    }
    return ans;

}

int main(){
    // implement it
    int n,m,k;
    // take inputs
    cout << "Enter the values of m, n, k: " << endl;
    cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(k);
    cout << "Enter the values of a: " << endl;
    for(int i = 0;i < n;i++){
        int z;
        cin>>z;
        a.push_back(z);
    }
    cout << "Enter the values of a: " << endl;
    for(int i = 0;i < m;i++){
        int z;
        cin>>z;
        b.push_back(z);
    }
    cout << "Enter the values of a: " << endl;
    for(int i = 0;i < k;i++){
        int z;
        cin>>z;
        c.push_back(z);
    }
    
    // give ouput
    cout << "Result: " << endl;
    vector<int> ans = findCommonElements(a,b,c);
    for(int i = 0;i < ans.size();i++)
        cout<< ans[i] << " ";
    cout<< endl;    
    return 0;
}