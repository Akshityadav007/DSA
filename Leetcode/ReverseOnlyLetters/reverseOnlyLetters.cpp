#include<iostream>
using namespace std;

// Problem || Leetcode : 917
/*
    Given a string s, reverse the string according to the following rules:
        - All the characters that are not English letters remain in the same position.
        - All the English letters (lowercase or uppercase) should be reversed.
        - Return s after reversing it.
*/

// Solution
/*
    Method 1:
    -> We'll have one answer string in which first we'll store "non - english letters" at their rightful place.
    -> Then we'll simply reverse the string given.

    Method 2: (In - place)
    -> Reverse by swapping
*/

string reverseOnlyLetters(string s) {
        string ans;
        for(int i = 0;i < s.size();i++){
            // push the characters other than english characters
            if(!( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') )){
                ans.push_back(s[i]);
            }
            // we have to fill letters in this place
            else{
                ans.push_back(1);
            }
        }
        int high = s.length() - 1,i = 0;
        while(high >= 0 && i < ans.size()){
            // check if the letter at 's' is english letter
            if((s[high] >= 'a' && s[high] <= 'z') || (s[high] >= 'A' && s[high] <= 'Z')){
                // if so, can it be pushed?
                if(ans[i] == 1){
                    ans[i] = s[high];
                    high--;
                }
                // shift to next position in 'ans'
                i++;
            }
            // if it is not an english letter
            else{
                // shift to next position
                high--;
            }
        }
        return ans;
}

int main(){
    string s = "ab-cd";
    cout << reverseOnlyLetters(s) << endl;
    return 0;
}