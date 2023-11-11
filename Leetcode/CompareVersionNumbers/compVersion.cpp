#include<iostream>
using namespace std;

// Problem | Leetcode 165
/*
    -> Given two version numbers, version1 and version2, compare them.
    -> Version numbers consist of one or more revisions joined by a dot '.'. 
    -> Each revision consists of digits and may contain leading zeros. 
    -> Every revision contains at least one character. 
    -> Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. 
    -> For example 2.5.33 and 0.1 are valid version numbers.
    -> To compare version numbers, compare their revisions in left-to-right order. 
    -> Revisions are compared using their integer value ignoring any leading zeros. 
    -> This means that revisions 1 and 001 are considered equal. 
    -> If a version number does not specify a revision at an index, then treat the revision as 0. 
    -> For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

    -> Return the following:
        If version1 < version2, return -1.
        If version1 > version2, return 1.
        Otherwise, return 0.
*/

// Solution
int compareVersion(string version1, string version2) {
    // between two dots compare the number

    int s1 = 0, s2 = 0;          // to trace both the strings
    while(s1 < version1.size() && s2 < version2.size()){

        long long num1 = 0;
        long long num2 = 0;

        while(s1 < version1.size() && version1[s1] != '.'){
            num1 = num1 * 10;
            num1 += version1[s1] - '0';
            s1++;
        }

        while(s2 < version2.size() && version2[s2] != '.'){
            num2 = num2 * 10;
            num2 += version2[s2] - '0';
            s2++;
        }

        if(num1 < num2)
            return -1;

        if(num1 > num2)
            return 1;
            
        s1++; s2++;
    }

    // what if there is still strings left to be trace ?
    while(s1 < version1.size()){
        // if anywhere we get a number greater than 0
        if(version1[s1] > '0' && version1[s1] != '.')
            return 1;
        s1++;
    }

    while(s2 < version2.size()){
        // if anywhere we get a number greater than 0
        if(version2[s2] > '0' && version2[s2] != '.')
            return -1;
        s2++;
    }
    return 0;
}


int main(){


    return 0;
}