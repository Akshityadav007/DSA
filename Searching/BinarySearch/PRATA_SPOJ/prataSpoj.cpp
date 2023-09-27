#include<iostream>
using namespace std;

// Problem || Spoj : PRATA = Roti Prata
/*
    -> IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
    -> The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function.
    -> The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). 
    -> A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete prata).
    -> (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). 
    -> The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.
*/

int main(){
    // test cases
    long long t;
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

        
    }

    return 0;
}