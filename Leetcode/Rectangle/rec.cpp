#include<iostream>
using namespace std;

// Problem || Leetcode : 223
/*
    -> Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
    -> The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
    -> The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).
*/

// Solution
// 1
vector<int> getCommonCoordinates(int ap1, int ap2, int bp1, int bp2){
    vector<int> commonPoints{0,0};              // answer

    // 4 conditions of overlapping
    // case 1
    if(ap1 < bp1 && ap2 < bp2 && bp1 < ap2){
        commonPoints[0] = bp1;
        commonPoints[1] = ap2;
    }
    // case 2
    else if(bp1 < ap1 && bp2 < ap2 && ap1 < bp2){
        commonPoints[0] = ap1;
        commonPoints[1] = bp2;
    }
    // case 3
    else if(bp1 <= ap1 && bp2 >= ap2){
        commonPoints[0] = ap1;
        commonPoints[1] = ap2;
    }
    // case 4
    else if(ap1 <= bp1 && ap2 >= bp2){
        commonPoints[0] = bp1;
        commonPoints[1] = bp2;
    }

    return commonPoints;
}

int commonArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    // X - axis
    vector<int> commonX = getCommonCoordinates(ax1, ax2, bx1, bx2);
    int commonX1 = commonX[0];
    int commonX2 = commonX[1];

    // Y - axis
    vector<int> commonY = getCommonCoordinates(ay1, ay2, by1, by2);
    int commonY1 = commonY[0];
    int commonY2 = commonY[1];

    int commonLength = abs(commonX1 - commonX2);
    int commonBreadth = abs(commonY1 - commonY2);

    return commonLength * commonBreadth;
}

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    // Total area = ( area1 + area2 ) - common area

    // area1 = area of rectangle 1
    int l1 = abs(ax1 - ax2);
    int b1 = abs(ay1 - ay2);
    int area1 = l1 * b1;

    // area2 = area of rectangle 2
    int l2 = abs(bx1 - bx2);
    int b2 = abs(by1 - by2);
    int area2 = l2 * b2;

    int totalArea = (area1 + area2) - commonArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);

    return totalArea;
}


// 2 (Another approach - doesn't effect much, only code is less)
int commonArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
        // X - axis
        int commonX1 = max(ax1, bx1);
        int commonX2 = min(ax2, bx2);

        // Y - axis
        int commonY1 = max(ay1, by1);
        int commonY2 = min(ay2, by2);

        int commonLength = commonX2 - commonX1;
        int commonBreadth = commonY2 - commonY1;

        // if overlapping, length and breadth will be +ve
        if(commonLength > 0 && commonBreadth > 0)
            return commonLength * commonBreadth;
        else
            return 0;
    }

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    // Total area = ( area1 + area2 ) - common area

    // area1 = area of rectangle 1
    int l1 = abs(ax1 - ax2);
    int b1 = abs(ay1 - ay2);
    int area1 = l1 * b1;

    // area2 = area of rectangle 2
    int l2 = abs(bx1 - bx2);
    int b2 = abs(by1 - by2);
    int area2 = l2 * b2;

    int totalArea = (area1 + area2) - commonArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);

    return totalArea;
}

int main(){


    return 0;
}