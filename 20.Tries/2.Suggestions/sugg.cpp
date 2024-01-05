#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 1268
/*
    -> You are given an array of strings products and a string searchWord.
    -> Design a system that suggests at most three product names from products after each character of searchWord is typed. 
    -> Suggested products should have common prefix with searchWord. 
    -> If there are more than three products with a common prefix return the three lexicographically minimums products.
    -> Return a list of lists of the suggested products after each character of searchWord is typed.
*/

class TrieNode{
    public:
        char value;
        bool isTerminal;
        TrieNode *children[256];

        TrieNode(char ch){
            this -> value = ch;
            this -> isTerminal = false;
            for(int i = 0;i < 256; i++)
                this -> children[i] = NULL;
        }
};

void insertWord(TrieNode *root, string word){
    // base case
    if(word.length() == 0){
        root -> isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch;
    
    TrieNode *child;
    if(root -> children[index] != NULL){
        child = root -> children[index];
    }
    else{
        child = new TrieNode(ch);
        root -> children[index] = child;
    }

    insertWord(child, word.substr(1));
}



// Solution
/*

*/


int main(){

    return 0;
}