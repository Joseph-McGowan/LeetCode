//
// Created by joseph on 15/07/2024.
//
#include <iostream>
#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    static vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> solution;
        stack<pair<int,int>> vals;
        //pair index, temp

        for (auto i : temperatures)
            solution.push_back(0);

        //vals.push(temperatures[0]);

        for (int i = 1; i < temperatures.size(); i++) {
            for (int j = 0; j < i; ++j) {
                solution[j]++;
            }
            if (vals.top() > temperatures[i])
                vals.pop();
            vals.push(temperatures[i]);

        }



        return solution;

    }
};



int main () {

    vector<int> temps = {30,38,30,36,35,40,28};

    auto sol = Solution::dailyTemperatures(temps);

    for (auto i : sol)
        cout << i << endl;

}