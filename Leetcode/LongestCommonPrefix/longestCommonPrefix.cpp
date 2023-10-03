#include<iostream>
using namespace std;

// Problem || Leetcode : 14

/*
    -> Write a function to find the longest common prefix string amongst an array of strings.
    -> If there is no common prefix, return an empty string "".
*/


string getMinimum(vector<string> &st){
        int minLength = st[0].size();
        string ans = st[0];
        for(int i = 1;i < st.size();i++){
            if(st[i].size() < minLength){
                ans = st[i];
                minLength = st[i].size();
            }
        }
        return ans;
    }
string longestCommonPrefix(vector<string>& strs) {
        // get the string with minimum length
        string prefix = getMinimum(strs);
        for(int i = 0;i < strs.size();i++){
            string s = strs[i];
            for(int j = 0;j < s.size();j++){
                if(s[j] != prefix[j]){
                    prefix = prefix.substr(0,j);
                    if(prefix.empty())
                        return prefix;
                    break;
                }
            }
        }
        return prefix;
}

int main(){


    return 0;
}