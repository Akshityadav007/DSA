#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// Before solving this problem, revise 'book allocation' || 'painter's partition' || 'aggressive cows'

// Problem || SPOJ : EKO
// # I solved this problem myself - NO HELP WAS TAKEN - Only previous mistakes and learnings helped!!
/*
    Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.
    Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).
    Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.
*/

// Solution

bool isPossibleBladeHeight(vector<long long> &heightOfTrees,long long currBladeHeight,long long woodToCut){
    // keep track of how much wood is cut till now
    long long woodCutYet = 0;
    for(long long i = 0;i < heightOfTrees.size();i++){
        // check if height of this tree is greater than blade height
        if(heightOfTrees[i] > currBladeHeight){
            // add the chopped wood in the wood cut till now
            woodCutYet += (heightOfTrees[i] - currBladeHeight);
            // check if we have cut the required wood
            if(woodCutYet >= woodToCut)
                return true;
        }
    }
    // we could not cut enough wood at this blade height
    return false;
}


long long maximumHeight(vector<long long> treeHeights,long long woodToCut){
    // let's get the search space - i.e. maximum height of the trees
    long long high = LONG_MIN;
    for(long long i = 0;i < treeHeights.size();i++)
        high = max(high,treeHeights[i]);
    long long low = 0;

    // store the answer
    long long bladeHeight = -1;

    while(low <= high){
        long long mid = low + ((high - low) >> 1);
        if(isPossibleBladeHeight(treeHeights,mid,woodToCut)){
            bladeHeight = mid;
            low = mid + 1;                  // need to maximise blade height
        }
        else{
            high = mid - 1;                 // maybe increased too much?
        }
    }
    return bladeHeight;
}


int main(){
    long long n,m;
    cin >> n >> m;
    vector<long long> v;
    for(long long i = 0;i < n;i++){
        long long a;
        cin >> a;
        v.push_back(a);
    }

    cout << maximumHeight(v,m) << endl;

}