#include<iostream>
using namespace std;

/*

                        Character arrays are different from Integer arrays
-------------------------------------------------------------------------------------------------------------------

                           Integer array                           Character array
    Size            Int arrays have elements of 'int' size      Char arrays have elements of 'char' size
                    i.e. '4 bytes', so the size of 'int'        i.e. '1 byte', so the size of 'char' 
                    arrays is '4 * no. of elements'.            arrays is '1 * no. of elements'.

    Input           For loop is needed.                         No loop is needed, can take input in one
                                                                line.

    Ouput           For loop is needed.                         No loop is needed, can print the array in
                                                                one line.

    Termination     Terminated by size being out of range.      Terminated when '\0' i.e. null character ('\zero').
                                                                (ASCII of null - 0).
-------------------------------------------------------------------------------------------------------------------


*/

/*
    -> 'cin' method of taking input has delimeter '\n,\t,white space' - This means it won't take input after any one of these are given as input.
            E.g.: cin input = Akshit Yadav
                cout      = Akshit
                - It actually stopped taking input post 'Akshit' because of <white-space>.

    -> In case of character arrays, if we want to take input with 'white spaces', we need to use 'cin.getline'.

        i.e. - cin.getline( <name-of-char_array>, <maximum-input-size-that-can-be>)
        - This too has a delimeter '\n' i.e. whenever you press 'Enter' to go to next line, it stops taking input.
    
    -> This is the reason 'character arrays' are efficient than 'strings'.

*/

int main(){

    // declaration of char array of size 10
    char ch[10];
    // take input
    cout << "Enter the character array in one line: " << endl;
    cin >> ch;          // for line - cin.getline(ch,10);
    // take ouput
    cout << "Char array printing: " << ch << endl;


    return 0;
}