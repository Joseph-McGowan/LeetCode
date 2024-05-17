//
// Created by joseph on 17/05/2024.
//
#include "vector"
#include "iostream"
#include "unordered_map"
#include "algorithm"

class Solution {
public:

    //initial solution
    static std::vector<int> topKFrequent(std::vector<int>& nums, int k) {

        std::unordered_map<int, int> elementFrequencies;

        for (auto & c : nums) {
            if (elementFrequencies.count(c))
                elementFrequencies[c]++;
            else {
                elementFrequencies.insert({c, 1});
            }

        }

        std::vector<int> frequencies;



        for(auto &k : elementFrequencies)
            frequencies.push_back(k.second);

        std::sort(frequencies.begin(), frequencies.end(), std::greater<>());

        std::vector<int> kFrequencies;
        int i = 0;

        while (k > 0) {
            for (auto &c: elementFrequencies) {
                std::vector<int>::iterator it;
                it = std::find(kFrequencies.begin(), kFrequencies.end(), c.first);
                if (c.second == frequencies[i] && (it == kFrequencies.end())) {
                    kFrequencies.push_back(c.first);
                    k--;
                    if (k == 0)
                        break;
                }


            }
            i++;
        }


        return kFrequencies;

    }
};


class ImprovedSolution {
public:
    static std::vector<int> topKFrequent(std::vector<int>& nums, int k) {

        std::unordered_map<int, int> elementFrequencies;

        for (int i = 0 ; i < nums.size() ; ++i) {
            elementFrequencies[nums[i]]++;
        }

        std::vector<std::vector<int>> freq(nums.size() +1 );
        for (auto it = elementFrequencies.begin(); it != elementFrequencies.end(); it++) {
            freq[it->second].push_back(it->first);
        }

        std::vector<int> results;

        for (int i = nums.size(); i >= 0; i--) {
            if (results.size() >= k)
                break;
            if (!freq[i].empty()) {
                results.insert(results.end(), freq[i].begin(), freq[i].end());
            }
        }

        return results;

        }
};

int main() {

    std::vector<int>nums = {4,1,-1,2,-1,2,3};

    std::vector<int>answer = Solution::topKFrequent(nums, 2);

    for (auto& i : answer)
        std::cout << i << std::endl;

}