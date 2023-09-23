#include<iostream>
using namespace std;

/*

    -> Strings are dynamic sequence of characters.
    -> They are needed in case of dynamic character allocation. They also have various utilities(in-built) which aren't present with character arrays.
    -> String is also terminated at '\0'.

*/

int main(){
    // declare a string - string string_name;
    string s;
    cout << "Enter the string: " << endl;
    // to take a line with white spaces as input we use getline( <input_method> , <name_of_string>) method;
    getline(cin,s);                     // input method = cin i.e. cin refers to "character" and "in" means "input" = character input
    cout << "String: " << s << endl;
    // length of string
    cout << "Length of string: " << s.length() << endl;
    // check if string is empty
    cout << "Is the string empty?: " << (s.empty()? "Yes" : "No") << endl;
    // get character at a given index
    cout << "Character at 1 index: " << s.at(1) << endl;                // give a string of more than 1 characters
    // check the first and last character of string
    cout << "Character at first index: '" << s.front() << "' and at last: '" << s.back() << "'" << endl;

    // adding of two strings
    string s1 = "Akshit ";
    string s2 = "Yadav";
    cout << "Added string: " << s1.append(s2) << endl;              // or s1 + s2
    // Note: s1 is appended with s2, so s1 will be affected not s2.

    // ERASE function - used to erase characters from 'i' to 'j'
    // string_name.erase( <starting_index>, <how_many_characters_after_starting_index> );
    string s3 = "My Name is lakhan.";
    s3.erase(8,2);                      // 2 characters from index 8
    cout << s3 << endl;

    // INSERT function - used to insert a string at an index
    // string_name.insert( <index_at_which_string_to_be_inserted, <string_to_be_inserted> );
    string s4 = "is";               // let's add back what we erased
    s3.insert(8,s4);
    cout << s3 << endl;

    /*
        -> push_back() and pop_back() functions are also there to add or remove anything at/from the back of the string.
        -> string_name.push_back( <string_to_be_inserted> );
        -> string_name.pop_back();
        # need not implement this, it' easy.

    */

    /*
        -> FIND function - used to find a substring or sequence of characters in a string
        -> string_name.find( <string_to_be_found> );
        -> if not found it returns 'npos' i.e. no position found else it returns the first index
        # Note: we need to give the scope of string class whenever we use 'npos'
    */
    int indexOfIs = s3.find("is");
    if(indexOfIs == string::npos){
        cout << "'Is' Not found" << endl;
    }
    else{
        cout << "'Is' found at: " << indexOfIs << endl;
    }
    // let's check for a character sequence not present in string
    int indexOfWas = s3.find("was");
    if(indexOfWas == string::npos){
        cout << "'was' not found" << endl;
    }
    else{
        cout << "'was' found at: " << indexOfWas << endl;
    }

    /*
        -> COMPARE function - case sensitive
        -> string1.compare(string2)
            Compare returns:
            0 : Both are equal
            1 : Not equal
        # Note: Don't use 'str1 == str2' for strings to compare.
        # Need not implement this, it's easy
   */


   // SUBSTR function
   // str1.substr( <starting_position_of_substring>, <length_of_substring_which_is_to_be_taken_out> );
   string str1 = "I am motivated and I will do this course till the end!";
   string str2 = "course";
   cout << str1.substr(5,9) << endl;            // should give 'motivated'



    return 0;
}