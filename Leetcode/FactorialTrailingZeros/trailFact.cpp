#include<iostream>
using namespace std;


// Problem || Leetcode : 
/*
    -> Given an integer n, return the number of trailing zeroes in n!.
    -> Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
*/

// Solution
 int trailingZeroes(int n) {
        int ZerosFrom5 = 0; 

        while(n >= 5){
            ZerosFrom5 += n / 5;
            n/=5;
        }
    
        return ZerosFrom5;
    }


int main(){


    return 0;
}