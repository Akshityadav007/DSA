#include<iostream>
using namespace std;


int value(char s){
    if(s  == 'I')
        return 1;
    else if(s == 'V')
        return 5;
    else if(s == 'X')
        return 10;
    else if(s == 'L')
        return 50;
    else if(s == 'C')
        return 100;
    else if(s == 'D')
        return 500;
    else if(s == 'M')
        return 1000;

    return -1;    
}

int romanToInt(string s) {
    if(s.size() == 1)
        return value(s[0]);
    // to store the ans
    int ans = 0,i = 0;
    while(i < s.size() - 1){
        // get value of the character
        int num1 = value(s[i]);
        int num2 = value(s[i + 1]);         // the number after the current number

        // if current number is lesser than next number
        if(num1 < num2){
            num1 = num2 - num1;
            i++;                            // we already have used one character
        }
        ans += num1;                    // add the number
        i++;
    }

    // for the last character
    if(i < s.size()){
        int num1 = value(s[i - 1]);
        int num2 = value(s[i]);

        // if previous number is lesser than current number
        if(num1 < num2){
            // first remove that from answer
            ans -= num1;
            // update num1
            num2 = num2 - num1;
        }
        ans += num2;
    }
    return ans;
}

int main(){


    return 0;
}