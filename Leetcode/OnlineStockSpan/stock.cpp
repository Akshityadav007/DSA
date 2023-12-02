#include<iostream>
#include<stack>
using namespace std;


// Problem || Leetcode :901
/*
    -> Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
    -> The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

    -> For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
    -> Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
    -> Implement the StockSpanner class:

        - StockSpanner() Initializes the object of the class.
        - int next(int price) Returns the span of the stock's price given that today's price is price.
*/

// Solution
/*
    # Method 1 : Brute Force (TLE)
        -> Simply keep pushing the elements in stack and then count the earlier pushed elements.
        -> After that push the elements back to the stack earlier popped.
*/

// Method 1
class StockSpanner {
public:
    stack<int> st;          // to store the prices
    StockSpanner() {            
    }
    
    int next(int price) {
        st.push(price);
        int ans = 0;
        stack<int> tempStack;              // to store elements to push back

        // pop all numbers smaller than or equal today's price
        while(!st.empty() && st.top() <= price){
            ++ans;
            tempStack.push(st.top());
            st.pop();
        }
        while(!tempStack.empty()){
            st.push(tempStack.top());
            tempStack.pop();
        }
        return ans;
    }
};


// Method 2


int main(){

    return 0;
}