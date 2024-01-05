#include<iostream>
using namespace std;

/*      ---------------------
       | Dynamic Programming |
        ---------------------

    -> Dynamic Programming is mainly an optimization over plain recursion.

        "   Those who forget their mistakes are condemned to repeat it!   "
    
    -> It is a technique of problem solving which are of type:
        a) Overlapping sub - problem -> Solving problem which has been solved earlier (didn't store it's result)
        b) Optimal sub - structure -> When a bigger problem's optlimal solution depends on same type of small problem.
        
        E.g. : Fibonacci number.

    -> " Once a problem is solved, don't solve it again (as result of that has been stored). "

    -> Two ways to solve dp problems:
        1) Top - down approach  (Recursion)            -----  Memoization
        2) Bottom - up approach (iterative)            -----  Tabulation
        3) Patterns

        # There is a possibility that "top down" approach might not work (slower than bottom up approach) sometimes. #
*/

// 1) Top - down approach
/*
    Step 1 => Create a dp array.
    Step 2 => Store/return answer in dp array.
    Step 3 => If the answer is already present (stored earlier), return it (instead of solving further).
*/

// 2) Bottom - up approach
/*
    Step 1 => Create a dp array.
    Step 2 => Fill the starting elements in dp array (observing base case).
    Step 3 => Fill rest elements of dp array using logic/formula of recursive relation.
*/


int main(){

    return 0;
}