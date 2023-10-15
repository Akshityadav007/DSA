#include<iostream>
using namespace std;

// Problem || Leetcode : 70
/*
    -> You are climbing a staircase. 
    -> It takes n steps to reach the top. 
    -> Each time you can either climb 1 or 2 steps. 
    -> In how many distinct ways can you climb to the top?
*/

// Solution
/*
    # Method 1: Recursion (TLE)
    -> Notice how we'll reach n'th stair from?
    -> Either from (n - 1)th stair or (n - 2)th stair.
    -> So, we can say that the no. of ways how we'll reach till (n - 1)th stair + the no. of ways we'll reach(n - 2)th stair will be the no. of ways we can reach 'nth' stair.
    -> i.e. f(n) = f(n - 1) + f(n - 2), where f(n) is the no. of ways we can reach 'nth' stair.

    -> Base case:
        - 0th stair : no. of ways to reach 0th stair will be only 1 (from 0 -> 0).
        - 1st stair : no. of ways to reach 1st stair will be only 1 (from 0 -> 1).

    -> Note : Program is same as fibonacci.
    
    #Method 2: DP (to be done while learning dp)
*/

int climbStairs(int n) {

}

int main(){


    return 0;
}