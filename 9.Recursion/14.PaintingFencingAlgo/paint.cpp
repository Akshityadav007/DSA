#include<iostream>
using namespace std;

// Problem || GeeksForGeeks
/*
    -> Given a fence with n posts and k colors,
    -> find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. 
    -> Since the answer can be large return it modulo 10^9 + 7.
*/

// Solution
/*
    -> Two cases for last two posts:
        - 1) Colored with same colors.
        - 2) Colored with different colors.

    -> Case 1: Same color.
        - Last two posts have 'k' colors, hence there are 'k' choices.
        - Rest other posts will become f(n - 2) - as total posts were 'n' and now 2 have been fixed, hence rest others' result will be f(n - 2).
        - For the rest posts, there are (k - 1) choices - as 1 has already been taken from 'k' colors and we can't make it 3 in a row.
        - Hence, Ans (other posts) = f(n - 2) * (k - 1), for rest posts.

    -> Case 2: Different color.
        - If we write the different colors for a small 'n', we observe that the answer in this case depends on the answer of last result of 'same color(case 1)' & 'different color(case 2) as well.
        - diff = (k - 1) * (case 1(prev) + case 2(prev))
        - f(n) = (k - 1) * f(n - 1)
                             ↓
        - f(n) = (k - 1) * f(n - 2) + (k - 1) * f(n - 1)
        - f(n) = (k - 1) * [f(n - 1) + f(n - 1)]
     
*/

int getPaintWays(int n, int k){
    // base case
    if(n == 1)
        return k;
    if(n == 2)
        return k * (k - 1);
    return (k - 1) * (getPaintWays(n - 1, k) + getPaintWays(n - 2, k));
}

int main(){
    int n = 3,k = 2;
    cout << getPaintWays(n,k) << endl;

    return 0;
}