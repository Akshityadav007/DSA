#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Problem || Leetcode : 1475
/*
    -> You are given an integer array prices where prices[i] is the price of the ith item in a shop.
    -> There is a special discount for items in the shop. 
    -> If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i].
    -> Otherwise, you will not receive any discount at all.
    -> Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount
    

*/


// Solution
/*
    -> It is same as "next smaller element question of stack".
*/

 vector<int> finalPrices(vector<int>& prices) {
    // based on concept of the question ' next smaller element '
    vector<int> discount(prices.size(), 0);
    stack<int> st;
    st.push(-1);


    for(int i = prices.size() - 1;i >= 0; i--){
        
        // get the element smaller than current element
        while(st.top() > prices[i])
            st.pop();                                  
        

        discount[i] = st.top();              // insert the next smallest price for the current price
        st.push(prices[i]);
    }

    // now the index -1 denotes, no discount
    // let us get 'answer' array

    vector<int> ans(prices.size(), 0);

    for(int i = 0;i < discount.size(); i++){
        if(discount[i] == -1){
            // no discount
            ans[i] = prices[i];
        }
        else{
            int finalPrice = prices[i] - discount[i];
            ans[i] = finalPrice;
        }
    }
    return ans;
}



int main(){


    return 0;
}

