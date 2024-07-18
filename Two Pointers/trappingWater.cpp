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
        int left = 0;
        int right = 0;
        int totalArea = 0;


        while (left < height.size()) {
            if (height[left] == 0) {
                left++;
                continue;
            }
            right = left+1;
            if (height[right] > height[left]) {
                left++;
            }
            else {
                while (height[right] < height[left] ) { //&& height[right+1] < height[right]
                    if(right +1  == height.size())
                        return totalArea;
                    right++;
                }
                int minHeight = min(height[left], height[right]);
                for (int i = left+1; i < right; i++) {
                    totalArea += (minHeight - height[i]);
                    if(totalArea > 9) {
                        cout << left <<endl;
                        cout << right << endl;
                        cout << i << endl;
                    }
                }


                left = right;
            }
        }

        return totalArea;
    }
};

int main() {

    vector<int>heights ={0,2,0,3,1,0,1,3,2,1};

    cout << Solution::trap(heights) << endl;

}
