#include<iostream>
#include<queue>
using namespace std;

// Problem || Leetcode : 767
/*
    -> Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
    -> Return any possible rearrangement of s or return "" if not possible.
*/


// Solution
/*
    # Method 1 : Use map

    # Method 2 : Max-Heap
        -> Map the count of all characters.
        -> Take a max heap to store the string characters.
        -> Max heap will store the maximum occuring character at top.
        -> We'll insert two elements from queue at a time, to make sure we don't insert same characters together.

        -> At last if there is a single element left in heap, handle it.
            - store the element in answer and reduce the count.
            - if the element is still left to be stored, this means we can't make a string by this.
*/

class Info{
    public:
        char val;
        int count;

        Info(char ch, int cnt){
            this -> val = ch;
            this -> count = cnt;
        }
};
class compare{
    public:
        bool operator()(Info a, Info b){
            return a.count < b.count;
        }
};

class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};

        // map frequency of all characters present in string
        for(int i = 0;i < s.length(); i++)
            freq[s[i] - 'a']++;
        
        // push all characters in maxHeap
        priority_queue<Info,vector<Info>, compare> maxHeap;
        // push all character into heap, where freq > 0
        for(int i = 0;i < 26; i++){
            if(freq[i] > 0){
                Info temp(i + 'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";
        
        while(maxHeap.size() > 1){
            Info first = maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;
            ans.push_back(second.val);
            second.count--;

            if(first.count > 0)
                maxHeap.push(first);
            if(second.count > 0)
                maxHeap.push(second);
        }

        // if there is 1 element left, handle it
        if(maxHeap.size() == 1){
            Info first = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;

            if(first.count != 0)
                return "";
        }

        return ans;
    }
};


int main(){


    return 0;
}