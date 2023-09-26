#include<iostream>
using namespace std;

// Problem  || Leetcode : 539
/*
    -> Given a list of 24-hour clock time points in "HH:MM" format.
    -> Return the minimum minutes difference between any two time-points in the list.
*/

// Solution
/*
    -> First convert all time in hours
    -> Sort the array (because minimum will be achieved by difference of adjacent time)
    -> Get the minimum of the difference.
*/

int findMinDifference(vector<string> &s){
    // store all time in minutes
    vector<int> v;
    for(int i = 0;i < s.size();i++){
        // get hours
        int hours = stoi(s[i].substr(0,2));             //  stoi: used to convert string to integer
        // get minutes
        int minutes = stoi(s[i].substr(3,2));           //  syntax: substr(from,no. of steps);
      
        // convert the time in minutes
        int totalTime;
        cout << hours << " " << minutes << endl;
        totalTime = (hours * 60) + minutes;
        cout << totalTime << endl;
        v.push_back(totalTime);
    }

    // sort all time
    sort(v.begin(),v.end());
    int minDiff = INT_MAX;
    for(int i = 1;i < v.size();i++){
        minDiff = min(minDiff, v[i] - v[i - 1]);
    }
    return minDiff;
}

int main(){
    vector<string> v;
    v.push_back("23:59");
    v.push_back("00:00");

    cout << "The minimum time difference is: " << findMinDifference(v) << endl;

    return 0;
}