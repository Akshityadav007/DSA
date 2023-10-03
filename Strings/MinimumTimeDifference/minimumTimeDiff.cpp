#include<iostream>
#include<map>
#include<limits.h>
using namespace std;

// Problem  || Leetcode : 539
// # Couldn't solve this, although attempted it
/*
    -> Given a list of 24-hour clock time points in "HH:MM" format.
    -> Return the minimum minutes difference between any two time-points in the list.
*/

// Solution
/*
    -> First convert all time in hours
    -> Sort the array (because minimum will be achieved by difference of adjacent time)
    -> Get the minimum of the difference.

    -> There are two types of differences:
        - Moving in minor - segment
        - Moving in major - segmenet
    -> But which is the minor segment ?
    -> We take both and take minimum among them to be answer
    -> Conider one movement clockwise and the other anti - clockwise
    
    -> Basically issue comes with day and night
        - We can consider day after night or night after day
        - Both are valid, but which is the minimum consideration ?
    
*/


vector<int> getTime(vector<string> &st){
    vector<int> res;
    for(int i = 0;i < st.size();i++){
        string time = st[i];
        int hours = stoi(time.substr(0,2));
        int minutes = stoi(time.substr(3,2));
        int totalMinutes = (hours * 60) + minutes;
        res.push_back(totalMinutes);
    }
    return res;
}


int findMinDifference(vector<string> &s){
    int minDiff = INT_MAX;
    // get time in minutes
    vector<int> time = getTime(s);              // shallow copy
    // sort it
    sort(time.begin(),time.end());
    

    return minDiff;
}

int main(){
    vector<string> v;
    v.push_back("12:35");
    v.push_back("00:10");

    cout << "The minimum time difference is: " << findMinDifference(v) << endl;

    return 0;
}

// Still not working!