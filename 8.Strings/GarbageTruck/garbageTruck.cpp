#include<iostream>
using namespace std;

// Problem || Leetcode : 2391
/*
    -> You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. 
    -> Garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. 
    -> Picking up one unit of any type of garbage takes 1 minute.
    -> You are also given a 0 - indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.
    -> There are three garbage trucks in the city, each responsible for picking up one type of garbage. 
    -> Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.
    -> Only one garbage truck may be used at any given moment. 
    -> While one truck is driving or picking up garbage, the other two trucks cannot do anything.
    -> Return the minimum number of minutes needed to pick up all the garbage.
*/

// Solution
/*
    -> We count the time for all three trucks individually.
      - We count all the required time and keep a tracker to track if garbage was picked atleast once.
      - If it wasn't, there is no need of that truck to travel.
    -> During collection we keep track of travel since last picked garbage and add it to the answer once we pick a garbage

*/

int collectGarbage(vector<string>& garbage, vector<int>& travel,char truckType){
    // track if garbage is picked
    bool garbagePicked = false;

    // keep tracking the time required
    int time = 0;
    int travelSinceLastPicked = 0;

    // we check for each string in the garbage array
    for(int j = 0;j < garbage.size();j++){
        string s = garbage[j];
        // add time required to travel here from 0
        if(j > 0)
            travelSinceLastPicked += travel[j - 1];
        for(int i = 0;i < s.length();i++){
            // check if the garbage truck is matching with the garbage type
            if(s[i] == truckType){
                garbagePicked = true;            // garbage is picked
                time++;                         // takes one minute per garbage
                time += travelSinceLastPicked;
                travelSinceLastPicked = 0;
            }
        }
    }
    // check if garbage was picked and there is need for the truck to travel
    if(garbagePicked)
        return time;
    else
        return 0;
}

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    // paper truck
    int paperTruck = collectGarbage(garbage,travel,'P');
    // glass truck
    int glassTruck = collectGarbage(garbage,travel,'G');
    // metal truck
    int metalTruck = collectGarbage(garbage,travel,'M');

    return paperTruck + glassTruck + metalTruck;
}

int main(){
    vector<string> garbage;
    garbage.push_back("G");
    garbage.push_back("P");
    garbage.push_back("GP");
    garbage.push_back("GG");

    vector<int> travel;
    travel.push_back(2);
    travel.push_back(4);
    travel.push_back(3);

    cout << garbageCollection(garbage, travel) << endl;

    return 0;
}