#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

// Problem || Leetcode : 179
// Couldn't do it. Was going too deep. Learnt Custom comparator.
/*
    -> Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
    -> Since the result may be very large, so you need to return a string instead of an integer.
*/

// Solution
/*
    -> Solve using custom comparator
    -> We first convert the whole array to a string
    -> Then we sort it using custom comparator to sort it in descending order
    -> Strings are sorted in lexicographical order.
    -> We need to customize the custom comparator so that it gives us our desired result

    -> While customising we should add a, b in both ways and return the greatest.
    -> For eg. a = 30 , b = 3
        - Here a + b = 303 and b + a = 330

    -> Edge case : nums is filled with 0 i.e. the largest number is 0.

*/

static bool myComp(string &a,string &b){
    return (a + b) > (b + a);                              
}

string largestNumber(vector<int>& nums) {
    // to store the answer
    string ans = "";

    // convert nums to string array
    vector<string> v;
    for(auto i: nums)
        v.push_back(to_string(i));

    // now sort it using custom comparator
    sort(v.begin(),v.end(), myComp);

    if(v[0] == "0")
        return "0";
    
    // send it to the answer
    for(auto s: v)
        ans += s;

    return ans;
}

int main(){

    return 0;
}