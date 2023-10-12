#include <iostream>
#include <vector>
using namespace std;

// THIS QUESTION IS NOT AVAILABLE ON LEETCODE
// This question wasn't solved by me, this was completely solved by Code Help

vector<int> factorial(int N){
    // declare ans vector
    vector<int> v(1,1);
    for(int i = 2;i <= N;i++){
        int carry = 0;
        for(int j = 0;j < v.size();j++){
            int n = v[j] * i + carry;
            int digit = n % 10;
            v[j] = digit;
            carry = n / 10;
        }
        while(carry > 0){
            v.push_back(carry % 10);
            carry/=10;
        }
    }
    // now reverse the answer vector
    reverse(v.begin(),v.end());
    return v;
}

int main() {
    int n;
    cout << "Enter the number " << endl;
    cin>>n;
    vector<int> ans = factorial(n);
    cout << "Resut = ";
    for(int i = 0;i < ans.size();i++)
        cout << ans[i];
    cout << endl;
    return 0;
}