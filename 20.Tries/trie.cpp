#include<iostream>
using namespace std;

/*   ------
    | Trie |
     ------

    -> Used for "pattern searching".
    -> Multi - way tree structure. (not n - ary tree).
    -> Root is a dummy character, forth which we insert characters.
    -> If we already have the character to be inserted in the tree, then we traverse the same path and once we get a character not matching with the character to be inserted next, we make a different branch out of it.
    -> To mark termination of a string we also need to map a boolean value to each node.

    # Real world use case : suggestions in searching.

    # Tip : Try to write your own code after understanding the concept.

    -> Insertion and searching codes are self explanatory.
    -> For deletion, we can't delete any node as there might be dependency on each node, hence we mark that particular string's isTerminal as false only.

*/

class TrieNode{
    public:
        char value;
        TrieNode *children[256];                         // array of pointers (trieNode) to map the characters
        bool isTerminal;

        TrieNode(char val){
            this -> value = val;
            this -> isTerminal = false;
            for(int i = 0;i < 256; i++)
                children[i] = NULL;
        }
};

// insertion
void insertWord(TrieNode* root, string word){
    // base case
    if(word.length() == 0){
        root -> isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch;
    TrieNode *child;
    if(root -> children[index] != NULL){
        // already present
        child = root -> children[index];
    }
    else{
        // absent
        child = new TrieNode(ch);
        root -> children[index] = child;
    }

    // recursion
    insertWord(child, word.substr(1)); 
}


bool search(TrieNode *root, string word){
    // base case
    if(word.length() == 0)
        return root -> isTerminal;
    
    // char ch = word[0];
    int index = word[0];

    TrieNode *child;
    if(root -> children[index] != NULL){
        // found
        child = root -> children[index];
    }
    else{
        // not found
        return false;
    }

    // recursion
    return search(child, word.substr(1));
}


void deletion(TrieNode *root, string word){
    // base case
    if(word.length() == 0){
        root -> isTerminal = false;
        return;
    }

    // char ch = word[0];
    int index = word[0];
    TrieNode *child;

    if(root -> children[index] != NULL)
        child = root -> children[index];
    else
        return;
    
    // recursion
    deletion(child, word.substr(1));
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

    cout << "Before deletion : " << endl;
    if(search(root, "akshit"))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;


    deletion(root, "akshit");

    cout << "After deletion : " << endl;
    if(search(root, "akshit"))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    return 0;
}