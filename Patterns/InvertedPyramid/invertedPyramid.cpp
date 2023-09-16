#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the height of array: "<<endl;
    cin>>n;
    if(n <= 0)
    return 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < (n * 2) - 1 - i;j++){
            if(j >= i)
            cout << "* ";
            else
            cout<<"  ";
        }
        cout<<endl;
    }
    return 0;
}