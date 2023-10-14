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
    2 - pointer approach
    -> ptr1 - Starting from '0' index , denotes no 'k' duplicates from 0 to ptr1 (excluding).
    -> ptr2 - Will move from ptr1 to the next 'k' elements.
            - If 'k' elements passed and all the elements of subarray (window - from ptr1 to ptr1 + k) are not same, then we'll start again i.e. ptr1 = 0.
            - Else, delete the window from string, move ptr1 a step back.
*/
bool min(int a,int b){
    if(a > b)
        return b;
    else
        return a;
}

string removeDuplicates(string s, int k) {
    if(s.size() == 1)
        return s;
    // two pointers
    int p1 = 0;
    // from '0' to 's.size() - k'
    while(p1 < s.size() - k){
        bool isKRepeating = true;               // mark next 'k' elements as repeating initially
        int p2 = p1;
        for(;p2 < p1 + k - 1;p2++){
            // if we get a character that is not repeating
            if(s[p2] != s[p2 + 1]){
                isKRepeating = false;
                break;
            }
        }
        if(isKRepeating){
            // delete the subarray (window of 'k'elements)
            s = (s.substr(0,p1) + s.substr(p2));
            p1 = 0;                             // move p1 to 0
        }
        else{
            p1++;
        }
    }
    // from 's.size() - k to s.size()'
    bool isNonRpeating = false;             // mark next 'k' elements initially as non repeating
    for(;p1 < s.size() - 1;p1++){
        if(s[p1] != s[p1 + 1]){
            isNonRpeating = true;
            break;
        }
    }
    // if all last 'k' elements of the array are repeating
    if(isNonRpeating == false){
        s = s.substr(0,s.size() - k);
    }
    return s;
}

int main(){
    string s = "deeedbbcccbdaa";
    cout << removeDuplicates(s,3) << endl;
    return 0;
}