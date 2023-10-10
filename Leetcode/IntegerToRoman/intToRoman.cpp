#include<iostream>
using namespace std;

// Problem || Leetcode : 12
/*
    -> Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
        Symbol       Value
        I             1
        V             5
        X             10
        L             50
        C             100
        D             500
        M             1000

    -> For example, 2 is written as II in Roman numeral, just two one's added together. 
        - 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
    -> Roman numerals are usually written largest to smallest from left to right. 
    -> However, the numeral for four is not IIII. Instead, the number four is written as IV. 
    -> Because the one is before the five we subtract it making four. 
    -> The same principle applies to the number nine, which is written as IX. 
    -> There are six instances where subtraction is used:
        - I can be placed before V (5) and X (10) to make 4 and 9. 
        - X can be placed before L (50) and C (100) to make 40 and 90. 
        - C can be placed before D (500) and M (1000) to make 400 and 900.

    -> Given an integer, convert it to a roman numeral.
*/

// Solution
/*
    -> We Simply first store all the pre defined roman numerals.
    -> Then for each digit we get the roman numeral and store it in an array which is later reversed to answer.
    -> Rest other things are explained in the comments.
*/


// My Method :
vector<string> getRomanTable(){

    // initially assigning all numbers "0"
    vector<string> romanTable(4000,"0");
    romanTable[1] = "I"; 
    romanTable[5] = "V"; 
    romanTable[10] = "X"; 
    romanTable[50] = "L"; 
    romanTable[100] = "C"; 
    romanTable[500] = "D"; 
    romanTable[1000] = "M";

    // now assing the 6 unique cases
    romanTable[4] = "IV"; 
    romanTable[9] = "IX"; 
    romanTable[40] = "XL"; 
    romanTable[90] = "XC"; 
    romanTable[400] = "CD"; 
    romanTable[900] = "CM"; 

    return romanTable;
}

string getRoman(vector<string>& romanTable,int number){
    string res = "";
    int i = number;

    // we search for the last pre defined roman literal
    while(i > 0 && number > 0){
        // if in the roman table pre - defined roman number exists
        if(romanTable[i] != "0"){
            res += romanTable[i];
            number = number - i;            // we need the remaining number's roman numerals
            i = number;                     // restart the loop from the remaining number
        }
        // if not move to previous number
        else{
            i--;
        }
    }
    return res;
}

string integerToRoman(int num) {
    // to store the answer
    string ans = "";
    // first we'll store it in array of strings, later reverse it
    vector<string> v;

    // first we make the roman table upto 4000 (3999 is the i/p limit)
    vector<string> roman = getRomanTable();                                 // shallow copy

    // now get the roman numerals for each digit using the same roman table
    int multiplier = 1;             // starting from ones digit

    // run a loop till the last digit of num
    while(num > 0){
        int digit = num % 10;                                       // get the digit
        string temp = getRoman(roman, digit * multiplier);          // send the place value of digit
        v.push_back(temp);                                          // store the result int array
        num /= 10;                                                  // remove the last digit of the number                 
        multiplier *= 10;                                           // update the place digit
    }

    // store the answer
    for(int i = v.size() - 1;i >= 0;i--){
        ans += v[i];
    }
    // return the answer
    return ans;
}


// A better code i found on leetcode:
class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]  = {"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

int main(){
    cout << integerToRoman(55) << endl;
    cout << integerToRoman(3) << endl;
    cout << integerToRoman(1) << endl;
    cout << integerToRoman(2) << endl;
    cout << integerToRoman(10) << endl;
    cout << integerToRoman(20) << endl;
    cout << integerToRoman(50) << endl;
    cout << integerToRoman(535) << endl;

    return 0;
}

