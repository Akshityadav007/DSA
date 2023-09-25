#include<iostream>
using namespace std;

/*
    -> Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.
    -> We select the i'th element (v[i]), say it 'key', and keep checking the position of the card to be placed. 
    -> Instead of 'right' we check in the 'left' direction.
    -> Motive: Push minimum element to the leftmost position.
 
    # Focus is on the left side of the array.
*/

void insertionSort(vector<int>& v){
    int n = v.size();
    for(int i = 1;i < n;i++){
        int key = v[i];
        int j = i - 1;
        // check in the left side of 'key' in the array
        while(j >= 0 && v[j] > key){
            // keep pushing elements forward
            v[j + 1] = v[j];
            j--;
        }
        // now as we have key element, we need to store it to the leftmost position
        v[j + 1] = key;
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
    insertionSort(v);
    cout << "After sorting: " << endl;
    printArray(v);

    return 0;
}