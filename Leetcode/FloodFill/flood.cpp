#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 733
/*
    -> An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
    -> You are also given three integers sr, sc, and color.
    -> You should perform a flood fill on the image starting from the pixel image[sr][sc].
    -> To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on.
    ->  Replace the color of all of the aforementioned pixels with color.
    -> Return the modified image after performing the flood fill.
*/

// Solution
/*
    -> Somewhat similar to number of islands.
    -> Visited is here needed because if old and new color are same then it will go to infinite loop. Hence, we can handle that case separately.
*/

class Solution {
public:
    bool isSafe(int newX, int newY, int oldColor, vector<vector<int>> &image){
        if(newX >= 0 && newY >= 0 && newX < image.size() && newY < image[0].size() && image[newX][newY] == oldColor)
            return true;
        return false;
    }
    void dfs(vector<vector<int>>& image, int oldColor, int newColor, int sr, int sc){
        // change color
        image[sr][sc] = newColor;

        // move in all directions = top, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0;i < 4; i++){
            int newDx = sr + dx[i];
            int newDy = sc + dy[i];

            if(isSafe(newDx, newDy, oldColor, image))
                dfs(image, oldColor, newColor, newDx, newDy);
            
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // am doing in place, you can do the other way too
        int oldColor = image[sr][sc];
        int newColor = color;
        if(oldColor == newColor)
            return image;
        dfs(image, image[sr][sc], color, sr, sc);

        return image;
    }
};

int main(){

    return 0;
}