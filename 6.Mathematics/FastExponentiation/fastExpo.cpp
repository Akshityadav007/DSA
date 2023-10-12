#include<iostream>
using namespace std;

/*

Fast Exponentiation
    1. Normal Solution to find a ^ b. -> O(b).          -- simple multiply 'a' to itself 'b' times.
    2. Better Solution a ^ b. -> O(log b) :
        - power can be even or odd:
            - Even power can be written as (a ^ (b / 2) * 2).
            - Odd power can be written as (a ^ (b / 2) * a).
        - Using this principle we will apply divide and conquer method.

*/

int fastExpon(int a,int b){
    int ans = 1;
    while(b > 0){
        // odd             
        if(b & 1){
            ans = ans * a;          // need to multiply 'a' one more time before 
        }
        a = a * a;
        b = b >> 1;         // b = b / 2
    }
    return ans;
}

int main(){
    cout << fastExpon(5,80) << endl;

    return 0;
}