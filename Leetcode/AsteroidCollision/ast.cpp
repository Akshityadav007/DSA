#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


// Problem || Leetcode : 735
/*
    -> We are given an array asteroids of integers representing asteroids in a row.
    -> For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
    -> Each asteroid moves at the same speed.
    -> Find out the state of the asteroids after all collisions. 
    -> If two asteroids meet, the smaller one will explode. 
    -> If both are the same size, both will explode. 
    -> Two asteroids moving in the same direction will never meet.
*/


// Solution
/*

*/
 vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> result;

        for(int &ast : asteroids){
            if(st.empty())
                st.push(ast);
            else{
                if(st.top() > 0 && ast < 0){
                        // opposite direction (towards each other)
                        /*
                            - collision is only possible if top element moves towards right and current asteroid moves towards left.
                            - st.top() > 0 && ast < 0
                            - two cases:
                                1) st.top() > abs(ast)  -> pop
                                2) st.top() < abs(ast)  -> push
                            - above cases are only applicable as long as they move towards each other
                        */
                        while(!st.empty() && (st.top() > 0 && (st.top() < abs(ast))))
                            st.pop();
                        
                        if(st.empty()){
                            st.push(ast);           // current asteroid destroyed all
                            continue;
                        }

                        if(st.top() > 0 && (st.top() == abs(ast))){
                            st.pop();
                            continue;
                        }

                        // did top element become greater than current asteroid (moving towards each other)? -> do nothing
                        // or it started moving in different direction ?         -> push
                        if(st.top() < 0)
                            st.push(ast);
                    }
                else
                    st.push(ast);
            }

        }
        while(!st.empty()){
            result.push_back(st.top());        // Note : We didn't do push_front() because it takes O(n) time
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }


int main(){

    return 0;
}