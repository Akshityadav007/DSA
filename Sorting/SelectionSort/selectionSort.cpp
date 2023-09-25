#include<iostream>
using namespace std;

/*
    -> Put the minimum element it at the right position.
    -> From i to (n - 1), pick the smallest number and swap it with 'ith' element.

    # Basically picking up smallest element from the right and keeping it to the left
    # In this, we store index of minimum element
    # Focus is on the right side of the array

*/

void selectionSort(vector<int>& v){
    int n = v.size();
    // move from 'i' to n - 1;
    for(int i = 0;i < n - 1;i++){
        // to store the minimum element from 'i' to 'n - 1'
        int indexOfMini = i;
        for(int j = i + 1;j < n;j++){
            if(v[indexOfMini] > v[j])
                indexOfMini = j;
        }
        // swap them
        swap(v[indexOfMini],v[i]);
    }
}


void printArray(vector<int>& v){
    for(int i = 0;i < v.size();i++)
        cout << v[i] << " ";
    cout << endl;
}

int main(){
    vector<int> v;
    v.push_back(20);
    v.push_back(10);
    v.push_back(50);
    v.push_back(30);
    v.push_back(90);
    v.push_back(10);
    v.push_back(25);
    v.push_back(70);
    v.push_back(120);
    v.push_back(40);

    cout << "Before sorting: " << endl;
    printArray(v);
    selectionSort(v);
    cout << "After sorting: " << endl;
    printArray(v);

    return 0;
}