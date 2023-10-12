#include<iostream>
using namespace std;

/*
    # Also known as:
        - Doubling Search
        - Galloping Search
        - Strazik Search
*/

/*
        -> Array should be sorted
        -> This type of search is done in arrays with very large size (infinte or unbounded array).
        -> We mainly are decreasing the search space (sub-array) in the array (than the regular binary search), to improve efficiency by a little.
        
        -> Limiting our search space,
            - Start from index = 1.
            - Check if v[index] is lesser than target element:
                Case 1: v[index] <= target
                        In this case we double the index
                        # catch: we could get out of range while doubling, need to handle that.
                Case 2: v[index] > target
                        In this case we have reached the 'high' point of our search space, we break the loop.
        -> Apply binary search on the limited search space found.
                        
*/

int binarySearch(vector<int>& v,int low,int high,int target){
    int mid = low + (high - low)/ 2;
    while(low <= high){
        if(v[mid] == target)
            return mid;
        else if(v[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
        // update mid
        mid = low + (high - low) / 2;
    }
    return -1;
}

int modifiedBinarySearch(vector<int>& v,int target){
    int n = v.size();
    // let's get the limited search space
    if(v[0] == target)
    return 0;
    // starting index from 1 because, if index = 0 then 0 * 2 = 0 ; => infinite loop
    int index = 1;
    // check if index is within range && if v[index] is lesser than target element
    while(index < n && v[index] <= target){
        // keep doubling the index
        index = index * 2;              // can do *3 or *4 too, but search space/range of [low,high] will increase in that case
    }
    
    // now we have got 'high' i.e. at index
    // for 'low' we go back to the previous index stage, where v[index] was still lesser than target element i.e. index / 2
    int low = index / 2;
    int high = min(index, n - 1);       // 'min' in case of index went out of range while doubling

    return binarySearch(v,low,high,target);
}

int main(){
    vector<int> v;
    int n = 100000;
    // inserting elements from 1 to 100000
    for(int i = 0;i < n;i++)
        v.push_back(i + 1);
    // target element
    int target = 450;

    // search for target
    int ans = modifiedBinarySearch(v,target);
    if(ans!= -1)
        cout << "Element found at index: " << ans << endl ;
    else
        cout << "Element not found!" << endl;
    

    return 0;
}