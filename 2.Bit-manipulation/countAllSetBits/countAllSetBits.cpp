#include<iostream>
using namespace std;

int main(){
    int n;
    cout<< "Enter the number: " << endl;
    cin>>n;
    int count = 0;
    for(int i = 0;i < 32;i++){
        if(n & (1 << i))
        count++;
    }
    cout << count << endl;
}