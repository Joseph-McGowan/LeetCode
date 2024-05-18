//
// Created by joseph on 18/05/2024.
//
#include <vector>
#include "algorithm"
#include "iostream"
#include "unordered_map"

class Solution {
public:
    static std::vector<int> productExceptSelf(std::vector<int>& nums) {

        int n = nums.size();
        //return array answer such that answer[i] = product of nums barring nums[i]

        std::vector<int> vals;

        int leftMultiplier = nums[0];

        vals.push_back(1);

        for (int i = 1; i < n ; ++i) {
            vals.push_back(leftMultiplier);
            leftMultiplier *= nums[i];

        }

        int rightMultiplier = nums[n-1];

        for (int i = n - 2; i >= 0 ; i--) {
            vals.at(i)*= rightMultiplier;
            rightMultiplier *= nums[i];
        }

        return vals;

//        std::vector<int> results;
//
//        for (auto & i: vals)
//            results.push_back(i);
//
//        return results;
    }
};

int main() {

    std::vector<int> result = {-1,1,0,-3,3};

    result = Solution::productExceptSelf(result);

    for (auto& i : result)
        std::cout << i << std::endl;


    return 0;
}