#include<iostream>
#include "myString.h"
using namespace std;

/*
    -> We need to compile two files here:
    -> Commands for terminal:
        - Step 1) clang++ -c myString.cpp
        - Step 2) clang++ -c main.cpp
        - Step 3) clang++ -o main MyString.o main.o

    -> We bridge two cpp files - 'myString.cpp' and 'main.cpp' using 'myString.h' file

    -> If we want to compile it again after compiling the file for first time (using above steps), we can use this command:
        - clang++ -c myString.h && clang++ -c main.cpp && clang++ -o main myString.o main.o
*/

int main(){

    MyString s = "Akshit is a good boy";
    cout << s << endl;

    MyString t("Test");
    cout << t << endl;

    cout << t[2] << endl;


    cout << s.find("good") << endl;

    return 0;
}