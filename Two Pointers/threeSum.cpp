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
        //two pointers, i & j point to array elements
        //cycle through all pairs of values; look for value that makes 0

        unordered_map<int, vector<int>> mappedVals;
        set<vector<int>> s;

        vector<vector<int>>indices;

        //int i = 0;
        //int j = 1;
        int a = 0;

        sort(nums.begin(), nums.end());

        // for (auto i : nums) {
        //     cout << i << endl;
        // }

        for(int i = 0; i < nums.size() - 1; i++) {
            //int indexI = nums[i];
            for (int j = 1; j < nums.size(); j++) {
                a = 0;
                //int indexJ = nums[j];
                int target = 0 - nums[j] - nums[i];
                while ( a < nums.size()- 1) {
                    if (a == i || a== j ) {
                        a++;
                        continue;
                    }
                    if (nums[a] == target ) {
                        //make sure val isn't duplicate
                        vector<int> solution = {nums[i], nums[j], nums[a]};
                            s.insert(solution);
                        }
                    a++;
                }
            }
        }

        for (auto i : s)
            indices.push_back(i);
        return indices;
    }

};

int main() {


    vector<int> index{-1,0,1,2,-1,-4};

    auto sol = Solution::threeSum(index);

    for (auto i : sol) {
        for (auto j : i )
            cout <<  j;
        cout << endl;
    }


    return 0;
}