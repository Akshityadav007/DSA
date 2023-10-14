#include<iostream>
using namespace std;

// Problem || Leetcode : 8
/*
    -> Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
    -> The algorithm for myAtoi(string s) is as follows:
        1) Read in and ignore any leading whitespace.
        2) Check if the next character (if not already at the end of the string) is '-' or '+'. 
           Read this character in if it is either. 
           This determines if the final result is negative or positive respectively. 
           Assume the result is positive if neither is present.
        3) Read in next the characters until the next non-digit character or the end of the input is reached. 
           The rest of the string is ignored.
        4) Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). 
           If no digits were read, then the integer is 0. 
           Change the sign as necessary (from step 2).
        5) If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. 
           Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
    
    -> Return the integer as the final result.

    -> Note:
        - Only the space character ' ' is considered a whitespace character.
        - Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
*/

// Solution
/*
   -> Basically we follow the same procedure as mentioned in the problem.
   -> We only need to check for edge cases where I failed terribly.
   -> Step 1 - We initially remove the leading spaces.
   -> Step 2 - We check if the number is positive or negative, and we remove the sign here.
   -> Step 3 - We remove zeroes, Before removing first check if the first character is a sign(edge case), we know we've already removed the sign. Now while removing we need to check if there are other characters except 0 or numbers too(edge case).
   -> Step 4 - Next start getting the number. First strip the number till only digits are present.
   -> Step 5 - Next there are two cases - The number is negative or positive (Step 2).
               - For both the cases there can be three cases:
               - Case 1: the number is more than the maximum limit of 'int'
               - Case 2: the number is within the range of 'int'
               - Case 3: the number is equal to the maximum range of 'int'
            - The issue arises only in the Case 3, where we need to take care of the last digit.
*/

    // Step 1
string removeLeadingSpace(string &s){
    int i = 0;
    // remove space
    while(s[i] == ' ' && i < s.size()){
        i++;
    }
    return s.substr(i);    
}

   // Step 2
bool checkSignAndRemoveSign(string &s){
    if(s[0] == '-'){
        s = s.substr(1);
        return true;
    }
    else if(s[0] == '+'){
        s = s.substr(1);
        return false;
    }
    else
        return false;
}

   // Step 3
string removeZeroes(string &s){
   int i = 0;
   if(i < s.size() && !(s[i] == '0' || s[i] >= '0' && s[i] <= '9'))
            return "0";
   // remove zeroes
    while(s[i] == '0' && i < s.size()){
        i++;
        // if we spot a character other than sign or numbers
        if(i < s.size() && s[i] != '0' && !(s[i] >= '0' && s[i] <= '9'))
            return "0";
    }
    return s.substr(i);
}

   // Step 4, 5
int getNumber(string &s,bool isNegative){
    string res = "";            // first we'll store the answer in a string to ensure it can be clamped later
    
    int i = (s[0] == '+' || s[0] == '-') ? 1 : 0;           // it is possible that first element might be a '+' or '-'
    
    while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
        res += s[i];
        i++;            // update i      
    }
    // Step 5 - clamping
    int ans = 0;
    if(isNegative){
        string lowerLimit = to_string(INT_MIN);
        lowerLimit = lowerLimit.substr(1);                  // removing sign 

         /*
            Three cases : 
            Case 1 : res.size() > lowerLimit.size()
            Case 2: res.size() < lowerLimit.size()
            Case 3: res.size() == lowerLimit.size()
         */

         // Case 1
         if(res.size() > lowerLimit.size()){
            return INT_MIN;
         }
         // Case 2
         else if(res.size() < lowerLimit.size()){
            int i = 0;   
            for(;i < res.size();i++){              
                  int num = res[i] - '0';             // get the digit
                  ans *= 10;                          // update the place value of ans
                  ans += num;                         // add digit to answer
            }
         }
         // Case 3
         else{
            int i = 0;   
            for(;i < res.size() - 1;i++){              
                  int num = res[i] - '0';             // get the digit
                  ans *= 10;                          // update the place value of ans
                  ans += num;                         // add digit to answer
            }
            // now for the last digit
            // if last digit of 'res' is greater than last digit of INT_MIN
            long long temp = ans;
            temp *= 10;
            temp += res[i] - '0';
            temp *= (-1);
            if(temp <= INT_MIN)
                return INT_MIN;
            // if it is lesser then
            else{
                int num = res[i] - '0';           // get the digit
                ans *= 10;                  // update the place value of ans
                ans += num;                 // add digit to answer
            }
         }
        
      ans *= (-1);
    }
    else{
        string upperLimit = to_string(INT_MAX);
         /*
            Three cases : 
            Case 1 : res.size() > upperLimit.size()
            Case 2: res.size() < upperLimit.size()
            Case 3: res.size() == upperLimit.size()
         */

        // Case 1
         if(res.size() > upperLimit.size()){
            return INT_MAX;
         }
         // Case 2
         else if(res.size() < upperLimit.size()){
            int i = 0;
            for(;i < res.size();i++){
            int num = res[i] - '0';           // get the digit
            ans *= 10;                  // update the place value of ans
            ans += num;                 // add digit to answer
            }
         }
         // Case 3
         else{
            int i = 0;
            for(;i < res.size() - 1;i++){
                  int num = res[i] - '0';           // get the digit
                  ans *= 10;                  // update the place value of ans
                  ans += num;                 // add digit to answer
            } 
            // now for the last digit
            // if last digit of 'res' is greater than last digit of INT_MIN
            long long temp = ans;
            temp *= 10;
            temp += res[i] - '0';

            if(temp >= INT_MAX){
                return INT_MAX;
            }
            // if it is lesser then
            else{
                int num = res[i] - '0';           // get the digit
                ans *= 10;                  // update the place value of ans
                ans += num;                 // add digit to answer
            }
         }
    }
    return ans;
}

int myAtoi(string s) {

    // Step 1
    s = removeLeadingSpace(s);

    // Step 2
    bool isNegative = checkSignAndRemoveSign(s);

   // Step 3
   s = removeZeroes(s);

    // Step 4, 5
    int ans = getNumber(s,isNegative);

    return ans;
}


int main(){
    string s = "   -115579378e25";
    cout << myAtoi(s) << endl;
    return 0;
}


// Lakshya 's code

int myatoi(string s){
    int num = 0, i = 0,sign = 1;//+ve;
    while(s[i] = ' '){
        i++;
    }
    if(i < s.size() && (s[i] = '-' || s[i] == '+')){
        sign = s[i] == '+' ? 1 : -1;
        ++i;
    }

    while(i < s.size() && isdigit(s[i])){
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')){
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + (s[i] - '0');
        ++i;
    }
    return num * sign;
}