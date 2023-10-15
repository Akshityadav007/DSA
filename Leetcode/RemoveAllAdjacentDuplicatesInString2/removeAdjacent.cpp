#include<iostream>
using namespace std;

// Problem || Leetcode : 1209
/*
    -> You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
    -> We repeatedly make k duplicate removals on s until we no longer can.
    -> Return the final string after all such duplicate removals have been made. 
    -> It is guaranteed that the answer is unique.
*/

// Solution
/*
    Method 1:
    -> Keep adding the characters, and after adding just check if last 'k' characters from that position are same.
    -> If so, delete(pop) k characters from that position.
    -> Note : The result string size should be greater than 'k' to perfrom the check operation.
    -> TC : O(nk).
    -> SC : O(1).

    Method 2: 2 ptr approach - i,j
    -> 'i' will be placed to the position where to left of 'i' everything is fine.
    -> 'j' will traverse the array and keep checking.
    -> For checking we need to keep a count of the occurrence of characters occurring adjacently.
    -> TC : O(n).
    -> SC : O(n).
*/

string removeDuplicates(string s, int k) {
    int i = 0,j = 0;

    // to store the count/freq of the characters
    vector<int> count(s.size(),0);

    while(j < s.size()){
        s[i] = s[j];
        count[i] = 1;
        if(i > 0 && s[i - 1] == s[i]){
            count[i] = count[i] + count[i - 1];
        }
        if(count[i] == k){
            i -= k;
        }
        i++;j++;
    }
    s = s.substr(0,i);
    return s;
}

int main(){
    string s = "deeedbbcccbdaa";
    cout << removeDuplicates(s,3) << endl;
    return 0;
}