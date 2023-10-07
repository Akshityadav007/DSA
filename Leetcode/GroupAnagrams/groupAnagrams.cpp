#include<iostream>
using namespace std;

// Problem || Leetcode : 49
/*
    -> Given an array of strings strs, group the anagrams together. 
    -> You can return the answer in any order.
    -> An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

*/

// Solution
/*
    -> This solution has the worst time complexity
*/

bool checkAnagram(string s1,string s2){
        // let's make frequency table for s1
        int freqTab1[256] = {0};                    // 256 because range of char is 0-255  => char is of 1 byte i.e. 8 bits. So, possible arrangement/combination of 8 bits is 2 ^ 8 = 256.
        for(int i = 0;i < s1.size();i++){
            freqTab1[s1[i]]++;
        }

        // let's make frequency Table for s2
        int freqTab2[256] = {0};
        for(int i = 0;i < s2.size();i++){
            freqTab2[s2[i]]++;
        }

        // let's match both frequency tables
        for(int i = 0;i < 256;i++){
            if(freqTab1[i] != freqTab2[i])
                return false;
        }
        return true;
    }

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;     // to store result
    
    // to mark the already inserted elements
    vector<bool> isDone(strs.size(),false);
    // we traverse the array of strings
    for(int i = 0;i < strs.size();i++){
        vector<string> v;
        if(isDone[i] == false)
            v.push_back(strs[i]);
        else
            continue;
        isDone[i] = true;
        for(int j = 0;j < strs.size();j++){
            if(strs[i].size() == strs[j].size() && isDone[j] == false){
                bool isAnagram = checkAnagram(strs[i],strs[j]);
                if(isAnagram){
                    v.push_back(strs[j]);
                    isDone[j] = true;
                }
            }
        }
        ans.push_back(v);
    }
    return ans;
}

int main(){

    return 0;
}