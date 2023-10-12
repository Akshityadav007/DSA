#include<iostream>
using namespace std;

// GCD is the maximum number which can divide the numbers.
/*
    Euclid algorithm : 
        - GCD(a, b) = GCD(a - b, b)     a > b
                    = GCD(a, b - a)     a < b
*/

int getGCD(int a,int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    while(a > 0 && b > 0){
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a == 0 ? b : a;
}

// LCM * HCF = a * b        => can get LCM using this


int main(){
    int a,b;
    // a > b
    cout << getGCD(a,b) << endl;
    return 0;
}