#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;


// Problem || Leetcode : 451
/*
    -> Given a string s, sort it in decreasing order based on the frequency of the characters. 
    -> The frequency of a character is the number of times it appears in the string.
    -> Return the sorted string. 
    -> If there are multiple answers, return any of them.
*/

static bool myComp(pair<char, int> &a, pair<char, int> &b){
    return a.second > b.second;
}
string frequencySort(string s) {
    unordered_map<char, int> m;     // to store frequency of each character in string
    for(char &ch : s)
        m[ch]++;
    
    string ans = "";

    // first put them in a vector
    vector< pair<char, int> > v;
    for(auto &p : m)
        v.push_back(p);

    sort(v.begin(), v.end(), myComp);

    for(pair<char, int> &p : v){
        string str = "";
        for(int i = 0; i < p.second; i++)
            str += p.first;
        ans += str;
    }
    
    return ans;
}



int main(){



    return 0;
}