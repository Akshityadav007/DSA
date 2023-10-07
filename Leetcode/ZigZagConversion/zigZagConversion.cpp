#include<iostream>
using namespace std;

// Problem || Leetcode : 6
/*
    -> The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
        P   A   H   N
        A P L S I I G
        Y   I   R
    -> And then read line by line: "PAHNAPLSIIGYIR"
    -> Write the code that will take a string and make this conversion given a number of rows:
        - string convert(string s, int numRows);
*/

// Solution
/*
    Note: From i = 0 to i = row - 1 -> straight line
          From i = row - 1 to i = 0 -> diagonal line

    -> Consider this a matrix of characters.
    -> Simply keep putting the string characters as said i.e.
        - when i reaches last row, change the column and start diagonal - j++,i--
        - when i reaches starting (0) of row, stop changing columns and start row changing - i++.

    -> Note: Handle corner cases like for single row or single element array.

*/

 string convert(string s, int numRows) {
    if(s.size() == 1 || numRows == 1)
        return s;
    vector<char> t(s.size(),' ');              // maximum column length can be of the string
    vector< vector < char> > v(numRows,t);       // matrix to for output
    
    int i = 0,j = 0;          // pointer for matrix
    int p = 0;                 // pointer for string

    // run the loop till end of string is reached
    while(s[p] != '\0'){

        // from i = 0 to i = numRows - 1 (last row - excluding)            -> i++, j constant
        for(;i < (numRows - 1) && s[p] != '\0';i++){
            v[i][j] = s[p];
            p++;
        }

        // from i = numRows - 1 (last row - including) to i = 0 (excluding)        -> i-- & j++
        for(;i > 0 && s[p] != '\0';i--,j++){
            v[i][j] = s[p];
            p++;
        }
    }

    // now store the matrix in a string
    string ans = "";
    for(int i = 0;i < v.size();i++){
        vector<char> temp = v[i];
        for(int j = 0;j < temp.size();j++)
            if(v[i][j] != ' ')
                ans += v[i][j];
    }

    // return the answer
    return ans;
}

int main(){
    string s = "A";
    int numRows = 1;
    cout << convert(s,numRows) << endl;

    return 0;
}