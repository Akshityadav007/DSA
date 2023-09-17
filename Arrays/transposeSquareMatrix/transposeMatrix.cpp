#include<iostream>
using namespace std;

// return dynamic array pointer
int** transpose(int a[][4], int row, int col) {
  int** t = new int*[col];
  // assign columns for every row
  for (int i = 0; i < col; i++) {
    t[i] = new int[row];
  }

    // make the transpose matrix
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      t[j][i] = a[i][j];
    }
  }

  return t;
}

void printDynamicArray(int **a,int row,int col){
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void printArray(int a[][4],int row,int col){
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// using swap - space complexity - O(1) < only for sqaure matrix >
void swapTranspose(int a[][4],int row,int col){
    for(int i = 0;i < row;i++){
        // accessing upper triangle
        for(int j = i + 1;j < col;j++){
                int temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
        }
    }

    // below formula takes more time and means same

    // for(int i = 0;i < row;i++){
    //     for(int j = 0;j < col;j++){
    //         if(i < j){
    //             int temp = a[i][j];
    //             a[i][j] = a[j][i];
    //             a[j][i] = temp;
    //         }
    //     }
    // }
}

// well it's actually better to use vector instead of this dynamic array in my view

int main(){
    int a[][4] = {
        {1,2,3,4},
        {5,6,7,8}
    };
    // int **t = transpose(a,2,4);
    // printDynamicArray(t,4,2);

    int b[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    cout << "\nBefore transpose: \n" << endl;
    printArray(b,4,4);
    swapTranspose(b,4,4);
    cout << "\nPost transpose: \n" << endl;
    printArray(b,4,4);
    cout << endl;
    return 0;
}