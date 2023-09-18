#include <iostream>
#include<vector>
using namespace std;

void printArray(vector<int>& v){
    for(int i = 0;i < v.size();i++)
        cout << v[i] << " ";
    cout << endl;
}

// THIS QUESTION IS NOT PRESENT ON LEETCODE (NORMAL)


vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int n = a.size(),m = b.size(),k = c.size();
    // two pointer approach
    int p1 = 0,p2 = 0;
    // temproray array to store all common elements among a and b
    vector<int> temp;
    // travserse both arrays

    while(p1 < n && p2 < m){
        if(a[p1] == b[p2]){
            if (temp.empty()) {
                temp.push_back(a[p1]);
            }
            else{
                if (a[p1] != temp[temp.size() - 1]) {
                temp.push_back(a[p1]);
                }
            }
            p1++;p2++;
        }
        else if(a[p1] < b[p2])
        p1++;
        else
        p2++;
    }

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

// geeks for geeks (doesn't pass 2 cases)
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
    // answer array/vector
    vector<int> ans;
    
    // three pointer approach
    int i = 0,j = 0,k = 0;
    
    while(i < n1 && j < n2 && k < n3){
        if(A[i] == B[j] && B[j] == C[k]){
            // if answer array is empty we can't check last element for duplicate
            if(ans.empty()){
                ans.push_back(A[i]);
            }
            else{
                // taking care of duplicate elements
                if(A[i]!=ans[ans.size() - 1]){
                    ans.push_back(A[i]);
                }
            }
            i++;j++;k++;
        }
        else{
            // find the smallest element among three
            if(A[i] < B[j]){
                i++;
            }
            else if(B[j] < C[k]){
                j++;
            }
            else{
                k++;
            }
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
    vector<int> a;
    vector<int> b;
    vector<int> c;
    cout << "Enter the values of a: " << endl;
    for(int i = 0;i < n;i++){
        int z;
        cin>>z;
        a.push_back(z);
    }
    cout << "Enter the values of b: " << endl;
    for(int i = 0;i < m;i++){
        int z;
        cin>>z;
        b.push_back(z);
    }
    cout << "Enter the values of c: " << endl;
    for(int i = 0;i < k;i++){
        int z;
        cin>>z;
        c.push_back(z);
    }

    // inputs for geeks for geeks
    int A[n],B[m],C[k];
    for(int i = 0;i < n;i++){
        A[i] = a[i];
    }
    for(int i = 0;i < m;i++){
        B[i] = b[i];
    }
    for(int i = 0;i < k;i++){
        C[i] = c[i];
    }

    // give ouput
    vector<int> ans = findCommonElements(a,b,c);
    cout << "Result(coding ninjas): " << endl;
    printArray(ans);  

    vector<int> ansGfg = commonElements(A,B,C,n,m,k);
    cout << "Result from geeks for geeks: " << endl;
    printArray(ansGfg);
    return 0;
}