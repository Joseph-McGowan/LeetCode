//
// Created by josep on 21/05/2024.
//
#include <algorithm>

#include "vector"
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {

        unordered_map<int, bool> vals;

        int largestConsecutive = 0;

        if (nums.empty() )
            return 0;

        for (auto &i : nums)
            vals.insert({i, true});

        // for (int i = 0; i < nums.size(); i++) {
        //     if (vals.count(nums[i] - 1 > 0 )) {
        //         vals
        //     }
        // }

        for (int i = 0; i < nums.size(); i++) {
            if (vals[nums[i] == true]) {
                int j = 0;
                    while (vals[nums[i] + j])
                        j++;
                    largestConsecutive = j > largestConsecutive ? j : largestConsecutive;
            }
        }

        // int largestInt = *max_element(nums.begin(), nums.end());
        // int smallestInt = *min_element(nums.begin(), nums.end());
        //
        // for (int i = smallestInt; i != largestInt ; i++) {
        //     if (vals[i-1] == false && vals[i] == true) {
        //         int counter = 1;
        //         while (vals[i + counter] == true)
        //             counter++;
        //         largestConsecutive = counter > largestConsecutive ? counter : largestConsecutive;
        //     }
        //
        // }

        return largestConsecutive;

    }
};


int main() {

    vector<int> nums = {0};

    cout << Solution::longestConsecutive(nums) << endl;
}