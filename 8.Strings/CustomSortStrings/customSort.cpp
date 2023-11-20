#include<iostream>
#include<algorithm>
using namespace std;


// Problem || Leetcode : 791
// Couldn't solve, obviously learnt a new thing!!
/*
    -> You are given two strings order and s. 
    -> All the characters of order are unique and were sorted in some custom order previously.
    -> Permute the characters of s so that they match the order that order was sorted. 
    -> More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
    -> Return any permutation of s that satisfies this property.
*/

// Solution
/*
    # We need to use custom comparator here.
    # In leetcode we made 'str' global by putting it outside class  'solution' and made compare 'static' function

    -> We sort using custom comparator.
    -> In custom comparator we compare it from the 'order' string. 
        - We check the position of both the characters in 'order' string and place the character at smaller position first.
*/

// create a global variable to compare the order
string str;
bool compare(char &a, char &b){
    // return true if 'a' is at a position lesser than 'b' in 'order' string
    // and on returning true, character 'a' is placed before character 'b' in result string.
    return (str.find(a) < str.find(b));
}

string customSortString(string order, string s) {
        // sort the string using custom comparator
        str = order;            // add order to global variable
        sort(s.begin(),s.end(), compare);
        return s;
}

int main(){
    string s = "abcd";
    string order = "cba";

    cout << customSortString(order, s) << endl;

    return 0;
}