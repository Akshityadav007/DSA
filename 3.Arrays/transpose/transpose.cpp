#include<iostream>
#include<vector>
using namespace std;

vector< vector <int> > transpose(vector< vector<int> >& matrix) {
        // m X n matrix
        int m = matrix.size(); // size of rows
        int n = matrix[0].size(); // size of columns

        // declare the answer matrix (n X m)
        vector< vector<int> > ans;

        // assign all 0 rows to ans
        for(int i = 0;i < n;i++){
            vector<int> row(m,0);
            ans.push_back(row);
        }

        // now insert the rows of matrix as columns in ans
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++)
                ans[j][i] = matrix[i][j];
        }
        
        return ans;
}

void printArray(vector<vector<int> >& v){
    int row = v.size();
    int col = v[0].size();
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector< vector<int> > v;
    cout << "Insert the size of the rows: " << endl;
    int rows = 0,col = 0;
    cin >> rows;
    cout << "Insert the size of columns: " << endl;
    cin >> col;
    for(int i = 0;i < rows;i++){
        vector<int> temp;
        for(int j = 0;j < col;j++){
            cout << " Enter the v[" << i << "]" << "[" << j << "]" << " element: " << endl;
            int a;
            cin >> a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }
    vector< vector<int> > ans = transpose(v);
    printArray(ans);
}