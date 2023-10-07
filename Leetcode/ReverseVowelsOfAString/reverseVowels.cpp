#include<iostream>
using namespace std;

// Problem || Leetcode : 345
/*
    -> Given a string s, reverse only all the vowels in the string and return it.
    -> The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
*/

// Solution
/*
    -> Simple swap all vowels
*/

string reverseVowels(string s) {
    int low = 0, high = s.size() - 1;
    // vowels
    string lowerVowels = "aeiou";
    string upperVowels = "AEIOU";

    // get high to a vowel first from rear end
    while(high >= 0){
        // once we find a vowel
        if(lowerVowels.find(s[high]) != string::npos || upperVowels.find(s[high]) != string::npos)
            break;
        high--;
    }

    // we swap all vowels
    while(low < high){
        // if we have found a vowel at low
        if(lowerVowels.find(s[low]) != string::npos || upperVowels.find(s[low]) != string::npos){
            swap(s[low],s[high]);

            // get high to a vowel
            while(low < high){
                high--;
                // once we find a vowel
                if(lowerVowels.find(s[high]) != string::npos || upperVowels.find(s[high]) != string::npos)
                    break;
            }
        }
        low++;
    }
    return s;
}

int main(){

    return 0;
}