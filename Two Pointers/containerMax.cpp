//
// Created by josep on 04/07/2024.
//
//

#include <inttypes.h>
#include <string.h>
#include "cctype"
#include "vector"
#include "string"
#include "iostream"

using namespace std;

class Solution {
public:

    static int areaCalc(int a, int b, vector<int> &c) {
        return (min( c[a],c[b]) * (b-a));
    }

    static int maxArea(vector<int>& heights) {
        int leftWall = 0;
        int rightWall = 1;

        int maxArea = min(heights[leftWall], heights[rightWall]) * (rightWall - leftWall);

        while (leftWall < heights.size() - 1 ) {
            if(rightWall == heights.size()) {
                leftWall++;
                if(leftWall != heights.size() - 1)
                    rightWall = leftWall + 1;
            }
            if(areaCalc(leftWall, rightWall, heights) > maxArea)
                maxArea = areaCalc(leftWall, rightWall, heights);

            if(rightWall < heights.size())
                rightWall++;
        }

        return maxArea;

    }
};

int main() {

    vector<int>heights = {3,2,3};

    cout << Solution::maxArea(heights) << endl;
}

//linear time solutuon
//left and right pointer pointing to beginning and end index
//move pointer of wall that is smaller

