#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the height of array: "<<endl;
    cin>>n;
    if(n <= 0)
    return 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n + i;j++){
            if(j >= n - 1 - i)
                cout<<"* ";
            else
                cout<<"  ";
        }
        cout<<endl;
    }
    return 0;
}