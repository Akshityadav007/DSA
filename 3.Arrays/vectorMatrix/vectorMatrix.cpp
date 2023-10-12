#include<iostream>
using namespace std;

int main(){

    // normal 1 - D vector
    vector < int > v; // vector < data-type > nameOfVector;

    // initialization with a default value
    vector < int > v1(5,0); // vector < data-type > nameOfVector(sizeOfVector,default-value);

    // declaration of 2 - D vector
    vector< vector<int> > v2;

    // declaration + initialization with a default value
    // vector < vector < data-type > > nameOfVector(size,default-vector);
    vector< vector<int> > v3(5,vector<int>(10,-1));

    return 0;
}