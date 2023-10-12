#include<iostream>
using namespace std;

// Give 'quotient' upto k decimal places precision.  -- first go and revise square root precision

// let's get out integral part
int integralPart(int dividend,int divisor){
    int low = 0,high = dividend;
    int mid = low + ((high - low) >> 1);
    // store answer
    int integer = -1;
    while(low <= high){
        if((mid * divisor) <= dividend){
            integer = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        // update mid
        mid = low + ((high - low) >> 1);
    }
    return integer;
}

double quotient(int dividend,int divisor,int precision){
    double ans = integralPart(dividend,divisor);

    double f = 0.1;
    for(int i = 0;i < precision;i++){
        while ((ans + f) * divisor < dividend)
        {
            ans += f;
        }
        f/=10;
    }
    return ans;
}


int main(){
    int dividend, divisor,precision;
    cout << "Enter dividend: " << endl;
    cin >> dividend;
    cout << "Enter divisor: " << endl;
    cin >> divisor;
    cout << "Enter upto which place precison is needed: " << endl;
    cin >> precision;

    printf("Quotient/Answer when %d is divided by %d upto  %d decimal places is: %0.*f.\n", dividend, divisor, precision ,precision, quotient(dividend, divisor, precision));
    // in the above code - '*' is used to define precision, can't use directly because 'precision' is not part of c++ library
    
    return 0;
}