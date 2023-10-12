#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i = 0;i < n;i++)
    cout << arr[i] << " ";
    cout << endl;
}


int main(){
    int n,k;
    cout<< "Enter the size of array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: "<<endl;
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    cout << "Enter number of times shift 'k':" << endl;
    cin>>k;
    for(int j = 0;j < k;j++){
        int temp = arr[0];
        for(int i = 0;i < n - 1;i++){
            arr[i] = arr[i + 1];
        }
        arr[ n - 1] = temp;
    }
    printArray(arr,n);
    
}