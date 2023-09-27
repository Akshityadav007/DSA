#include<iostream>
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

vector<int> getHours(vector<string> &s){
    vector<int> hrs;
    for(int i = 0;i < s.size();i++){
        int h = stoi(s[i].substr(0,2));
        hrs.push_back(h);
    }
    return hrs;
}

vector<int> getMinutes(vector<string> &s){
    vector<int> mins;
    for(int i = 0;i < s.size();i++){
        int m = stoi(s[i].substr(3,2));
        mins.push_back(m);
    }
    return mins;
}


int antiClockWiseConvert(int hours, int minutes){
    return ((24 - hours)* 60) + minutes;
}

int findMinDifference(vector<string> &s){
    int minDiff = 0;


    for(int i = 1;i < s.size();i++){

    }

    return minDiff;
}

int main(){
    vector<string> v;
    v.push_back("12:35");
    v.push_back("00:10");

    cout << "The minimum time difference is: " << findMinDifference(v) << endl;

    return 0;
}