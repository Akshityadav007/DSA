#include<iostream>
using namespace std;

void printArray(int arr[], int size, int index){
    // base case
    if(index >= size){
        cout << endl;
        return;
    }

    // operation
    cout << arr[index] << " ";

    // recursive call
    printArray(arr,size,index + 1);
}

// we can also take array as pointer too, works same
// print array in reverse order
void reversePrintArray(int *arr, int size, int index){
    // base case
    if(index >= size){
        return;
    }

    // recursive call
    reversePrintArray(arr,size,index + 1);

    // operation
    cout << arr[index] << " ";
    if(index == 0)                                                  // this one i just did to make the o/p look cleaner
        cout << endl;
}

int main(){
    int arr[5] = {10,20,30,40,50};
    printArray(arr,5,0);
    reversePrintArray(arr,5,0);
    return 0;
}