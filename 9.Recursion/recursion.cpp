#include<iostream>
using namespace std;

/*
    -> Recursion - when a function calls itself directly/indirectly. (bookish)
    -> When solution of the bigger problem depends on the solution of solution of smaller problem of same type.
    -> ** Trick - Solve one case, rest others will be handled by recursion. **

    -> Three parts:
        - Base case (mandatory) is the main thing where recursion stops.
        - Recursive relation/call (mandatory).
        - Processing/operation (optional).

    -> Function call stack keeps track of all the function call.

    -> Head recursion : Function call first, processing later.
    -> Tail recursion : Function call later, processing first.

    # Note : Don't try to go in depth in recursion, you'll get lost. Just trust the recursion, it will perform it's task. If the answer is wrong you've not written the three parts of recursion correctly.
    # Of course for dry run, you'll draw the recursion tree.

    -> How to find base case ?
       - Draw the recursion tree for a smaller case. 
       - At the bottom where you can't further proceed i.e. you constraints are hit, you have your base case.
       - We should know the answer of base case already.

    -> How do calls proceed? Is it simultaneous?
        - Calls do not proceed simultaneously.
        - At a time only call is proceeded (either left or right branch).
        - For our convenience, we take left first and then right later.

*/

void print(int n){
    if(n == 0)
        return;
    print(n - 1);             // head recursion - function call first
    cout << n << endl;              // processing later
}

void printReverse(int n){
    if(n == 0)
        return;           
    cout << n << endl;                // Tail recursion - processing first
    printReverse(n - 1);             // function call later
}

int main(){

    return 0;
}