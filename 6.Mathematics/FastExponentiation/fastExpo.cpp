#include<iostream>
using namespace std;


// Problem || Leetcode : 50
/*

Fast Exponentiation
    1. Normal Solution to find a ^ b. -> O(b).          -- simple multiply 'a' to itself 'b' times.
    2. Better Solution a ^ b. -> O(log b) :
        - power can be even or odd:
            - Even power can be written as a ^ b = (a ^ ((b / 2) * 2)).
            - Odd power can be written as  a ^ b = (a ^ ((b / 2) * 2) * a).
        - Using this principle we will apply divide and conquer method.

*/

int fastExpon(int a,int b){
    int ans = 1;
    while(b > 0){
        // odd               
        if(b & 1){
            ans = ans * a;          // need to multiply 'a' to 'ans' one more time if odd power
        }
        a = a * a;                  // square 'a'   -- 
        b = b >> 1;                 // b = b / 2
    }
    return ans;
}

int main(){
    cout << fastExpon(3,5) << endl;

    return 0;
}