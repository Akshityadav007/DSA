#include<iostream>
#include<vector>
using namespace std;

// Type 4
// Level: Hard
// before this question revise nearly sorted array

/*

    Question: Given an unsorted array of elments occurring (in pair) even number of times except one element.
    
    Answer ->                    ↓
    Array = {10, 10, 2, 2, 5, 5, 2, 5, 5, 20, 20, 11, 11, 10, 10}
             ↓   ↓   ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓   ↓   ↓   ↓   ↓   ↓
    index =  0   1   2  3  4  5  6  7  8  9   10  11  12  13  14
    
    -> For observation divide the array in two:
        1) Left of the answer
            - Notice all pairs have first element at odd index and second at even index
        2) Right of the answer
            - Notice all pairs have first element at even index and second at odd index
        3) It is a surety that the answer will always be present at an even index.

    -> Now the question becomes similar to 'peak element in mountain array' question.
        Part A: 0 to answer - 1
                v[i] = v[i + 1]
        Part B: Answer to n - 1
                v[i] = v[i - 1]
        Note: Here we included answer within part B, not part A (to make it similar to 'peak element' question, otherwise we'll have to update low differently instead of high).
    -> Now we'll proceed as did in 'peak element' question
*/

int findOddOccuring(vector<int>& v){
    int n = v.size();
    int low = 0,high = n - 1;
    int mid = low + (high - low) / 2;

    while(low <= high){
        // for single element array
        if(low == high)
            return low;

        // first check the postion of mid - even or odd
        
        // mid at odd position
        if(mid & 1){
            // two cases - part A  and part B
            // we can check mid - 1 because lowest odd index is 1
            if((mid > 0) && (v[mid] == v[mid - 1])){
                // mid is present in part A
                low = mid + 1;
            }
            else{
                // mid is present in part B
                high = mid - 1;
            }
        }
        // mid at even position
        // Note: answer is present at even position, always
        else{
            // two cases - part A  and part B
            // here take care mid + 1 < n, because n - 1 is even always
            if((mid + 1) < n && (v[mid] == v[mid + 1])){
                // mid is in part A
                low = mid + 2;
            }
            else{
                // mid is in part B
                high = mid;
                // because what if mid is at the answer ? index will be lost if we do mid - 2 or mid - 1;  
            }
        }

        // update mid
        mid = low + (high - low) / 2;

    }
    return -1;
}

int main(){
    // the array :
    // v = {1,1,5,5,2,2,3,3,2,9,9,5,5,8,8}

    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(5);
    v.push_back(5);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(10);
    v.push_back(9);
    v.push_back(9);
    v.push_back(5);
    v.push_back(5);
    v.push_back(8);
    v.push_back(8);

    int ans = v[findOddOccuring(v)];
    cout << "Ans is: " << ans << endl;

    return 0;
}