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
    // to store ans
    int ans = 0;
    // For all other methods it gives TLE, hence we'll apply 'Sieve Of Eratoshtenes'
    if(n == 0 || n == 1)
        return false;
    // let's make our sieve     -- mark all non primes
    vector<bool> prime(n,true);      // initially mark all of them prime
    prime[0] = prime[1] = false;            // 0 and 1 aren't prime

    // let's store all primes and simultaneously mark all multiples of prime as non prime
    for(int i = 2; i < n;i++){
        // if it is a prime
        if(prime[i]){
            ans++;
            // now mark all multiples of prime as false
            int j = i + i;          // start from next multiple of 'i'
            while(j < n){
                prime[j] = false;
                j = j + i;          // multiples of 'i'
            }
        }
    }
    return ans;
}

// a little improvised version
int countPrimesSieveOfEratosthenes(int n){
    int ans = 0;        // to store the answer
    vector<bool> prime(n - 1,true);
    // mark 0 and 1 as false
    prime[0] = prime[1] = false;

    // let's mark the multiples of prime nos. as false and count primes
    for(int i = 2;i *i < n;i++){
        // if it is a prime number it will be marked as false
        if(prime[i]){
            // if it is a prime, mark all it's multiples as false.
            // all i * i multiples are already marked, so we move forth them
            for(int j = i * i;i < n;j += i)
                prime[j] = false;
        }
    }
    // lastly count all of them
    for(int i = 0;i < n;i++)
        if(prime[i])
            ans++;
    return ans;
}

int main(){

    return 0;
}