#include<iostream>
using namespace std;

// Ques: Give the quotient when two numbers are divided using binary search

/*

    -> Dividend = divsior * quotient + reminder;
        
        If we remove reminder then the statement would turn:
    -> Dividend >= divisor * quotient;
        Equals when reminder = 0 , and '>' when reminder > 0

    ->  A) Hence the search space of quotient is [0,dividend)
        B) Predicate function:
            dividend >= divisor * quotient;
            We'll have 'mid' as quotient and the divisor, dividend are user inputs
        C) Updation:
            case 1: dividend == divisor * quotient
                    This means that we have found the exact answer (no decimal)
                    we will simply return it.

            case 2: dividend > divisor * quotient
                    This means we need to move towards the dividend to increase the multiplication (by increasing the quotient i.e. mid) i.e. right(high)
                    It is also a possibility this could be the nearest possible answer (as the answer might be in decimal and we don't need decimal values), hence we keep storing the variable in a variable.

            case 3: dividend < divisor * quotient
                    This means we need to move away from the dividend to decrease the multiplication (by decreasing quotient i.e. mid) i.e. left(low)
*/

// using binary search
int divide(int divisor,int dividend){
    int low = 0,high = dividend;
    int mid = low + (high - low) / 2;
    // we need to keep storing the answer
    int ans = 0;

    while(low <= high){
        // multiplication = mid * divisor
        int multiplication = mid * divisor;
        if(multiplication <= dividend){
            // keep storing the nearest answer
            ans = mid;
            // move right
            low = mid + 1;
        }
        else{
            // move left
            high = mid - 1;
        }
        // update mid (I forget this everytime)
        mid = low + (high - low) / 2;
    }
    return ans;

}

int main(){
    int divisor,dividend;
    cout << "Enter the dividend: " << endl;
    cin >> dividend;
    cout << "Enter the divisor: " << endl;
    cin >> divisor;

    // now the issue is the numbers could be either negative or positive
    // but we'll send absolute values of them and later decide the sign of quotient

    int quotient = divide(abs(divisor),abs(dividend));

    /*
        case 1: dividend < 0 and divisor > 0 or vice versa
        case 2: dividend < 0 and divisor < 0            
        case 3: dividend > 0 and divisor > 0                -- default

        for case 2 and 3, answer is going to be same.

    */

   if((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0)){
        // quotient = 0 - quotient; // love babar
        quotient *= (-1);   // me
   }

    cout << "Ans = " << quotient << endl;

}