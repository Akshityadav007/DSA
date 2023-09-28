#include<iostream>
using namespace std;

// Problem || Leetcode : 2325
// This is my solution, but love babbar's solution was simple and easier (refer to 'find and replace' problem to understand mapping).
/*
    You are given the strings key and message, which represent a cipher key and a secret message, respectively. 
    The steps to decode message are as follows:

    -> Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
    -> Align the substitution table with the regular English alphabet.
    -> Each letter in message is then substituted using the table.
    -> Spaces ' ' are transformed to themselves.
    -> For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), 
       we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
*/

// Solution
/*
    -> First we need to get the substitution table to compare.
    -> Then we need to build the key table and make sure that the letters don't get repeated.
    -> Lastly decode the message, we simply check the index of the current letter in the key table and store that index.
    -> Then we check the same index letter in the subtitution table and add it to the answer.
*/

string decodeMessage(string key, string message) {
    // create a substitution table
    string substitutionTable = "";
    for(char c = 'a' ; c <= 'z'; c++){
        substitutionTable += c;
    }

    // prepare key table
    string keyTable = "";

    for(int i = 0;i < key.size();i++){
        // if the character is not already added into the keyTable && it is not a white space
        if(keyTable.find(key[i]) == string::npos && key[i] != ' '){
            keyTable += key[i];
        }
    }
    // now let's start decoding the message
    string decoded = "";
    for(int i = 0;i < message.size();i++){
        if(message[i] == ' ')
            decoded += message[i];
        else{
            int posInKeyTable = keyTable.find(message[i]);
            decoded += substitutionTable[posInKeyTable];
        }
    }
    return decoded;
}

int main(){
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";

    cout << decodeMessage(key,message) << endl;


    return 0;
}
