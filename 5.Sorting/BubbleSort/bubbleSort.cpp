#include<iostream>
using namespace std;

// sorting in ascending order
/*
    -> Bubble sort is a sorting algorithm that compares two adjacent elements and swaps them until they are in the intended order.
    -> Basically comparing 'n' elements of array of 'n' sized 'n' times.
    -> Swapping is done if arr[i] > arr[i + 1]

    # The motive of this algo is to move largest element to the right

*/

void bubbleSort(vector<int>& v){
    // size of array
    int n = v.size();
    for(int i = 0;i < n;i++){
        // n - i, because after every 'i' iteration we place the largest element to the right most position, so we don't need to go to the position we already put the right element at the right position.
        for(int j = 0;j < n - i - 1;j++){
            if(v[j] > v[j + 1])
                swap(v[j],v[j + 1]);
        }
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
    bubbleSort(v);
    cout << "After sorting: " << endl;
    printArray(v);

    return 0;
}