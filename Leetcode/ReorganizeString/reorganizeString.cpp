#include<iostream>
using namespace std;

// Problem || Leetcode : 767
// Couldn't do, learnt new approach greedy
/*
    -> Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
    -> Return any possible rearrangement of s or return "" if not possible.
*/

// Solution
/*
    # Method 1 : Priority Queue (to be done after we learn priority queue)
    # Method 2: Greedy 
                - In greedy approach we think greedily i.e. think about today not tomorrow.
                - This means we think first to get the answer for current case, later cases we'll deal later.

                - 1) In this question first we get the maximum number of occurring character and place then in string having atleast one space from each other(non - adjacently) in only one iteration.
                - 2) Then similarly for later cases we repeat this.
                - 3) Of course, before this we'll keep a count of all the characters in a seperate hash.
                - 4) If at any instance, the maximum occuring character goes out of bound while insertion, we return empty string as it wont' be possible to place it adjacently. (try for a case, you'll understand).

*/

string reorganizeString(string s) {
    // create a hash to keep count of the characters
    vector<int> myHash(26,0);
    for(int i = 0;i < s.size();i++){
        myHash[s[i] - 'a']++;
    }

    // get the maximum occurring character in the array
    int freq = INT_MIN;
    char maxOccuringChar;
    for(int i = 0;i < myHash.size();i++){
        if(myHash[i] > freq){
            maxOccuringChar = i + 'a';                // get the max occurring char
            freq = myHash[i];                         // assing frequency of the character
        }
    }

    // start placing in answer
    int index = 0;
    while(index < s.size() && freq > 0){                   
        s[index] = maxOccuringChar;
        freq--;
        index += 2;                             // note here we are moving i = i + 2 to place them non adjacently
    }

    // if we went out of bound while doing that and still couldn't place all characters
    if(freq > 0){
        return "";              // return an empty string
    }
    else{
        myHash[maxOccuringChar - 'a'] = 0;          // update the count/freq of max occurring character
    }

    // place the rest
    for(int i = 0;i < myHash.size();i++){
        // till all occurrences of this char are placed
        while(myHash[i] > 0){
            if(index >= s.size()){
                index = 1;                      // if index moved out of bound in earlier step move to starting
            }
            s[index] = i + 'a';
            myHash[i]--;
            index += 2;
        }
    }
    return s;
}

int main(){
    string s = "aab";

    return 0;
}