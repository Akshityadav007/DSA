#include<iostream>
using namespace std;

// Problem || Leetcode : 5
/*
    -> Given a string s, return the longest palindromic substring in s.
*/

// Solution
/*
    -> Just based on Palindromic Substring problem. Just revise that you will get what it is.
*/

pair<int,int> getStrings(string s,int low,int high){
        pair<int, int> p(s.size(),-1);
        // we need to move sideways
        while(low >= 0 && high < s.size() && s[low] == s[high]){
            p.first = low;
            p.second = high;
            low--; high++;
        }
        return p;
}

string longestPalindrome(string s) {
    // store the answer
    int lowIndex = s.size(), highIndex = -1;
    
    for(int i = 0;i < s.size();i++){
        
        // odd sized palindrome substring
        int p1 = i,p2 = i;
        pair<int, int> oddLowString = getStrings(s, p1, p2);
        int lowOddIndex = oddLowString.first;
        int highOddIndex = oddLowString.second;
        int sizeOdd = highOddIndex - lowOddIndex;
        if(sizeOdd > highIndex - lowIndex){
            lowIndex = lowOddIndex;
            highIndex = highOddIndex;
        }

        // odd palindrome strings
        p1 = i,p2 = i + 1;
        pair<int, int> evenLowString = getStrings(s, p1, p2);
        int lowEvenIndex = evenLowString.first;
        int highEvenIndex = evenLowString.second;
        int sizeEven = highEvenIndex - lowEvenIndex;
        if(sizeEven > highIndex - lowIndex){
            lowIndex = lowEvenIndex;
            highIndex = highEvenIndex;
        }
    }

    return s.substr(lowIndex,(highIndex - lowIndex) + 1);
}

int main(){
    string s = "ab";
    cout << longestPalindrome(s) << endl;

    return 0;
}