#include<iostream>
using namespace std;

bool decreasingOrder(int &a,int &b){
    return a > b;
}

// we take row as input to compare
bool matrixComparator(vector<int> &a,vector<int> &b){
    return a[1] < b[1];     // sort according to index 1
}

void printArray(vector<int>& v){
    for(int i = 0;i < v.size();i++)
        cout << v[i] << " ";
    cout << endl;
}

void printMatrix(vector< vector <int> > &matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main(){
    vector<int> v;
    v.push_back(20);
    v.push_back(10);
    v.push_back(50);
    v.push_back(30);
    v.push_back(90);
    v.push_back(10);
    v.push_back(25);
    v.push_back(70);
    v.push_back(120);
    v.push_back(40);
    
    cout << "Before sorting: " << endl;
    printArray(v);
    sort(v.begin(), v.end(), decreasingOrder);      // by default it's increasing
    cout << "After sorting: " << endl;
    printArray(v);

    // but what of 'matrix' / ' 2 - D arrray ? 
    // by default in matrix, it sorts according to the first index element

    vector< vector<int> > matrix;

    // row 1
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(22);
    row1.push_back(10);

    // row 2
    vector<int> row2;
    row2.push_back(0);
    row2.push_back(32);
    row2.push_back(39);

    // row 3
    vector<int> row3;
    row3.push_back(4);
    row3.push_back(15);
    row3.push_back(19);

    // push rows into matrix
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    // before default sorting first let's assign matrix to another matrix by deep copying
    vector< vector<int> > m2;

    for(int i = 0;i < matrix.size();i++){
        vector<int> temp;
        for(int j = 0;j < matrix[0].size();j++){
            temp.push_back(matrix[i][j]);
        }
        m2.push_back(temp);
    }

    cout << "The matrix: " << endl;
    printMatrix(matrix);
    sort(matrix.begin(), matrix.end());
    cout << "Post sorting, the matrix: " << endl;
    printMatrix(matrix);

    cout << "Observe the first column and second column!" << endl;
    cout << "\nIf we want it to sort according to our custom comparator: ,say instead of first, sort it according to second column" << endl;
    cout << "Before: " << endl;
    printMatrix(m2);
    cout << "After: " << endl;
    sort(m2.begin(), m2.end(), matrixComparator);
    printMatrix(m2);
}