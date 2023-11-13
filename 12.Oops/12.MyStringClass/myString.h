#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>
using namespace std;

class MyString{
    private:
        char *data;             // pointer to character array data
        int length;             // length of the string
    
    public:
        // default cTor
        MyString();

        // parameterized cTor
        MyString(const char *c);

        // copy cTor
        MyString(const MyString &other);


        // destructor
        ~MyString();


        int size() const;

        bool empty() const;
    
        const char *c_str() const;                      // used while printing string

        char operator[](int index);                    // used to get character at a given index

        // find substring
        int find(const MyString &subStr) const;

        // overloading '<<' (insertion operator) for easy o/p
        friend std :: ostream &operator << (std :: ostream &os, const MyString &str);                   // ignore this (don't take too much load)

};


#endif