//
// Created by joseph on 08/05/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        //hash set
        std::unordered_map<int, int> vals;

        for (int i = 0; i < nums.size(); ++i) {
            vals[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (vals.count(complement) && vals[complement] != i) {
                return {i, vals[complement]};
            }
        }

        }
};

int main(int argc, char** argv)
{
    std::vector<int> myVec = {3,3};
    auto vals =  Solution::twoSum(myVec, 6);

    return 1;
}



//~Will not work when complement = value (i.e 4+4 = 8)
//        for (int i = target; i > 0; --i) {
//            complement = target - i;
//            //int* It;
//            auto It = std::find(nums.begin(), nums.end(), complement);
//            if (*It == complement){
//                int ref = It - nums.begin();
//                auto test = nums.begin();
//                cout << *test << endl;
//                auto testEnd = nums.end() - 1;
//                cout << *testEnd << endl;
//                It = find(nums.begin(), nums.end(), i);
//                if (*It == i && It - nums.begin() != ref ) {
//                    int refIndexTwo = It - nums.begin();
//                    return vector<int>{ref, refIndexTwo};
//                }
//            }

