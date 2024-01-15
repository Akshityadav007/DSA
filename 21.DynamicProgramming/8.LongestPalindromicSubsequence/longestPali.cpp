#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Problem || Leetcode : 516
/*
    -> Given a string s, find the longest palindromic subsequence's length in s.
    -> A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
*/



// Solution
/*  
    -> Can solve using the 'longest common subsequence' question.

    -> simply put, reverse the given string ans get the length of longest common subsequence of both.

*/

class Solution {
public:
    int solveUsingTabulationSO(string &text1,string &text2){
        // step 1 : dp array
        int n = text1.size();
        int m = text2.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for(int index2 = m - 1; index2 >= 0; index2--){
            for(int index1 = n - 1; index1 >= 0; index1--){
                int ans = 0;

                 if(text1[index1] == text2[index2])
                    ans = 1 + next[index1 + 1];
                else
                    ans = 0 + max(next[index1], curr[index1 + 1]);
                
                curr[index1] = ans;
            }

            // shifting
            next = curr;
        }

        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(), a.end());

        int ans = solveUsingTabulationSO(a, s);
        return ans;
    }
};

int main(){


    return 0;
}