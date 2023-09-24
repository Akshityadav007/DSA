#include<iostream>
#include<numeric>
using namespace std;

// Level: Hard (Geeksforgeeks)
// # Note: Before attempting this question please revise book allocation problem

// Problem
/*
    Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

    The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.

*/

// Solution
/*
    -> We will go exactly like book allocation.
    -> Analogy b/w the two problems:
                        Book allocation     Painter's problem
                    -   book                board
                    -   Pages               Length of the board
                    -   Student             Painter
    
    -> Difference: It is not a must that one painter must get atleast one board. (the condition to check if m > n (painters > boards) will be removed)

*/

bool isPossibleSolution(vector<int>& boards,int maximumPaint,int painters){
    int n = boards.size();
    unsigned long long lengthPainted = 0;
    int painterCount = 1;

    for(int i = 0;i < n;i++){
        if(boards[i] > maximumPaint)
            return false;
        if(lengthPainted + boards[i] > maximumPaint){
            painterCount++;
            lengthPainted = boards[i];
            if(painterCount > painters)
                return false;
        }
        else
            lengthPainted += boards[i];
    }
    return true;
}


long long minTimeToPaint(vector<int>& boards,int painters){
    // total boards
    int n = boards.size();

    // let's get total length of all boards
    unsigned long long totalLength = accumulate(boards.begin(),boards.end(),0);
    /*
        'accumulate' is part of 'numeric' header file.
        syntax: accumulate(from, end, initial_value_of_sum).
        # Note: By default it adds all members of array but we can define custome actions too by providing custom functions.
    */

   // now search space is achieved
   unsigned long long low = 0,high = totalLength;
   unsigned long long mid = low + ((high - low) >> 1);

   // answer
   unsigned long long minTime = 0;

   while(low <= high){
        // if possible solution
        if(isPossibleSolution(boards,mid,painters)){
            minTime = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        mid = low + ((high - low) >> 1);
   }

   return minTime;
}

int main(){
    vector<int> boards;
    boards.push_back(5);
    boards.push_back(10);
    boards.push_back(30);
    boards.push_back(20);
    boards.push_back(15);
    int painters = 3;

    cout << "The minimum time to paint the dog's home: " << minTimeToPaint(boards,painters) << endl;

    return 0;
}