//
// Created by josep on 23/05/2024.
//


#include "vector"
#include "iostream"
#include "algorithm"
#include "unordered_map"
#include <set>

using namespace std;

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>>indices;

        sort(nums.begin(), nums.end());

        int lp = 0;
        int rp = nums.size()-1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[0] > 0)
                break;
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            lp = i+1;

            while (lp < rp) {
                int threeSum = nums[lp] + nums[rp] + nums[i];
                if (threeSum > 0 )
                    rp--;
                if (threeSum < 0)
                    lp++;
                if (threeSum ==0) {
                    auto index = {nums[lp] + nums[rp] + nums[i]};
                    indices.emplace_back(index);
                    lp++;
                    while (nums[lp] == nums[lp-1] && lp < rp)
                        lp++;
                }

            }
        }

        return indices;


    }

};

int main() {


    vector<int> index{-3,1,  2,-2};

    auto sol = Solution::threeSum(index);

    for (auto i : sol) {
        for (auto j : i )
            cout <<  j;
        cout << endl;
    }


    return 0;
}