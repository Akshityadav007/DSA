#include<iostream>
using namespace std;

// Problem || Leetcode : 2125
/*
    -> Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.
    -> There is one laser beam between any two security devices if both conditions are met:
        - The two devices are located on two different rows: r1 and r2, where r1 < r2.
        - For each row i where r1 < i < r2, there are no security devices in the ith row.
        - Laser beams are independent, i.e., one beam does not interfere nor join with another.

    Return the total number of laser beams in the bank.
*/

// Solution
/*
    -> Simply keep count of beams in each row. Maintain two counters (r1, r2), for both rows.
    -> To count the beams, first keep a check if security device is present.
    -> If security device is present in the row, toggle the checker and then increase the number of security devices(r2).
    -> Post iterating the rows, check if security devices were encountered, if so, check if it isn't the first row.
        - If it isn't the first row update the answer else only update the r1.
        - The number of beams are measured by the number of combinations that can be taken between two numbers(a,b) i.e. a * b.
*/


int numberOfBeams(vector<string>& bank) {
    int ans = 0;
    int r1 = 0,r2 = 0;                      // to count the number of beams
    for(int i = 0;i < bank.size();i++){
        string v = bank[i];
        bool hasDevice = false;               // to check if the row has no security device
        for(int j = 0;j < v.size();j++){
            if(v[j] == '1'){
                hasDevice = true;
                r2++;                   // add the number of beams     
            }
        }
        // if this row has security devices
        if(hasDevice){
            // if r1 is updated
            if(r1 > 0){
                ans += (r2 * r1);
            }
            // Case 1: r1 == 0 ; Case 2: r1 > 0
            r1 = r2;                // in both cases we need to update r1
        }
        r2 = 0;             // reset the value of r2 beams
    }
    return ans;
}

int main(){

    return 0;
}