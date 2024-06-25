//
// Created by joseph on 24/06/2024.
//
#include "iostream"
#include "vector"
#include "math.h"

using namespace std;


class Solution {
public:
    static int search(vector<int>& nums, int target) {
        int currentIndex = floor(nums.size() / 2);
        int arrSize = floor(nums.size() / 2);
        int leftPointer = 0;
        int rightPointer = nums.size();

        //pick number halfway between current index and end of list
        //if number bigger, discard vals to right, and vice versa
        while (leftPointer <= rightPointer)
        {

            if (nums[currentIndex] < target) {

                leftPointer = currentIndex + 1;
                currentIndex = floor((rightPointer + leftPointer)/ 2);
            }
            else if (nums[currentIndex] > target) {
                rightPointer = currentIndex -1;
                currentIndex = floor((rightPointer + leftPointer)/ 2);
            }
            else if (nums[currentIndex] == target)
                return currentIndex;

        }

        return -1;
    }
};


int main() {

    vector<int> nums = {-1};
    cout << Solution::search(nums, 12);

}