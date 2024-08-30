//
// Created by josep on 06/07/2024.
//
#include "vector"
#include "iostream"
#include "algorithm"
#include "unordered_map"
#include <set>

using namespace std;

class Solution {
public:
    static int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};

int main() {

    vector<int>heights ={0,2,0,3,1,0,1,3,2,1};

    cout << Solution::trap(heights) << endl;

}


//while (left < height.size()) {
//if (height[left] == 0) {
//left++;
//continue;
//}
//right = left+1;
//if (height[right] > height[left]) {
//left++;
//}
//else {
//while (height[right] < height[left] ) { //&& height[right+1] < height[right]
//if(right +1  == height.size())
//return totalArea;
//right++;
//}
//int minHeight = min(height[left], height[right]);
//for (int i = left+1; i < right; i++) {
//totalArea += (minHeight - height[i]);
//if(totalArea > 9) {
//cout << left <<endl;
//cout << right << endl;
//cout << i << endl;
//}
//}
//
//
//left = right;
//}
//}
//
//return totalArea;

//int left = 0;
//int right = 0;
//int totalArea = 0;
//
//while (height[right] == 0)
//right++;
//left = right; //have found a left wall
//right++;
//while (right < height.size()) {
//if (height[right] < height[left])
//right++;
//else {
//break;
//}
//}
//int minHeight = min(height[left], height[right]);
//left++;
//while (left < right) {
//totalArea += minHeight - height[left];
//left++;
//}
//
//while(right < height.size()) {
//while (height[right] > height[right-1] )
//right++;
//left = right - 1;
//while (height[right] < height[left] )
//{
//if (right >= height.size())
//return totalArea;
//right++;
//}
//minHeight = min(height[right], height[left]);
//left++;
//while ( left < right)
//{
//totalArea += minHeight - height[left];
//left++;
//}
//
//}
//
//
//return totalArea;