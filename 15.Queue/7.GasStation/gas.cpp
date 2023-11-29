#include<iostream>
#include<queue>
using namespace std;


// Problem || Leetcode 134
/*
    -> There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
    -> You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
    -> You begin the journey with an empty tank at one of the gas stations.
    -> Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. 
    -> If there exists a solution, it is guaranteed to be unique.
*/


// Solution
/*
    # Method 1 : Brute force
     -> Check for every gas station.
     -> T.C. : O(n ^ 2)
    
    # Method 2 : Use Queue
     -> Now in brute force we were doing unneccessary repeated checks for some gas stations.
     -> For example,
        - If we have checked for 1,2,3 gas stations, and we can't reach 4th Gas station from any of them. This means we don't need to check for 1st, 2nd gas station for the second time we check
          because with the contribution of 2nd gas station too we couldn't reach 4th gas station.
        - Note : This is just an example of repeatition.
    -> We need to make sure if rear reaches front.
    -> if movement is possible, rear++;
    -> if not possible, front = rear + 1, rear = front.
    
    # Method 3 : It is not neccessary to use queue.
        -> Keep track of the amount of gas needed to travel from one gas station to another along with balance gas if it is.
        -> The place where we get our gas in deficit, we need to start from next gas station (consider) keeping the deficit gas track (because we need to have a circular nature).
        -> # Note: We are keeping track of deficit because if we have to travel across these stations the cost/gas need to be fullfilled by upcoming stations. That's why are updating 'start' point too.
        -> And at last if we balance +ve or 0 we did it, else we are in deficit i.e. -ve so we can't travel no matter from where we start.
    
*/

// We haven't used queue instead have used the concept of queue for this question
// # Method 3 : Simple solution - Two pointer
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int deficit = 0;
         int balance = 0;
         int start = 0;

         for(int i = 0;i < gas.size();i++){ // check each index if it is the answer
            balance = balance + gas[i] - cost[i];

            if(balance < 0){
                deficit += abs(balance);
                // condition breaks here, so start from this gas station
                start = i + 1;
                balance = 0;
            }
         }

         if(balance - deficit >= 0)
            return start;
        else
            return -1;
    }

int main(){


    return 0;
}