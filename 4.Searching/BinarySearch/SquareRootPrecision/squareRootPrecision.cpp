//  path: Searching/BinarySearch/SquareRootPrecision
#include<iostream>
#include<math.h>
using namespace std;

// Give square root of a number upto k decimal places.

/*

    -> First we find integer part of it.    - (Revise square root by binary search)
    -> Then we calculate fractional part
        - We'll keep on adding 0.1( 10 ^ (-1) ) and try to reach as near as possible to the number
        - To move to the next digit, divide the 0.1 by 10 i.e. = 0.01.

*/

int sqRoot(int n){
    int low = 0,high = n;
    unsigned long long mid = low + ((high - low) >> 1);
    // keep storing the number
    int ans = -1;
    while(low <= high){
        unsigned long long sq = mid * mid;
        if (sq <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        mid = low + ((high - low) >> 1);
    }
    return ans;
}

double squareRoot(int n,int precision){
    double ans = 0;

    int integerPart = sqRoot(n);
    // add the integral part to ans
    ans += integerPart;
    
    // let's calculate fractional part
    double f = 0.1;
    // let's get the answer upto 'k' decimal places precision
    for(int i = 0;i < precision;i++){
        while(((ans + f) * (ans + f)) <= n){
            ans += f;
        }
        // for the next digit precision divide by 10 to go to the next fractional position
        f/=10;
    }
    return ans;
}

int main(){
    int n,precision;
    cout << "Enter the number: " << endl;
    cin >> n;
    cout << "Enter upto which place precison is needed: " << endl;
    cin >> precision;
    cout << "Square root upto 5 " << " decimal places for " << n << " is: " << squareRoot(n,precision) << endl;
    cout << "'cout' prints only upto 5 decimal places.\nHence, precise output is given by 'printf'" << endl;
    printf("Square root upto  %d decimal places for %d is: %0.*f.\n", precision, n, precision, squareRoot(n, precision));       // limit: upto 15 decimal places max
    // in the above code - '*' is used to define precision, can't use directly because 'precision' is not part of c++ library
    return 0;
}
