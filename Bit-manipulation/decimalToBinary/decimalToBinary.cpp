#include<iostream>
using namespace std;

void decToBinary(int n); // geeksforgeeks

int main(){
    int n;
    cout<< "Enter the number: " << endl;
    cin>>n;
    //cout << decimalToBinary(n) << endl;
    decToBinary(n);
    return 0;
}

// gfg
void decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
    cout<<endl;
}


// wrong solution
int decimalToBinary(int n){
    if(n <= 0)
    return 0;
    int binary = 1;
    while(n > 1){
        binary *= 10;
        binary += (n % 2);
        n = n >> 1;
    }
    return binary;
}               
// my solution  - wrong
