#include<iostream>
#include<vector>
using namespace std;


// Problem || Leetcode : 1023
/*
    -> Given an array of strings queries and a string pattern, return a boolean array answer where answer[i] is true if queries[i] matches pattern, and false otherwise.
    -> A query word queries[i] matches pattern if you can insert lowercase English letters pattern so that it equals the query. 
    -> You may insert each character at any position and you may not insert any characters.
*/

// Solution
/*

*/

class TrieNode{
    public:
        char val;
        bool isLeaf;
        TrieNode *children[256];

        TrieNode(char ch){
            this -> val = ch;
            this -> isLeaf = false;
            for(int i = 0;i < 256; i++)
                this -> children[i] = NULL;
        }
};

class Solution {
public:
    void insert(TrieNode *root, string word){
        // base case
        if(word.size() == 0){
            root -> isLeaf = true;
            return;
        }

        char ch = word[0];
        int index = ch;
        TrieNode *child;

        // insert only capital Letters
        if(root -> children[index] != NULL)
            child = root -> children[index];
        else{
            child = new TrieNode(ch);
            root -> children[index] = child;
        }
    
        insert(child, word.substr(1));
    }

    bool matchPattern(TrieNode *root, string s){
        // base case
        if(s.size() == 0)
            return root -> isLeaf;

        int index = s[0];

        if(root -> children[index])
            return matchPattern(root -> children[index], s.substr(1));
        else if(islower(s[0]))
            return matchPattern(root, s.substr(1));
        
        return false;
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        TrieNode *root = new TrieNode('$');
        insert(root, pattern);                              // insert pattern in trie

        for(string s : queries){
            bool res = matchPattern(root, s);
            ans.push_back(res);
        }

        return ans;
    }
};

int main(){

    return 0;
}