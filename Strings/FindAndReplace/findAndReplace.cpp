#include<iostream>
#include<map>
using namespace std;

// Problem || Leetcode : 890
// Try this again with map
/*
    -> Given a list of strings words and a string pattern, return a list of words[i] that match pattern.
    -> You may return the answer in any order.
    -> A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
    -> Recall that a permutation of letters is a bijection from letters to letters: 
        - every letter maps to another letter, and no two letters map to the same letter.
*/

// Solution
/*
    -> We will create mapping for both 'pattern' and 'words[i]' with substitution table.
    -> Substitution table = 'a - z'.

*/

// basically this function normalises all strings to a common rule
void createMapping(string& s){
    // start from 'a'
    char start = 'a';
    // take any size of array greater than 127 (because there are 127 characters in ascii table) and assign all to 0
    char mapping[200] = {0};
    for(auto c: s){
        if(mapping[c] == 0){
            mapping[c] = start;
            start++;                // move to next character i.e. if start was 'a' move to 'b'
        }
    }

    // update the string
    for(int i = 0;i < s.length();i++){
        char ch = s[i];             // take out the character from string at 'i' index
        s[i] = mapping[ch];         // update 'i'th character in string from mapping
    }
} 

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    // pattern mapping & update it
    createMapping(pattern);         

    // to store the answer
    vector<string> ans;
    for(auto s: words){
        // update string to the common mapping/rule as that of pattern
        string temp = s;
        createMapping(temp);  
        if(temp == pattern)
            ans.push_back(s);
    }
    return ans;
}

int main(){
    vector<string> words;       // "abc","deq","mee","aqq","dkd","ccc"
    words.push_back("abc");
    words.push_back("deq");
    words.push_back("mee");
    words.push_back("aqq");
    words.push_back("dkd");
    words.push_back("ccc");

    string pattern = "abb";

    vector<string> ans = findAndReplacePattern(words,pattern);      // shallow copying

    for(auto s: ans)
        cout << s << endl;

    return 0;
}