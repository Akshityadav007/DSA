#include<iostream>
using namespace std;


void solve(int arr[],int n){
    cout << sizeof(arr) << endl;        // prints 8     -- because array is passed by reference in C++ and 'arr' stores the reference of the array acting as a pointer. And pointers have size of 8 in 64 bits architecture.
}

// so, if 'arr' is acting as a pointer, we can take the input in a pointer ?
void solve2(int* ptr,int n){
    cout << sizeof(ptr) << endl;        // prints 8     -- So, we now conclude that the entire array is not passed to a function, instead the reference is passed
    
    cout << &ptr << endl;               // prints y     -- i.e. different from main(), because this pointer is a new pointer which stores address of the same array passed to it.
    cout << ptr << endl;                // print x      -- address of original array stored in pointer 'ptr'
}

int main(){
    int arr[] = {10,20,30,40,50};
    solve(arr,5);
    cout << sizeof(arr) << endl;            // prints 20

    cout << &arr << endl;                   // prints x     -- address of original array
    cout << arr << endl;                    // prints x

    solve2(arr,5);
    return 0;
}