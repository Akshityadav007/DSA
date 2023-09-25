#include<iostream>
using namespace std;

// Level: Hard (Geeksforgeeks)
// I got to understand this by solving Leetcode 1011: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// Problem
/*
    You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book. 
    Out of all the permutations, the goal is to find the permutation where the student with the most books allocated to him gets the minimum number of pages, out of all possible permutations.

    Note: Return -1 if a valid assignment is not possible.
*/


// Solution

// check if the allocation of 'mid' number pages is feasible for 'm' students
bool isAllocationFeasible(vector<int> &v,int mid,int students){
        // number of books
        int n = v.size();
        // to count number of students allocated with books till now
        int studentsCount = 1;                  // starting with 1 because first student will have to be allocated with books
        // to track allocated pages to the current student
        int allocatedPages = 0;                 // starting with 0 because till now we haven't started allocation    

        // start allocation
        for(int i = 0;i < n;i++){

            // what if the number of pages of a book is greater than 'mid' number of pages ?
            if(v[i] > mid){
                return false; 
            }      // allocation is not possible for this - we need to allocate atleast one book
            
            // what if no more books can be allocated to the current student
            if(allocatedPages + v[i] > mid){
                // we need to stop allocation to the current student and forward it to next student
                studentsCount++;
                // reset the allocated pages to the current pages of the book - because it is being forwarded to next student and we don't need the allocated pages to the previous student to add to this
                allocatedPages = v[i];
                // check the student count too
                if(studentsCount > students){
                    return false;           // we don't have any student left to allocate the 'mid' number of pages
                }
            }
            
            // otherwise add the current book pages to the allocated pages to the current student till now
            else{
                allocatedPages += v[i];
            }
        }  

        // if no breaking point was triggered, this means allocation was successful!
        return true;

}

/*

    -> First we calculate maximum how many pages we can allocate i.e. sum of all pages.
    -> Now, we know for sure that the answer (i.e. 'minimum number of pages') will lie between 0 to sum.
    -> As we see this is a monotonic function, we can apply binary search to find the 'minimum number of pages'.

    -> Now we need to check for the allocation for every number at mid.
        - try to allocate 'mid' number of pages to the 'm' students.
        - There will be two cases:
            Case 1: Allocation is feasible
                    -> In this case, we try to minimise the number of pages being allocated to students.
            Case 2: Allocation is not feasible -
                    -> In this case, we try to increase 'mid' to ensure more number of pages are allocated to 'm' students.

*/
int allocateMinimum(vector<int>& v,int m){
    int n = v.size();

    // what if number of students to allocate 'm' are greater than the number of books 'n' to be allocated?
    if(m > n)
    return -1;

    // let's find sum of all pages or if there is 1 student to allocate
    int sumOfPages = 0;
    for(int i = 0;i < n;i++)
        sumOfPages+=v[i];

    // to store the ans
    int minimumNumberOfPages = 0;

    // ans can be anywhere from 0 to sumOfAllPages
    // let's apply binary search in the search space
    int low = 0,high = sumOfPages;
    int mid = low + ((high - low) >> 1);  // or low + (high - low) / 2;

    while(low <= high){
            // Two Cases:
            // Case 1: Allocation feasible -
            if(isAllocationFeasible(v,mid,m)){
                // store the answer
                minimumNumberOfPages = mid;
                // also we need to minimise our search area to get the least number of pages allocated to the student with maximum number of books
                // so we go left
                high = mid - 1;
            }
            // Case 2: Allocation not feasible
            else{
                //  we need to increase the 'mid' number, to get more pages to allocate to a student
                // so we go right
                low = mid + 1;
            }
        // update mid - i.e. get a new minimum number of pages to allocate
        mid = low + ((high - low) >> 1);
    }

    return minimumNumberOfPages;

}

int main(){
    vector<int> v;
    v.push_back(12);
    v.push_back(34);
    v.push_back(67);
    v.push_back(90);
    int m = 2;

    int ans = allocateMinimum(v,m);
    if(ans == -1)
    cout << "Invalid allocation!" << endl;
    else
    cout << "Minimum number of pages allocated: " << ans << endl;

    return 0;
}
