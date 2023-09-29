#include<iostream>
//#include<string>
using namespace std;

// Problem || Leetcode : 1910
// I gave brute force approach because I had not revised the 'string' code. So, didn't use library functions.

/*
    -> Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
    -> Find the leftmost occurrence of the substring part and remove it from s.
*/

// Brute force - O(n^2) - Gives TLE
string removeOccurrences(string s, string part) {
    string ans;
    // first we run a loop from '0' to 's.length()'
    int i = 0;
    while(i < s.length()){
        // we check if this is a substring part
        if(s[i] == part[0]){
            int j = 0;
            while(j < part.length()){
                if(s[i + j] != part[j])
                    break;
                j++;
            }
            if(j == part.length())
                i+=j;
        }
        else{
            ans.push_back(s[i]);
            i++;
        }
    }
    return ans;

}

// Optimized
string removeOccurrences2(string s,string part){
    int i = 0;
    while(s[i] != '\0'){
        int indexOfPart = s.find(part);
        if(indexOfPart >= 0 && indexOfPart < s.length()){
            s.erase(indexOfPart, part.length());
        }
        else{
            return s;
        }
    }
    return s;
}

string removeOccurrencesLoveBabbar(string s,string part){
    // till 'part' is present in the string, run a loop
    while(s.find(part)!= string::npos){
        // erase the substring if it is found
        s.erase(s.find(part), part.length());
    }
    return s;
}


int main(){
    string s = "abdfhsabcfjdkaabc";
    string substring = "abc";

    cout << "Final string: " << removeOccurrences2(s,substring) << endl;


    return 0;
}