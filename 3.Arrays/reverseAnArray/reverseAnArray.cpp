#include<iostream>
using namespace std;

void reverseArray(int *arr,int n);

int main(){
    int n;
    cout << "Enter the size of the array: "<<endl;
    cin>>n;
    if(n <= 0)
    return 0;
    cout<< " Enter the elements of the array: "<<endl;
    int arr[n];
    for(int i = 0;i < n;i++)
    cin>>arr[i];
    reverseArray(arr,n);
    cout<<"Result = "<<endl;
    for(int i = 0;i < n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

void reverseArray(int *arr,int n){
    if(n <= 1)
    return;
    int i = 0,j = n - 1;
    while(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;j--;
    }
}