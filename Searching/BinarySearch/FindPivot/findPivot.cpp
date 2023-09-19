#include<iostream>
#include<vector>
using namespace std;

/*

    -> The array is sorted and rotated.
    -> Pivot element is the largest element of the array. (this is different from array question)

            example array = [12, 14, 16, 2, 4, 6, 8, 10]
    
    -> We see on plotting the elements on the graph, this can be visualized in two parts:
       - Part A = from 0 to pivot                       i.e. 0 to 2
       - Part B = from (pivot  + 1) to (n - 1)          i.e. 3 to 7

    -> Also not that both the parts are increasing in nature. (So, it is different from 'peak element' problem.)
    -> Since it is sorted array, we can apply binary search.
    -> There can be two possibilities to find pivot:
        - v[mid] < v[mid - 1]       (v[mid] = 2)     ->   return mid - 1;
        - v[mid] > v[mid + 1]       (v[mid] = 16)    ->   return mid;
        - You can check for any other element the above two conditions won't act.
    -> Now if mid is not at peak:
        - Either it could be at part A:
            - v[mid] >= v[low]                -> move left
        - Or it could be at part B:
            - v[mid] < v[low]                 -> move right

    -> Note: It is mandatory that the pivot exists! (of course it will).

    -> LEARNING: IF WE ARE DOING V[INDEX + 1] OR V[INDEX - 1], CHECK FOR 1 ELEMENT ARRAY (V = {4})

*/

int findPivot(vector<int>& v){
    // size of the array
    int n = v.size();
    int low = 0,high = n - 1;
    int mid = low + (high - low) / 2;

    while(low <= high){
        // for single element array
        if(low == high)
            return mid;
        // pivot is at mid - 1, also not we can't access v[-1]
        if(mid > 0 && v[mid] < v[mid - 1])
            return mid - 1;
        // pivot is at mid, also not we can't access v[n]
        else if(mid < (n - 1) && v[mid] > v[mid + 1])
            return mid;
        // mid is present in part A
        else if(v[mid] >= v[low]){
            low = mid + 1;
        }
        // mid is present in part B
        else{
            high = mid - 1;
        }
        // update mid
        mid = low + (high - low) / 2;
    }
    return -1;
}


int main(){
    vector<int> v;
    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;
    cout << "Enter the elements of the sorted - rotated array: " << endl;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    // result pivot index
    int pivot = findPivot(v);
    cout << "Pivot is at index: " << pivot << endl;

    return 0;
}