#include<iostream>
using namespace std;

// you will need to mention column numbers while passing 2 - D array in a function
void printArray(int a[][3],int row,int col){
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// not much needed ↓
void columnWiseAccess(int a[][4],int row,int col){
    for(int i = 0;i < col;i++){
        for(int j = 0;j < row;j++){
            // column varies ; row is constant
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}

int main(){
    // declaration + initialization
    // int array-Name[rows][columns]
    int a[2][4] = {
        {1,2,3,4}, // row 1
        {5,6,7,8}  // row 2
        };
    
    /*
    in memory this is stored in form of linear array
    we can get it using formula = c * i + j where c = total no. of columns
    i.e. a[2][4] = [1,2,3,4,5,6,7,8]
    in linear form it is 2 x 4 = 8 blocks
    
    2d array index representation in memory
    (i,j) = c * i + j = a + b = index in memory
    (0,0) = 4 * 0 + 0 = 0 + 0 = 0 
    (0,1) = 4 * 0 + 1 = 0 + 1 = 1
    (0,2) = 4 * 0 + 2 = 0 + 2 = 2
    (0,3) = 4 * 0 + 3 = 0 + 3 = 3
    (1,0) = 4 * 1 + 0 = 4 + 0 = 4
    (1,1) = 4 * 1 + 1 = 4 + 1 = 5
    (1,2) = 4 * 1 + 2 = 4 + 2 = 6
    (1,3) = 4 * 1 + 3 = 4 + 3 = 7

    (use ctrl + cmd + space to choose symbols, 'therefore' symbol was entered from that panel <macOS>.)
    ∴ In memory this 2 - D array is:
    a[0] = 1
    a[1] = 2
    a[2] = 3
    a[3] = 4
    a[4] = 5
    a[5] = 6
    a[6] = 7
    a[7] = 8
    
   
   ************************************************

    From the above info we can say, that the information of no. of column is necessary for a 2-d array to function

    ∴ COLUMN NUMBERS IS A MUST TO ENTER WHILE 2 - D ARRAY (DECLARATION + INITIALIZATION)

    this means we don't really need to enter row numbers for 2 - d array!

   ************************************************
   
   */

  int b[][3] = {
    {1,2,3},
    {1,2,3}
    };

    // and this will work fine.

    // let us print both arrays || row wise access
    //printArray(a,2,4);
    printArray(b,2,3);

    // column wise access || generally not needed
    columnWiseAccess(a,2,4);
    
    return 0;
}