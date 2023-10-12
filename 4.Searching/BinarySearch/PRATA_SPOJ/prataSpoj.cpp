#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Problem || Spoj : PRATA = Roti Prata
// Couldn't solve this
/*
    -> IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
    -> The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function.
    -> The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). 
    -> A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete prata).
    -> (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). 
    -> The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.
*/

// Solution
/*
    -> Given the cooks cook prata according to their ranks,
        - First prata in 'R' minutes => 2nd prata in 2 * R minutes => 3rd prata in 3 * R minutes....
        - Therefore total minutes taken by a cook of 'R' rank to cook 'n' prata:
            total minutes = 1R + 2R + 3R + 4R + 5R .....   nR
            total minutes = R * (1 + 2 + 3 + 4 + 5 + ....n)          -- taking R common
            total minutes = R * (n * (n + 1) / 2)

    -> Now minimum time to cook 'n' parata = 0
    -> So, we can say our answer lies between 0 to Rmax * (n * (n + 1) / 2)         -- 'n' is fix for all cooks, so to maximise the nmber of minutes 'R' should be max
    -> Search space = 0 to Rmax * (n * (n + 1) / 2)

    -> Now we need to search for the minimum time taken to cook the prata
    -> Applying binary search,
        - check if any cook can cook prata in 'mid' minutes (store mid in answer)             -- i.e. check possible solution
        - if yes, we need to check for 'time' lesser than mid => move towards low
        - if no, we need to check for 'time' greater than mid => move towards higher

    -> How to check if cooks can cook prata in time?
        - Start from the best cook i.e. Rank 1
        - If it can cook all prata withing time limit (mid) then cool otherwise pass the next prata to next cook, i.e. Rank 2
        - So, in parallel to Rank 1 cook Rank 2 cook will also cook.
        - Similary if rank 2 cook exceeds time limit pass the rest prata to next cooks and so on...
        - If at a time no cooks remain for prata to be cooked, we need more time, so it is not a possible solution.                     -- move towards high
*/

bool canCook(vector<int> cookRanks,int p, int timeLimit){
    int prataMade = 0;          // to track prata made till now.
    for(int i = 0; i < cookRanks.size(); i++){
        // let's check for cooks
        int timeTaken = 0;          // to track the time taken by the cook to cook the prata
        int timer = 1;
        while(timeTaken <= timeLimit){
            // if the next prata can be made within time limit
            if(timeTaken + (timer * cookRanks[i]) <= timeLimit){
                prataMade++;
                timeTaken += cookRanks[i] * timer;
                timer++;
            }
            else
                break;
        }
        // check if required number prata are made
        if(prataMade >= p)
            return true;
    }
    // ran out of cooks - need more time
    return false;
}

int minimumTime(vector<int> cookRanks,int p){
    // to store the answer
    int ans = -1;
    // let's get our search space 
    int Rmax = *max_element(cookRanks.begin(),cookRanks.end());     // *max_element() -- gives maximum element in vector
    int low = 0,high = Rmax * (p * (p + 1) / 2);            // high = last rank cook * prata * (prata + 1) / 2
    while(low <= high){
        int mid = low + ((high - low) >> 1);

        // if cooks can cook prata in 'mid' time
        if(canCook(cookRanks,p,mid)){
            ans = mid;          // store the answer
            high = mid - 1;     // move towards low to minimise the time
        }
        // if cooks can't cook in 'mid; time
        else{
            low = mid + 1;      // increase the time
        }
    }
    return ans;
}

int main(){
    // test cases
    int t;
    cin >> t;
    while(t--){
        // no. of prata
        int p;
        cin >> p;
        // no. of cooks
        int l;
        cin >> l;
        // ranks of l cooks
        vector<int> cooksRanks;
        for(int i = 0;i < l;i++){
            int r;
            cin >> r;
            cooksRanks.push_back(r);
        }
        cout << minimumTime(cooksRanks,p) << endl;
    }
    return 0;
}