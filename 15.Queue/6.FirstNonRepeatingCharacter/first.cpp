#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Problem || Leetcode : 387
/*
    -> Given a string s, find the first non-repeating character in it and return its index. 
    -> If it does not exist, return -1.
*/

// Solution
/*
    # Method 1 : Use hashmap

    # Method 2 : Use queue
        -> Use a queue to keep track of characters
        -> Remove all multiple occurring character
        -> The character at front of the queue will be the answer.

*/

// Method : 2
int firstUniqChar(string s) {
    queue<int> q;
    vector<int> freq(26,0);

    for(int i = 0; i< s.length();i++){
        freq[s[i] - 'a']++;
        q.push(i);
        
        // find the answer
        while(!q.empty()){
            int frontCharacter = s[q.front()];
            // multiple occurence
            if(freq[frontCharacter - 'a'] > 1)
                q.pop();
            else
                break;
        }
    }
    if(q.empty())
        return -1;
    else
        return q.front();
}

int main(){


    return 0;
}