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
        int n = nums.size();
        if (n == 0)return 0;
        unordered_set<int>s;

        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }

        int longest = 1;
        for(auto i : s)
        {
            int temp = i;

            if(s.find(i-1) == s.end()) //i-1 can be first element of sequence
            {
                int x = i;
                int cnt = 1;
                while(s.find(x+1)!=s.end())
                {
                    x = x+1;
                    cnt++;

                }
                longest = max(longest, cnt);
            }
            else //we found 1-1, curr ele cannot start a seq
                continue;
        }
        return longest;

    }
};


int main() {

    vector<int> nums = {0};

    cout << Solution::longestConsecutive(nums) << endl;
}