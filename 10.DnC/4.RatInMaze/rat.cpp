#include<iostream>
using namespace std;

// Problem || GeeksForGeeks : Medium
/*
    -> Consider a rat placed at (0, 0) in a square matrix of order N * N. 
    -> It has to reach the destination at (N - 1, N - 1). 
    -> Find all possible paths that the rat can take to reach from source to destination. 
    -> The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
    -> Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
    
    # Note: In a path, no cell can be visited more than one time. 
            If the source cell is 0, the rat cannot move to any other cell.
*/



// Solution
/*
    -> In this algo, we'll move in the maze using recursion.
    -> For every movement we'll have one function call. As there are 4 movements, hence 4 recursive calls.

    -> Keep track of the earlier visited places using another function/array.

*/

bool isVisited(int maze[][4], int row, int col, int sourceRow, int sourceCol, int nextRow, int nextCol, vector< vector <bool> > &visited){
    // check for all safe cases
    if(
        (nextRow >= 0 && nextRow <= row) &&              // if the next row is in - bound
        (nextCol >= 0 && nextCol <= col) &&             // if the next column is in - bound
        maze[nextRow][nextCol] == 1 &&                  // if next position is not blocked 
        visited[nextRow][nextCol] == false              // if next position is not visited earlier
    )
        return true;
    else
        return false;
}

void ratInMaze(int maze[][4],int row, int col,int sourceRow, int sourceCol, string &res, vector < vector <bool> > &visited){
    // base case
    if(sourceRow == (row-1) && sourceCol == (col-1)){
        // we reached destination
        cout << res << endl;
        return;
    }

    // for 4 movements, 4 recursive calls       -- solve one case, rest is handled by recursion

    // UP
        int nextRow = sourceRow - 1;
        int nextCol = sourceCol;
        // if not already visited
        if(isVisited(maze, row, col, sourceRow, sourceCol, nextRow, nextCol, visited)){
            // mark visited
            visited[nextRow][nextCol] = true;

            // call recursion
            res.push_back('U');
            ratInMaze(maze, row, col, nextRow, nextCol, res , visited); 

            // backtracking
            res.pop_back();
            visited[nextRow][nextCol] = false;
        }

    // DOWN
        nextRow = sourceRow + 1;
        nextCol = sourceCol;
        // if not already visited
        if(isVisited(maze, row, col, sourceRow, sourceCol, nextRow, nextCol, visited)){
            // mark visited
            visited[nextRow][nextCol] = true;

            // call recursion
            res.push_back('D');
            ratInMaze(maze, row, col, nextRow, nextCol, res , visited); 
            
            // backtracking
            res.pop_back();
            visited[nextRow][nextCol] = false;
        }

    // RIGHT
        nextRow = sourceRow;
        nextCol = sourceCol + 1;
        // if not already visited
        if(isVisited(maze, row, col, sourceRow, sourceCol, nextRow, nextCol, visited)){
            // mark visited
            visited[nextRow][nextCol] = true;

            // call recursion
            res.push_back('R');
            ratInMaze(maze, row, col, nextRow, nextCol, res , visited); 
            
            // backtracking
            res.pop_back();
            visited[nextRow][nextCol] = false;
        }

    // LEFT
        nextRow = sourceRow;
        nextCol = sourceCol - 1;
        // if not already visited
        if(isVisited(maze, row, col, sourceRow, sourceCol, nextRow, nextCol, visited)){
            // mark visited
            visited[nextRow][nextCol] = true;

            // call recursion
            res.push_back('L');
            ratInMaze(maze, row, col, nextRow, nextCol, res , visited); 
            
            // backtracking
            res.pop_back();
            visited[nextRow][nextCol] = false;
        }
}

int main(){
    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    int row = 4;
    int col = 4;

    int sourceRow = 0;
    int sourceCol = 0;

    // to track if already visited the position
    vector< vector < bool > > visited(row, vector< bool >(col, false));
    string result = "";

    // what if source position is blocked ? 
    if(maze[sourceRow][sourceCol] == 0){
        cout << "No solution exists!" << endl;
    }
    else{
        visited[sourceRow][sourceCol] = true;
        ratInMaze(maze, row, col, sourceRow, sourceCol, result, visited);
    }

    return 0;
}