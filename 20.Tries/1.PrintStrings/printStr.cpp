#include<iostream>
#include<vector>
using namespace std;

// Problem || Homework (solved it)
/*
    -> Given a string prefix and a trie.
    -> Print all strings stored with the given prefix in trie.
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




void printAll(vector<string> &ans, TrieNode *root, string prefix){
    // base case
    if(root -> isTerminal)
        ans.push_back(prefix);

    // traverse whole trie
    for(int i = 0;i < 256; i++){
        if(root -> children[i] != NULL){
            prefix += i;
            printAll(ans, root -> children[i], prefix);

            prefix.pop_back();                                      // backtrack
        }
    }
}

void printStrings(vector<string> &ans, TrieNode *root, string temp, string prefix){
    // base case
    if(temp.length() == 0){
        printAll(ans, root, prefix);
        return;
    }
    
    char ch = temp[0];
    int index = ch;
    TrieNode *start = root -> children[index];

    if(start != NULL)
        printStrings(ans, start, temp.substr(1), prefix);
    else
        cout << "No string with prefix '" << prefix << "' is present in trie!" << endl;
}


int main(){
    TrieNode *root = new TrieNode('-');             // root node

    insertWord(root, "donation");
    insertWord(root, "dona");
    insertWord(root, "donor");
    insertWord(root, "donate");
    insertWord(root, "car");
    insertWord(root, "care");
    insertWord(root, "caretaker");
    insertWord(root, "load");
    insertWord(root, "loader");
    insertWord(root, "love");
    insertWord(root, "lover");
    insertWord(root, "lavish");
    insertWord(root, "akshit");
    insertWord(root, "akshita");

    vector<string> ans;
    string prefix = "c";

    printStrings(ans, root, prefix, prefix);

    for(auto i: ans)
        cout << i << endl;


    return 0;
}