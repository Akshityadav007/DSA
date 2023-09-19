#include<iostream>
using namespace std;

/*

    In any binary search question, we do 3 things:
    1) Get our search space i.e. low and high
    2) Get out mid and Check if the value is present at mid         -- (predicate function)
    3) Then update the code accordingly based on result of predicate function

    In this question:
    Find the rounded square root of a number in O(logn) time complexity.

    Learning: Contraction of search space

*/

int squareRoot(int n){
    int ans = -1;           // used to store answer in case of square roots lesser than required
    int low = 0,high = n;
    unsigned long long mid = low + (high - low) / 2;            // just because of temporary buffer that won't be able to store mid * mid
    while(low <= high){
        long long square = mid * mid;           // we need long long for storing value of square of this
        if(square == n)
            return mid;
        else if(square > n)
            high = mid - 1;
        else{
            ans = mid;              // this is used in case of fractional square roots. e.g. √68 = 8.xy 
            low = mid + 1;
        }
        // update mid
        mid = low + (high - low) / 2;
    }
    return ans;

}

int main(){
    int n;
    cout << "Enter the number to find its round off square root: " << endl;
    cin >> n;
    int ans = squareRoot(n);
    cout << "√" << n << " = " << ans << endl;
}


// Also solve for upto 3 decimal places