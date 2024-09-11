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

        vector<int> results;
        stack<pair<int, int>> temps;
        vector<pair<int, int>> tempIndex;


        for (int i = 0; i < temperatures.size(); i++) {
            tempIndex.emplace_back(i, temperatures[i]);
            results.emplace_back(0);
        }

        int i = 1;

        int currentHighest = 0;

        if(temperatures.empty() == true)
            return {};
        temps.push({0, temperatures[0]});

        while(i < temperatures.size()) {
            if (temps.empty()) {
                temps.push({i, temperatures[i]});
                i++;
                continue;
            }
            while(temperatures[i] > temps.top().second ) {
                int gap = tempIndex[i].first - temps.top().first;
                results[temps.top().first] = gap;
                temps.pop();
                if (temps.empty())
                    break;
            }
            temps.push(pair(i, temperatures[i]));
            i++;
        }

        if(!temps.empty()) {
            while (!temps.empty()) {
                results[temps.top().first] = 0;
                temps.pop();
            }
        }
        return results;

    }
};



int main () {

    vector<int> temps = {30,38,30,36,35,40,28};

    auto sol = Solution::dailyTemperatures(temps);

    for (auto i : sol)
        cout << i << endl;

}