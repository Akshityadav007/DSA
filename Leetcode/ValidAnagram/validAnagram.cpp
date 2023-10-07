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
    -> Method 2 : Using mapping (frequency table)

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


bool checkAnagram(string s1,string s2){
        // let's make frequency table for s1
        int freqTab1[300] = {0};
        for(int i = 0;i < s1.size();i++){
            freqTab1[s1[i]]++;
        }

        // let's make frequency Table for s2
        int freqTab2[300] = {0};
        for(int i = 0;i < s2.size();i++){
            freqTab2[s2[i]]++;
        }

        // let's match both frequency tables
        for(int i = 0;i < 300;i++){
            if(freqTab1[i] != freqTab2[i])
                return false;
        }
        return true;
}

int main(){
    string s = "anagram",t = "nagaram";
    

    return 0;
}