#include<iostream>
using namespace std;

// my solution - right and similar to geeksforgeeks (after decimal to binary wrong solution).
int binaryToDecimal(int n){
    int num = 0,power = 0;
    while(n > 0){
        int k = n % 10;
        k = k * (1 << power);
        num += k;
        power++;
        n/=10;
    }
    return num;
}

int main(){
    int n;
    cout<< "Enter the number: " << endl;
    cin>>n;
    cout << binaryToDecimal(n) << endl;
    return 0;
}