#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sortarray(int arr[],int n){
    int i = 0,j = n - 1;
    while(i < j){
        if(arr[i] == 1){
            if(arr[j] == 0){
               swap(arr[i],arr[j]);
                i++;
            }
            j--;
        }
        else{
            if(arr[j] == 1){
                j--;
            }
            i++;
        }
    }
}

void printArray(int arr[],int n){
    for(int i = 0;i < n;i++)
    cout << arr[i] << " ";
    cout << endl;
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
    sortarray(arr,n);
    printArray(arr,n);
}