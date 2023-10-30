#include<iostream>
using namespace std;

// Problem || GeeksForGeeks
/*
    -> A Derangement is a permutation of n elements, such that no element appears in its original position. 
    -> For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
    -> Given a number n, find the total number of Derangements of a set of n elements.
*/

// Solution
/*
    -> For a number at position '0', we can suppose keep it at positions other than the same position i.e. (n - 1) possible permutations.
    -> For placement of '0th' number, two cases:
        - Case1 : We'll swap it with number at 'ith' position.          -- (n - 2) elements left to be swapped, i.e. solve(n - 2)
        - Case2 : We'll place '0th' number at 'i', but 'ith' number can be placed at any other place.         -- (n - 1) elements left to be swapped, i.e. solve(n - 1)
    -> Take out permutation of next (n - 1) or (n - 2) numbers and add them.

    => case1 + case 2 = [(n - 1) * solve(n - 2)] + [(n - 1) * solve(n - 1)]
                      = (n - 1) * { solve(n - 2) + solve(n - 1) }
*/  

int solve(int n){
    // base case
    if(n == 1 || n == 2)
        return n - 1;

    return (n - 1) * (solve(n - 1) + solve(n - 2));
}

int main(){
    int n = 100;
    cout << solve(n) << endl;


    return 0;
}