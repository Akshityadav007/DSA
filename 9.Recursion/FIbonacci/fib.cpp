#include<iostream>
using namespace std;

/*
    Fibonacci series - 'nth' term is addition of last two terms i.e. terms at 'n - 1' + 'n - 2'.

*/

int fib(int n){
    // base case
    if(n == 0 || n == 1)
        return n;
    // function call + operation
    int ans = fib(n - 1) + fib(n - 2);
    return ans;                                 // i know we could've written 'return fib(n - 1) + fib(n - 2)', this is done to let you understand.
}

int main(){

    cout << fib(7) << endl;
    return 0;
}