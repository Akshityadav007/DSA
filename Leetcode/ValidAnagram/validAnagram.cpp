#include<iostream>
using namespace std;

// Problem || Leetcode : 242
/*
    -> Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    # An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

// Solution
/*
    -> Method 1 : Using library
    -> Method 2 : Usnig mapping

    # It is pretty easy, so am not going to write the code, just think!
    
*/

bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        for(int i = 0;i < s.size();i++){
            int index = t.find(s[i]);
            if(index == string::npos){
                return false;
            }
            else{
                t[index] = 199;
            }
        }
        return true;
}

int main(){
    string s = "anagram",t = "nagaram";
    

    return 0;
}