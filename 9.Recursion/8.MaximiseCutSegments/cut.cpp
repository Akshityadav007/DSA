#include<iostream>
using namespace std;

// Problem || GFG : Medium
// V. Important pattern
/*
    -> Given an integer N denoting the Length of a line segment. 
    -> You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. 
    -> Here x, y, and z are integers.
    -> After performing all the cut operations, your total number of cut segments must be maximum.

    Note: if no segment can be cut then return 0.
*/

// Solution
/*
    # Method 1 - Exploring all possible ways (Gives TLE)
    -> We'll have a recursive call for each of the integers x, y , z.
    -> 1 + recursive call - here '1' is the number of segment cut in the current recursive call.
    -> We'll get the maximum of the three calls.

    -> For base case - we need to cut it till n = 0.

    # Method 2 - DP

    # Method 3 - Bit masking (Google yourself)
*/

int maximizeTheCuts(int n, int x, int y, int z)
{
    // base case
    if(n <= 0)
        return 0;
    if(n < 0)
        return INT_MIN;                 // this is a case where we cut more than required to be cut i.e. the minimum length to be cut was more than the remaining segment length.

    // function calls
    int call1 = 1 + maximizeTheCuts(n - x, x, y, z);
    int call2 = 1 + maximizeTheCuts(n - y, x, y, z);
    int call3 = 1 + maximizeTheCuts(n - z, x, y, z);

    // now the result will be the maximum of the all three cases.
    return max(call1, max(call2, call3));

}

int main(){
    int n = 4;
    int x = 1,y = 1, z = 1;
    cout << maximizeTheCuts(n, x, y, z) << endl;



    return 0;
}