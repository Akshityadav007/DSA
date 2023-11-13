#include "myString.h"
#include <cstring>                      // strcpy

// Implement definition 'string' class functions.     -> class :: function_name

// default cTor
MyString :: MyString(){
    data = new char[1];
    length = 0;
    data[0] = '\0';
}

// param cTor
MyString :: MyString(const char *str){
    data = new char[strlen(str) + 1];
    length = strlen(str);
    strcpy(data, str);
}

// copy cTor
MyString :: MyString(const MyString &other){
    data = new char[other.size() + 1];
    length = other.length;
    strcpy(data, other.data);
}

// destructor
MyString :: ~MyString(){
    delete[] data;
}


// size
int MyString :: size() const{
    return length;
}

// empty
bool MyString :: empty() const{
    return length == 0;
}


const char *MyString :: c_str() const{
    return data;
}

std :: ostream &operator << (std :: ostream &os, const MyString &str){
    os << str.c_str();
    return os;
}

// to get an element at a given index
char MyString :: operator[](int index)
{
    if(index >= length)
    {
        return '\0';
    }
    return data[index];
}


// to find first index of a substring
int MyString :: find(const MyString &subStr) const
{
    if(subStr.length > length)
        return -1;
    
    for(int i = 0;i <= length - subStr.length; i++)
    {   
        int j = 0;
        for(; j < subStr.length; j++)
        {
            if(data[i + j] != subStr.data[j]){
                break;
            }
        }

        if(j == subStr.length){
            return i;
        }
    }
    return -1;
}
