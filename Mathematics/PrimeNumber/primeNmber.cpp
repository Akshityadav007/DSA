#include<iostream>
using namespace std;

// Problem || Leetcode : 204
/*
    -> Given an integer n, return the number of prime numbers that are strictly less than n.
*/

// Solution

/*
    Prime Number methods:
    1) Naive                            -- checking one by one
    2) Sqrt Approach                    -- checking prime till i * i < n                    -> Gives TLE

    3) Sieve of Eratosthenes:
        - We take a boolean array from 2 to n - 1 to mark prime numbers        
        - Initially we consider all of them as prime and thus mark 'true' to all          -- (mark 0 and 1 as 'false')
        - Then we start assigning the multiples of prime numbers as 'false' ( because they can't be prime )
        - Now we simply need to count all the element marked as 'true' in the array and return.
        - The array made is called - 'Sieve'.

    4) Segmented Sieve  - count prime in a given range [low,high].
*/

int countPrimesSieveOfEratosthenes(int n){
    int ans = 0;        // to store the answer
    vector<bool> prime(n - 1,true);
    // mark 0 and 1 as false
    prime[0] = prime[1] = false;

    // let's mark the multiples of prime nos. as false and count primes
    for(int i = 2;i < n - 1;i++){
        // if it is a prime number it will be marked as false
        if(prime[i]){
            ans++;
        }
        int j = 2;
        while(j < n){
            prime[j] = false;
            j = j + i;              // go to next multiple of 'i'
        }
    }
    return ans;
}


int main(){

    return 0;
}