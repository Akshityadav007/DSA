#include<iostream>
#include<stack>
using namespace std;


// Problem || Leetcode : 1472
/*
    -> You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.
    -> Implement the BrowserHistory class:
        - BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
        - void visit(string url) Visits url from the current page. It clears up all the forward history.
        - string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
        - string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

*/


// Solution
class BrowserHistory {
public:
    stack<string> backward;         // to store all websites in back direction
    stack<string> forth;            // to store all websites in forward direction

    BrowserHistory(string homepage) {
        backward.push(homepage);
    }
    
    void visit(string url) {
        // clear all forward history
        while(!forth.empty())
            forth.pop();
        backward.push(url);
    }
    
    string back(int steps) {
        // keep transfering all websites to forward stack till 'steps'
        while(backward.size() > 1 && steps--){
            forth.push(backward.top());
            backward.pop();
        }

        return backward.top();
    }
    
    string forward(int steps) {
        // keep transferrig all websites to back stack till 'steps'
        while(!forth.empty() && steps--){
            backward.push(forth.top());
            forth.pop();
        }

        return backward.top();
    }
};


int main(){

    return 0;
}