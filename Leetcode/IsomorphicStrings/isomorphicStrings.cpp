#include<iostream>
using namespace std;

// Problem || Leetcode : 205
// similar to 'Decode Message' and 'Find and replace'
/*
    -> Given two strings s and t, determine if they are isomorphic.
    -> Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    -> All occurrences of a character must be replaced with another character while preserving the order of characters. 
    -> No two characters may map to the same character, but a character may map to itself.
*/

// Solution
/*
    -> This can be done using mapping i.e. bringing both the strings to a common rule
*/

// below function creates a common rule for all strings
vector<char> mapping(string str){
    vector<char> c(200,0);
    char start = 'a';
    for(int i = 0;i < str.size();i++){
        if(c[str[i]] == 0){
            c[str[i]] = start;
            start++;
        }
    }
    // mapping done
    return c;
}

bool isIsomorphic(string s, string t) {
    // map both to a common rule
    vector<char> mappingS = mapping(s);
    vector<char> mappingT = mapping(t);
    
    // now match both mappings
    for(int i = 0;i < s.length();i++){  // can use either s.length() or t.length()
        if(mappingS[s[i]] != mappingT[t[i]])
            return false;
    }
    return true;
}

int main(){

    return 0;
}