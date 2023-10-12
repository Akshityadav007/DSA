#include<iostream>
using namespace std;

void swapByTemp(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swapByArithmetic(int &a,int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void swapByXOR(int &a,int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main(){
    int a,b;
    cout << "Enter the two numbers: " << endl;
    cin >> a >> b;

    cout << "a = " << a << ", b = " << b << endl;
    // assigning a to x and b to y so that they may not give unwanted results for other swapping methods
    int x = a,y = b;
    swapByTemp(x,y);
    cout << "Swap by temp: \n a = " << x << ", b = " << y << endl;

    x = a,y = b;
    swapByArithmetic(x,y);
    cout << "Swap by artihmetic: \n a = " << x << ", b = " << y << endl;

    x = a,y = b;
    swapByXOR(x,y);
    cout << "Swap by XOR: \n a = " << x << ", b = " << y << endl;

    return 0;
}