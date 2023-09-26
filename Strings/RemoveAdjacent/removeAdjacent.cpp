#include<iostream>
using namespace std;

// Problem      - Leetcode 1047

// I was able to solve this problem after relaxing my mind and writing the approach on a paper (which is a bit hard for lazy people).

/*
    -> You are given a string s consisting of lowercase English letters.
    -> Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

*/

// Solution
/*
    -> We take two pointers p1 (starting from -1) for ans, and p2 for s.
    -> We check the element at p1 i.e. ans[p1] if it is equal to s[p2].
        - If it is equal then we do (p1 - 1) and remove the last element from p1;
        - In doing so, maybe once we remove all elements from ans i.e. p1 = -1.
        - Hence, we need to first check if p1 == -1 before performing the check.
        - If p1 is not equal to -1, then we do the check else we simply add it to ans. 

*/

string removeDuplicates(string s){
    string ans;
    int ptr = -1;
    for(int i = 0;i < s.length();i++){
        if(ptr >= 0){
            if(ans[ptr]!=s[i]){
                ans+=s[i];
                ptr++;
            }
            else{
                ptr--;
                ans.pop_back();
            }
        }
        else{
            ans+=s[i];
            ptr++;
        }
    }
    return ans;
}

string removeDuplicatesLoveBabbar(string s){
    string ans;

    for(int i = 0;i < s.length();i++){
        
        if(ans.length() > 0 && ans[ans.length() - 1] == s[i]){
            ans.pop_back();
        }
        else{
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main(){
    string s;
    cout << "Enter the string: " << endl;
    cin >> s;

    cout << "Final string: " << removeDuplicates(s) << endl;

    return 0;
}