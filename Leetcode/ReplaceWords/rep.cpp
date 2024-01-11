#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 648
/*
    -> In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. 
    -> For example, when the root "an" is followed by the successor word "other", we can form a new word "another".
    -> Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. 
    -> If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
    -> Return the sentence after the replacement.
*/

// Solution
/*
    -> Use tries to store all dictionary elements.
    -> Get the prefix of every word of the sentence and add it to answer.
    -> In case the word isn't present in trie the prefix will be the word itself.
*/

class TrieNode{
    public:
        char val;
        bool isLeaf;
        TrieNode *children[26];

        TrieNode(char ch){
            this -> val = ch;
            this -> isLeaf = false;
            for(int i = 0;i < 26;i++)
                children[i] = NULL;
        }


        void insert(TrieNode *root, string word){
            // base case
            if(word.length() == 0){
                root -> isLeaf = true;
                return;
            }

            char ch = word[0];
            int index = ch - 'a';
            TrieNode *child;

            if(root -> children[index] != NULL)
                child = root -> children[index];
            else{
                child = new TrieNode(ch);
                root -> children[index] = child;
            }

            insert(child, word.substr(1));
        }
};


class Solution {
public:
    void getPrefix(TrieNode *root, string &prefix, string temp, string word){
        // base case
        if(root -> isLeaf || temp.length() == 0)
            return;

        int index = temp[0] - 'a';
        if(root -> children[index] != NULL){
            prefix += root -> children[index] -> val;
            root = root -> children[index];
        }
        else{
            prefix = word;
            return;
        }

        getPrefix(root, prefix, temp.substr(1), word);
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode *root = new TrieNode('$');

        // insert all dictionary words in trie
        for(auto i : dictionary)
            root -> insert(root, i);
        
        string ans = "";
        string word = "";

        for(int i = 0;i < sentence.length(); i++){
            if(sentence[i] != ' ')
                word += sentence[i];
            else{
                // search the current word's prefix in trie
                string prefix = "";
                getPrefix(root, prefix, word, word);
                ans += prefix + " ";

                word = "";                                          // reset the word
            }
        }
        // last word
        string prefix = "";
        getPrefix(root, prefix, word, word);
        ans += prefix;

        return ans;
    }
};

int main(){

    return 0;
}