//
// Created by josep on 22/05/2024.
//

#include "vector"

#include "iostream"
using namespace std;


class Solution {
public:
    static vector<int> twoSum(vector<int>& numbers, int target) {

        int index1 = 0;
        int index2 = numbers.size() - 1;

        int indexSum = numbers[index1] + numbers[index2];

        while (indexSum != target  || index1 == index2) {
            if (indexSum > target ) {
                index2--;
            }
            else {
                index1++;
            }
            indexSum = numbers[index1] + numbers[index2];

        }

        vector<int> indices = {index1 + 1, index2 + 1};
        return indices;

    }
};

int main() {

    vector<int> ints = {1, 3, 4, 4};
    int target = 8;

    auto sol = Solution::twoSum(ints, target);

    for (auto i : sol)
        cout << i << endl;
}