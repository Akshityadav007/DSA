#include<iostream>
#include<vector>
using namespace std;

/*
    Problem Statement:

    Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

    An integer a is closer to x than an integer b if:

    |a - x| < |b - x|, or
    |a - x| == |b - x| and a < b

*/

// I wasn't able to solve this question 
// I didn't think method 1. Instead I though method 2(that too 80%)

/*
    Method - 1: Contraction
    -> Simply we check the difference between x and v[low] and x and v[high].
    -> We need to move closer to the place where difference is least.
    -> We keep moving the pointers low and high upto a place where they have 'k' space between them (high - low = k).

    Method - 2: Expansion (using binary search)
    -> First we find the closest element to 'x' using binary search.
    -> Then we start moving in both the directions upto 'k' elements and meanwhile keep storing them.
*/

// Method 1) Two ptr approach (contraction):

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    int low = 0,high = n - 1;

    vector <int> ans;

    while (high - low >= k)
    { 
        // take differences
        int diffHigh = arr[high] - x;
        int diffLow = x - arr[low];

        // check if arr[high] is more closer to x than arr[low]
        if(diffLow > diffHigh)
            low++;
        // for diffLow == diffHigh, high-- because we should take lowesr value
        else
            high--;
    }

    while(low <= high){
        ans.push_back(arr[low]);
        low++;
    }
    return ans;
    /*
        or we could have done

        return vector<int> (arr.begin() + low,arr.begin() + high + 1);
    */
}


// Method 2) binary search (expansion):

int lowerBound(vector<int>& v,int x){
    // we need to give an index closest to the number greater than or equal to 'x'
    int low = 0,high = v.size() - 1;
    int mid = low + (high - low) / 2;;
    // need to store closest element
    int ans = high;     // storing high because in case the element is not present in the array 'end; iterator or 'end' position is returned

    while(low <= high){
        if(v[mid] < x){
            low = mid + 1;
        }
        // in case of v[mid] >= x
        else{
            // store the closest element
            ans = mid;
            high = mid - 1;
        }
        // update mid
        mid = low + (high - low) / 2;
    }
    return ans;
}

vector<int> findClosestElements2(vector<int>& v,int k,int x){
    int n = v.size();
    // using binary search to get the lower bound - an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’ and if the value is not present in the vector then it returns the end iterator .
    int high = lowerBound(v,x);
    // we need lower bound since we need to get the elements beside 'x' and assign 'low' to just before the element 'x' or lower bound of x
    int low = high - 1;

    // keep checking 'k'
    while(k--){
        // if low goes out of bound i.e. -1
        if(low < 0){
            high++;
        }
        // if high goes out of bound i.e. n
        else if(high >= n){
            low--;
        }
        else if(x - v[low] > v[high] - x){
            high++;
        }
        // at x - v[low] == v[high] - x, also we do low-- as we have to get smaller number
        else{
            low--;
        }
    }

    // enter numbers ranging from index [low + 1,high) in a vector
    return vector<int>(v.begin() + low + 1,v.begin() + high);
}



void printArray(vector<int> v){
    for(int i = 0;i < v.size();i++)
        cout << v[i] << " ";
    cout << endl;
}

int main(){
    vector<int> v;
    // [1,2,5,5,6,6,7,7,8,9]    <-- array
    //  0,1,2,3,4,5,6,7,8,9     <-- index
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(5);
    v.push_back(6);
    v.push_back(6);
    v.push_back(7);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    int x = 7;
    int k = 7;

    vector<int> ans = findClosestElements(v,k,x);   // shallow copy - referencing
    printArray(ans);

    return 0;
}