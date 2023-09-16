#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i = 0;i < n;i++)
    cout << arr[i] << " ";
    cout << endl;
}

// love babbar's answer
void leftShiftArray(int arr[],int n){
    int temp = arr[n - 1];
    for(int i = n - 1;i >= 0;i--)
    arr[i] = arr[i - 1];
    arr[0] = temp;
}

int main(){
    int n;
    cout<< "Enter the size of array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: "<<endl;
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    int t1 = arr[0],t2 = 0;
    for(int i = 1;i < n;i++){
        t2 = arr[i];
        arr[i] = t1;
        t1 = t2;
    }
    arr[0] = t1;
    printArray(arr,n);
    // leftShiftArray(arr,n);
    // printArray(arr,n);
}